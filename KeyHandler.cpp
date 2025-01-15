#include "KeyHandler.h"

#undef max

KeyHandler* KeyHandler::Instance = nullptr;
map<int, vector<KeyHandler::KeyHandlerFunc>> KeyHandler::Keys;
vector<KeyHandler::KeyBinding> KeyHandler::keyBindings;
vector<KeyHandler::KeyCombination> KeyHandler::keyCombinations;

KeyHandler* KeyHandler::GetInstance()
{
    if (!Instance)
        Instance = new KeyHandler();
    return Instance;
}

void KeyHandler::RegisterKey(const KeyBinding& binding)
{
    function<void()> action = Actions::GetActionById(binding.actionId);
    Keys[binding.key].push_back(action);
    keyBindings.push_back(binding);
}

void KeyHandler::RegisterKeyCombination(const KeyCombination& combination)
{
    function<void()> action = Actions::GetActionById(combination.actionId);
    keyCombinations.push_back(combination);
    keyCombinations.back().action = action;
}

void KeyHandler::HandleKeys()
{
    static set<int> pressedKeys;
    for (const auto& combination : keyCombinations)
    {
        bool allKeysPressed = true;
        for (int key : combination.keys)
        {
            if (!(GetAsyncKeyState(key) & 0x8000))
            {
                allKeysPressed = false;
                break;
            }
        }
        if (allKeysPressed)
        {
            combination.action();
            return;
        }
    }

    for (const auto& [key, handlers] : Keys)
    {
        if (GetAsyncKeyState(key) & 0x8000)
        {
            if (pressedKeys.find(key) == pressedKeys.end())
            {
                for (const auto& handler : handlers)
                {
                    handler();
                }
                pressedKeys.insert(key);
            }
        }
        else
        {
            pressedKeys.erase(key);
        }
    }
}

void KeyHandler::LoadKeyBindings()
{
    filesystem::create_directories("HS-QOL-Mod");
    ifstream file("HS-QOL-Mod/keybindings.txt");
    if (!file.is_open())
        return;

    keyBindings.clear();
    Keys.clear();
    keyCombinations.clear();

    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        string type;
        iss >> type;

        if (type == "key")
        {
            int key;
            int actionId;
            iss >> key >> actionId;
            KeyBinding binding = { static_cast<Actions::ActionID>(actionId), key };
            RegisterKey(binding);
        }
        else if (type == "combination")
        {
            int actionId;
            iss >> actionId;
            vector<int> keys;
            int key;
            while (iss >> key)
            {
                keys.push_back(key);
            }
            KeyCombination combination = { static_cast<Actions::ActionID>(actionId), keys };
            RegisterKeyCombination(combination);
        }
    }

    file.close();
}

void KeyHandler::SaveKeyBindings()
{
    ofstream file("HS-QOL-Mod/keybindings.txt");
    if (!file.is_open())
        return;

    for (const auto& binding : keyBindings)
    {
        file << "key " << binding.key << " " << static_cast<int>(binding.actionId) << endl;
    }

    for (const auto& combination : keyCombinations)
    {
        file << "combination " << static_cast<int>(combination.actionId);
        for (int key : combination.keys)
        {
            file << " " << key;
        }
        file << endl;
    }

    file.close();
}

void KeyHandler::ReassignKey(KeyBinding& binding)
{
    cout << "Press the new key for " << Actions::GetActionName(binding.actionId);
    function<void()> action = Actions::GetActionById(binding.actionId);

    while (true)
    {
        bool anyKeyPressed = false;
        for (int vkCode = 8; vkCode <= 255; ++vkCode)
        {
            if (GetAsyncKeyState(vkCode) & 0x8000)
            {
                anyKeyPressed = true;
                break;
            }
        }
        if (!anyKeyPressed)
        {
            break;
        }
        Sleep(1000 / 30);
    }

    bool keyCaptured = false;
    while (!keyCaptured)
    {
        for (int vkCode = 8; vkCode <= 255; ++vkCode)
        {
            if (GetAsyncKeyState(vkCode) & 0x8000)
            {
                if (vkCode == VK_RETURN) continue;

                while (GetAsyncKeyState(vkCode) & 0x8000)
                {
                    Sleep(1000 / 30);
                }

                auto& handlers = Keys[binding.key];
                handlers.erase(remove_if(handlers.begin(), handlers.end(),
                    [&binding, &action](const KeyHandlerFunc& func) {
                        return func.target<void()>() == action.target<void()>();
                    }), handlers.end());

                if (handlers.empty())
                {
                    Keys.erase(binding.key);
                }

                int oldKey = binding.key;
                binding.key = vkCode;
                Keys[binding.key].push_back(action);

                UpdateKeyCombinations(oldKey, vkCode);

                cout << "\n" << Actions::GetActionName(binding.actionId) << " successfully reassigned to " << GetKeyName(vkCode) << endl;
                SaveKeyBindings();
                keyCaptured = true;
                break;
            }
        }
        Sleep(1000 / 30);
    }
}

void KeyHandler::ShowKeyReassignmentMenu()
{
    cout << "\nKey Reassign Menu:\n";
    for (size_t i = 0; i < keyBindings.size(); ++i)
    {
        cout << i + 1 << ". " << Actions::GetActionName(keyBindings[i].actionId) << " \n";
    }
    cout << "\nSelect an option to reassign: ";

    int option;
    while (!(cin >> option) || option <= 0 || option > keyBindings.size())
    {
        cout << "Invalid option. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Select an option: ";
    }

    ReassignKey(keyBindings[option - 1]);
}

vector<pair<int, Actions::ActionID>> KeyHandler::GetKeyBindings()
{
    vector<pair<int, Actions::ActionID>> bindings;
    for (const auto& binding : keyBindings)
    {
        bindings.emplace_back(binding.key, binding.actionId);
    }
    return bindings;
}

string KeyHandler::GetKeyName(int vkCode)
{
    static const unordered_map<int, string> specialKeys = {
        {VK_HOME, "Home"}, {VK_END, "End"}, {VK_INSERT, "Insert"}, {VK_DELETE, "Delete"},
        {VK_PRIOR, "Page Up"}, {VK_NEXT, "Page Down"}, {VK_UP, "Up Arrow"}, {VK_DOWN, "Down Arrow"},
        {VK_LEFT, "Left Arrow"}, {VK_RIGHT, "Right Arrow"}, {VK_SPACE, "Space"}, {VK_RETURN, "Enter"},
        {VK_TAB, "Tab"}, {VK_ESCAPE, "Escape"}, {VK_BACK, "Backspace"}, {VK_F1, "F1"}, {VK_F2, "F2"},
        {VK_F3, "F3"}, {VK_F4, "F4"}, {VK_F5, "F5"}, {VK_F6, "F6"}, {VK_F7, "F7"}, {VK_F8, "F8"},
        {VK_F9, "F9"}, {VK_F10, "F10"}, {VK_F11, "F11"}, {VK_F12, "F12"}
    };

    auto it = specialKeys.find(vkCode);
    if (it != specialKeys.end())
    {
        return it->second;
    }

    UINT scanCode = MapVirtualKey(vkCode, MAPVK_VK_TO_VSC);
    char keyName[128];
    if (GetKeyNameTextA(scanCode << 16, keyName, sizeof(keyName)) > 0)
    {
        return string(keyName);
    }
    return "Unknown Key";
}

void KeyHandler::UpdateKeyCombinations(int oldKey, int newKey)
{
    for (auto& combination : keyCombinations)
    {
        for (auto& key : combination.keys)
        {
            if (key == oldKey)
                key = newKey;
        }
    }
}

KeyHandler::KeyHandler()
{
    RegisterKey({ Actions::SPAWN_ITEM, VK_F1 });
    RegisterKey({ Actions::SET_PLAYER_SPEED, VK_F3 });
    RegisterKey({ Actions::TOGGLE_MASS, VK_F4 });
    RegisterKey({ Actions::TOGGLE_POST_PROCESS, VK_F5 });
    RegisterKey({ Actions::TOGGLE_INFINITE_STAMINA, 0x49 }); // F3
    RegisterKey({ Actions::SAVE_LOADOUT, 0x54 }); // T
    RegisterKey({ Actions::SETSLOWMO, 0x5A }); // Z
    RegisterKey({ Actions::UNLOAD_DLL, VK_END });
    RegisterKey({ Actions::CHANGE_KEYBIND, VK_HOME });

    RegisterKeyCombination({ Actions::SETSLOWMO, {VK_CONTROL, 0x5A} }); // Ctrl + Z
}