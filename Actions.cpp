#include "Actions.h"
#include "KeyHandler.h"

float Actions::CustomGameSpeed = 0.4f;
bool Actions::bInfiniteStaminaEnabled = false;
bool Actions::bMassReduced = false;
float Actions::OriginalPelvisMass = 0.0f;
float Actions::OriginalRWeaponMass = 0.0f;
float Actions::OriginalLWeaponMass = 0.0f;
float Actions::OriginalSpine05Mass = 0.0f;
float Actions::OriginalAimSwingSpeed = 0.0f;
HMODULE Actions::Module = nullptr;

std::unordered_map<Actions::ActionID, Actions::ActionInfo> Actions::actions = {
    { SPAWN_ITEM,               { "Spawn Item", SpawnItem } },
    { SET_PLAYER_SPEED,         { "Set Player Speed", SetPlayerSpeed } },
    { TOGGLE_MASS,              { "Toggle Mass", ToggleMass } },
    { TOGGLE_POST_PROCESS,      { "Toggle Post Process", TogglePostProcess } },
    { TOGGLE_INFINITE_STAMINA,  { "Toggle Infinite Stamina", ToggleInfiniteStamina } },
    { SAVE_LOADOUT,             { "Save Loadout", SaveLoadout } },
    { TOGGLE_CUSTOM_GAME_SPEED, { "Toggle Custom Game Speed", ToggleCustomGameSpeed } },
    { SET_CUSTOM_GAME_SPEED,    { "Set Custom Game Speed", SetCustomGameSpeed } },
    { UNLOAD_DLL,               { "Unload DLL", UnloadDLL } },
    { CHANGE_KEYBIND,           { "Change Keybind", ShowKeyReassignmentMenu } }
};

void Actions::Initialize(HMODULE& Module)
{
    Actions::Module = Module;
}

void Actions::UnloadDLL()
{
    HWND consoleWindow = GetConsoleWindow();
    FreeConsole();
    PostMessage(consoleWindow, WM_CLOSE, 0, 0);
    FreeLibraryAndExitThread(Actions::Module, 0);
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

void Actions::SpawnItem()
{
    ItemSpawner::AskForItemAndSpawn(GameInstances::GetWorld(), GameInstances::GetPawn());
}

void Actions::SetPlayerSpeed()
{
    SDK::AWillie_BP_C* CurrentPawn = GameInstances::GetPawn();
    CurrentPawn->CharacterMovement->MaxWalkSpeed = 9999999;
    std::cout << "Enter new speed: ";
    std::cin >> CurrentPawn->Running_Speed_Rate;
    CurrentPawn->CharacterMovement->MaxAcceleration = 9999999;
    CurrentPawn->CharacterMovement->bCheatFlying = 1;
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
        CurrentPawn->Aim_Swing_Speed = 999.0f;
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
}

void Actions::ToggleInfiniteStamina()
{
    bInfiniteStaminaEnabled = !bInfiniteStaminaEnabled;
}

void Actions::SaveLoadout()
{
    GameInstances::GetPawn()->Save_Loadout();
}

void Actions::ToggleCustomGameSpeed()
{
    SDK::AWorldSettings* WorldSettings = GameInstances::GetWorldSettings();
    WorldSettings->TimeDilation == 1.0f ? WorldSettings->TimeDilation = CustomGameSpeed : WorldSettings->TimeDilation = 1.0f;
    Sleep(200);
}

void Actions::SetCustomGameSpeed()
{
    std::cout << "Enter new custom game speed (" << CustomGameSpeed << " currently): ";
    std::cin >> CustomGameSpeed;
}
