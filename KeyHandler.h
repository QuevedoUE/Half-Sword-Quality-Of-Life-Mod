#pragma once
#undef max

#include "Actions.h"
#include <map>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <filesystem>
#include <iostream>
#include <limits>
#include <set>

using namespace std;

class KeyHandler
{
public:
    struct KeyBinding {
        Actions::ActionID actionId;
        int key;
    };

    struct KeyCombination {
        Actions::ActionID actionId;
        vector<int> keys;
        function<void()> action;
    };

    using KeyHandlerFunc = function<void()>;

    KeyHandler();

    static KeyHandler* GetInstance();
    void RegisterKey(const KeyBinding& binding);
    void RegisterKeyCombination(const KeyCombination& combination);
    void HandleKeys();
    void LoadKeyBindings();
    void SaveKeyBindings();
    void ReassignKey(KeyBinding& binding);
    void ShowKeyReassignmentMenu();
    vector<pair<int, Actions::ActionID>> GetKeyBindings();
    string GetKeyName(int vkCode);
    void UpdateKeyCombinations(int oldKey, int newKey);

private:
    static KeyHandler* Instance;
    static map<int, vector<KeyHandlerFunc>> Keys;
    static vector<KeyBinding> keyBindings;
    static vector<KeyCombination> keyCombinations;
};