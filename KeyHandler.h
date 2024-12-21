#pragma once
#undef max

#include "Actions.h"
#include "GameInstances.h"
#include <map>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <filesystem>
#include <iostream>
#include <limits>

class KeyHandler
{
public:
    struct KeyBinding {
        Actions::ActionID actionId;
        int key;
    };

    struct KeyCombination {
        Actions::ActionID actionId;
        std::vector<int> keys;
        std::function<void()> action;
    };

    using KeyHandlerFunc = std::function<void()>;

    KeyHandler();

    static KeyHandler* GetInstance();
    void RegisterKey(const KeyBinding& binding);
    void RegisterKeyCombination(const KeyCombination& combination);
    void HandleKeys();
    void LoadKeyBindings();
    void SaveKeyBindings();
    void ReassignKey(KeyBinding& binding);
    void ShowKeyReassignmentMenu();
    std::vector<std::pair<int, Actions::ActionID>> GetKeyBindings();
    std::string GetKeyName(int vkCode);
    void UpdateKeyCombinations(int oldKey, int newKey);

private:
    static KeyHandler* Instance;
    static std::map<int, std::vector<KeyHandlerFunc>> Keys;
    static std::vector<KeyBinding> keyBindings;
    static std::vector<KeyCombination> keyCombinations;
};