#include "Actions.h"
#include "KeyHandler.h"
#include "SDK.hpp"
#include <fstream>
#include <filesystem>
#include <cstdlib>

float Actions::CustomGameSpeed = 0.4f;
bool Actions::bInfiniteStaminaEnabled = false;
bool Actions::bMassReduced = false;
float Actions::OriginalPelvisMass = 0.0f;
float Actions::OriginalRWeaponMass = 0.0f;
float Actions::OriginalLWeaponMass = 0.0f;
float Actions::OriginalSpine05Mass = 0.0f;
float Actions::OriginalAimSwingSpeed = 0.0f;

namespace fs = std::filesystem;


std::unordered_map<Actions::ActionID, Actions::ActionInfo> Actions::actions = {
    { SPAWN_ITEM,               { "Spawn Item", SpawnItem } },
    { SET_PLAYER_SPEED,         { "Set Player Speed", SetPlayerSpeed } },
    { TOGGLE_MASS,              { "Toggle Reduced Mass", ToggleMass } },
    { TOGGLE_POST_PROCESS,      { "Toggle Post Process Effects", TogglePostProcess } },
    { TOGGLE_INFINITE_STAMINA,  { "Toggle Infinite Stamina", ToggleInfiniteStamina } },
    { SAVE_LOADOUT,             { "Save Loadout", SaveLoadout } },
    { SETSLOWMO,                { "Slow Motion", SetSlowMo } },
    { SET_CUSTOM_GAME_SPEED,    { "Set Custom Game Speed", SetCustomGameSpeed } },
    { UNLOAD_DLL,               { "Unload DLL", UnloadDLL } },
    { CHANGE_KEYBIND,           { "Change Keybindings", ShowKeyReassignmentMenu } },
};

void Actions::UnloadDLL()
{
    MH_DisableHook(MH_ALL_HOOKS);
    MH_RemoveHook(MH_ALL_HOOKS);
    MH_Uninitialize();
    HWND consoleWindow = GetConsoleWindow();
    FreeConsole();
    PostMessage(consoleWindow, WM_CLOSE, 0, 0);
    FreeLibraryAndExitThread(GetModuleHandleW(0), 0);
}

std::function<void()> Actions::GetActionById(ActionID id)
{
    auto it = actions.find(id);
    if (it != actions.end())
    {
        return it->second.action;
    }
    return nullptr;
}

std::string Actions::GetActionName(ActionID id)
{
    auto it = actions.find(id);
    if (it != actions.end())
    {
        return it->second.name;
    }
    return "Unknown Action";
}

void Actions::ShowKeyReassignmentMenu()
{
    KeyHandler::GetInstance()->ShowKeyReassignmentMenu();
}

void Actions::Saveloadoutpreset() {
    string sourcePath;
    char* localAppData = nullptr;
    size_t requiredSize = 0;
    SDK::AWillie_BP_C* CurrentPawn = GameInstances::GetPawn();

    
    if (GameInstances::GetPlayerController()->bShowMouseCursor) {
        std::cout << "You must be in-game to save your presets." << std::endl;
        return;
    }

   
    if (_dupenv_s(&localAppData, &requiredSize, "LOCALAPPDATA") == 0 && localAppData != nullptr) {
        sourcePath = string(localAppData) + R"(\VersionTest54\Saved\SaveGames\SG Player Equipment.sav)";
        free(localAppData);
    }
    else {
        cerr << "APPDATA NOT FOUND. Error retrieving LOCALAPPDATA." << endl;
        return;
    }

    
    if (!fs::exists(sourcePath)) {
        cerr << "The file SG Player Equipment.sav does not exist or is corrupted: " << sourcePath << endl;
        return;
    }

    
    string targetFolder = "C:/HS-QOL";
    if (!fs::exists(targetFolder)) {
        if (!fs::create_directories(targetFolder)) {
            cerr << "Failed to create target folder: " << targetFolder << endl;
            return;
        }
    }

    
    string newName;
    cout << "Enter preset name (do not include .sav): ";
    cin >> newName;

    
    if (newName.find_first_of("\\/:*?\"<>|") != string::npos) {
        cerr << "Preset name contains invalid characters. Please try again." << endl;
        return;
    }

    string targetPath = targetFolder + "/" + newName + ".sav";

    
    try {
        fs::copy(sourcePath, targetPath, fs::copy_options::overwrite_existing);
        cout << "Preset saved as: " << newName << endl;
        if (CurrentPawn) {
            CurrentPawn->Save_Loadout();
        }
        else {
            cerr << "Failed to save loadout: CurrentPawn is null." << endl;
        }
    }
    catch (const fs::filesystem_error& e) {
        cerr << "Failed to save preset: " << e.what() << endl;
    }
}


void Actions::LoadLoadoutPreset() {
    string targetPathPlayer;
    string targetPathGiveUp;
    char* localAppData = nullptr;
    size_t requiredSize = 0;

    if (_dupenv_s(&localAppData, &requiredSize, "LOCALAPPDATA") == 0 && localAppData != nullptr) {
        // Defines APPDATA
        string appDataBase = string(localAppData) + R"(\VersionTest54\Saved\SaveGames\)";
        targetPathPlayer = appDataBase + "SG Player Equipment.sav";
        targetPathGiveUp = appDataBase + "Save_GiveUp.sav";
        free(localAppData);
    }
    else {
        cerr << "APPDATA NOT FOUND. Error retrieving LOCALAPPDATA." << endl;
        return;
    }

    string presetsFolder = "C:/HS-QOL";
    if (!fs::exists(presetsFolder)) {
        cerr << "Preset folder not found. Create it by saving a preset first." << endl;
        return;
    }

    vector<string> availablePresets;
    for (const auto& entry : fs::directory_iterator(presetsFolder)) {
        if (entry.is_regular_file() && entry.path().extension() == ".sav") {
            availablePresets.push_back(entry.path().stem().string());
        }
    }

    if (availablePresets.empty()) {
        cerr << "No presets available in the folder." << endl;
        return;
    }

    cout << "Available presets:" << endl;
    for (const auto& preset : availablePresets) {
        cout << "- " << preset << endl;
    }

    string presetName;
    cout << "Enter preset name to load (without .sav): ";
    cin >> presetName;

    string sourcePath = presetsFolder + "/" + presetName + ".sav";

    if (!fs::exists(sourcePath)) {
        cerr << "The selected preset does not exist: " << presetName << endl;
        return;
    }

    try {
        // Copia el archivo al destino SG Player Equipment.sav
        fs::copy(sourcePath, targetPathPlayer, fs::copy_options::overwrite_existing);
        cout << "Preset loaded for SG Player Equipment: " << presetName << endl;

        // Copia el archivo al destino Save_GiveUp.sav
        fs::copy(sourcePath, targetPathGiveUp, fs::copy_options::overwrite_existing);
        cout << "Preset loaded for Save_GiveUp: " << presetName << endl;

        // Forzar la recarga en el juego
        SDK::AWillie_BP_C* CurrentPawn = GameInstances::GetPawn();
        if (CurrentPawn) {
            CurrentPawn->Load_Save();              
            CurrentPawn->Add_Startup_Weapons();
            CurrentPawn->Load_Save_Give_Up();
            cout << "Loadout successfully updated in-game." << endl;
        }
        else {
            cerr << "Failed to load preset: CurrentPawn is null." << endl;
        }
    }
    catch (const fs::filesystem_error& e) {
        cerr << "Failed to load preset: " << e.what() << endl;
    }
}




void Actions::SpawnItem()
{
    ItemSpawner::AskForItemAndSpawn(GameInstances::GetWorld(), GameInstances::GetPawn());
}

void Actions::SetPlayerSpeed()
{
    SDK::AWillie_BP_C* CurrentPawn = GameInstances::GetPawn();
    CurrentPawn->CharacterMovement->MaxWalkSpeed = 9999999;
    std::cout << "Enter new speed:  (" << CurrentPawn->Running_Speed_Rate << " currently): ";
    std::cin >> CurrentPawn->Running_Speed_Rate;
    CurrentPawn->CharacterMovement->MaxAcceleration = 9999999;
    CurrentPawn->CharacterMovement->bCheatFlying = 1;
    std::cout << "New Speed: " << CurrentPawn->Running_Speed_Rate << std::endl;
}

void Actions::ToggleMass()
{
    SDK::AWillie_BP_C* CurrentPawn = GameInstances::GetPawn();
    if (!bMassReduced) {
        OriginalPelvisMass = CurrentPawn->Default_Pelvis_Mass;
        OriginalRWeaponMass = CurrentPawn->R_Weapon_Mass;
        OriginalLWeaponMass = CurrentPawn->L_Weapon_Mass;
        OriginalAimSwingSpeed = static_cast<float>(CurrentPawn->Aim_Swing_Speed);
        OriginalSpine05Mass = CurrentPawn->Default_Spine_05_Mass;

        CurrentPawn->Default_Pelvis_Mass = 0;
        CurrentPawn->R_Weapon_Mass = 0;
        CurrentPawn->L_Weapon_Mass = 0;
        CurrentPawn->Aim_Swing_Speed = 99999.0f;
        CurrentPawn->Default_Spine_05_Mass = 0;

        bMassReduced = true;
    }
    else {
        CurrentPawn->Default_Pelvis_Mass = OriginalPelvisMass;
        CurrentPawn->R_Weapon_Mass = OriginalRWeaponMass;
        CurrentPawn->L_Weapon_Mass = OriginalLWeaponMass;
        CurrentPawn->Aim_Swing_Speed = OriginalAimSwingSpeed;
        CurrentPawn->Default_Spine_05_Mass = OriginalSpine05Mass;

        bMassReduced = false;
    }
}

void Actions::TogglePostProcess()
{
    SDK::APostProcessVolume* PPVolume = GameInstances::GetPostProcessVolume();
    PPVolume->bUnbound = ~PPVolume->bUnbound;
    std::cout << "Post process is: " << (PPVolume->bUnbound ? "enabled" : "disabled") << std::endl;
}

void Actions::ToggleInfiniteStamina()
{
    bInfiniteStaminaEnabled = !bInfiniteStaminaEnabled;
    std::cout << "Infinite stamina is now:  " << (bInfiniteStaminaEnabled ? "enabled" : "disabled") << std::endl;
}

void Actions::SaveLoadout()
{
    if (GameInstances::GetPlayerController()->bShowMouseCursor) {
        std::cout << "You must be in-game to save your loadout" << std::endl;
        return;
    }
    GameInstances::GetPawn()->Save_Loadout();
    std::cout << "Loadout saved successfully" << std::endl;
}

void Actions::SetCustomGameSpeed() {

    SetSlowMo();
}

void Actions::SetSlowMo()
{
    SDK::AWorldSettings* WorldSettings = GameInstances::GetWorldSettings();
    WorldSettings->TimeDilation = (WorldSettings->TimeDilation == 1.0f ? WorldSettings->TimeDilation = 0.4f :
    WorldSettings->TimeDilation == 0.4f or WorldSettings->TimeDilation == 0.0f ? WorldSettings->TimeDilation = 1.0f : 0);
    Sleep(200);
}
    