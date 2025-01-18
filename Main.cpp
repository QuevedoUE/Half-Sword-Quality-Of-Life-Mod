#include "pch.h"
#include "KeyHandler.h"
#include "MinHook.h"

typedef void(__thiscall* tProcessEvent)(SDK::UObject*, SDK::UFunction*, void*);
tProcessEvent OriginalProcessEvent = nullptr;

static void __fastcall HookedProcessEvent(SDK::UObject* Object, SDK::UFunction* Function, void* Params) {
    // We gotta find a better way to handle this
    if (Function->GetName() == "Camera Shake Timeline__UpdateFunc" && Actions::bInfiniteStaminaEnabled)
        GameInstances::GetPawn()->Stamina = 100;
    OriginalProcessEvent(Object, Function, Params);
}

void ClearConsole() {
    // Last Row
    std::cout << "\033[1A\033[2K"; 
    std::cout << "\033[1J"; 
}
static void HSMessage() {
    ClearConsole();
    std::cout << R"(
         __  __      ______   _____                        __          
        / / / /___ _/ / __/  / ___/      ______  _________/ /          
       / /_/ / __ `/ / /_    \__ \ | /| / / __ \/ ___/ __  /           
      / __  / /_/ / / __/   ___/ / |/ |/ / /_/ / /  / /_/ /            
     /_/_/_/\__,_/_/_/    _/____/|__/|__/\____/_/___\__,_/    _ ____   
       / __ \__  ______ _/ (_) /___  __   ____  / __/  / /   (_) __/__ 
      / / / / / / / __ `/ / / __/ / / /  / __ \/ /_   / /   / / /_/ _ \
     / /_/ / /_/ / /_/ / / / /_/ /_/ /  / /_/ / __/  / /___/ / __/  __/
     \___\_\__,_/\__,_/_/_/\__/\__, /   \____/_/    /_____/_/_/  \___/ 
                              /____/
    
                        By Froid & The Ghost
                            !TO EVERYONE!
                          !2025 NEW EDITION!
                     --> 1.25 PRESETS & FIXES <--
                                                                            )";
    std::cout << R"(
Key bindings:

F1 -> Spawn Item
F2 -> Set Player Speed
F3 -> Toggle Infinite Stamina
F4 -> Toggle Reduced Mass
F5 -> Toggle Post Process Effects                
T  -> Save Loadout
Z  -> Slow Motion
F6 -> Save Preset
F8 -> Load Preset
HOME -> Unload DLL (DEBUGGIN PURPOSES !DONT TOUCH!) 
)";
std::cout << "\n";

}

static void InitializeHook() {
    if (MH_Initialize() != MH_OK) {
        std::cerr << "Error initializing MinHook" << std::endl;
        return;
    }

    SDK::UObject* pObject = SDK::UObject::GObjects->GetByIndex(0);
    if (!pObject) {
        std::cerr << "Could not get an instance of UObject." << std::endl;
        return;
    }

    uintptr_t* vtable = *reinterpret_cast<uintptr_t**>(pObject);
    uintptr_t ProcessEventAddress = vtable[SDK::Offsets::ProcessEventIdx];

    if (MH_CreateHook(reinterpret_cast<LPVOID>(ProcessEventAddress), reinterpret_cast<LPVOID>(&HookedProcessEvent), reinterpret_cast<LPVOID*>(&OriginalProcessEvent)) != MH_OK) {
        std::cerr << "Error creating hook for ProcessEvent" << std::endl;
        return;
    }

    if (MH_EnableHook(reinterpret_cast<LPVOID>(ProcessEventAddress)) != MH_OK) {
        std::cerr << "Error enabling hook for ProcessEvent" << std::endl;
        return;
    }

    std::cout << "Hooks initialized successfully!" << std::endl;
}

static DWORD MainThread(HMODULE Module)
{
    AllocConsole();
    FILE* Dummy;
    freopen_s(&Dummy, "CONIN$", "r", stdin);
    freopen_s(&Dummy, "CONOUT$", "w", stderr);
    freopen_s(&Dummy, "CONOUT$", "w", stdout);


    SDK::FTransform SpawnOriginTransform{};
    SpawnOriginTransform.Translation = SDK::FVector(0.0f, 0.0f, 0.0f);
    SpawnOriginTransform.Rotation = SDK::FQuat(180.0f, 0.0f, 0.0f, 1.0f);
    SpawnOriginTransform.Scale3D = SDK::FVector(1.0f, 1.0f, 1.0f);

    SDK::AActor* SpawnedActor = ItemSpawner::SpawnActorFromClass(GameInstances::GetWorld(), SDK::APostProcessVolume::StaticClass(), SpawnOriginTransform, nullptr);
    SDK::APostProcessVolume* PostProcessVolume = static_cast<SDK::APostProcessVolume*>(SpawnedActor);

    if (!PostProcessVolume) {
        std::cerr << "Failed to spawn PostProcessVolume!" << std::endl;
        return 1;
    }

    auto& Settings = PostProcessVolume->Settings;

    Settings.bOverride_ColorGradingIntensity = true;
    Settings.ColorGradingIntensity = 0.7f;
    Settings.bOverride_RayTracingGI = true;
    Settings.RayTracingTranslucencyMaxRoughness = 0.6f;
    Settings.bOverride_BloomIntensity = true;
    Settings.BloomIntensity = 2.5f;
    Settings.bOverride_BloomSizeScale = true;
    Settings.BloomSizeScale = 1.2f;
    Settings.bOverride_BloomThreshold = true;
    Settings.BloomThreshold = 1.0f;
    Settings.bOverride_MotionBlurAmount = true;
    Settings.MotionBlurAmount = 0.7f;
    Settings.bOverride_VignetteIntensity = true;
    Settings.VignetteIntensity = 0.45f;
    Settings.bOverride_ReflectionsType = true;
    Settings.ReflectionsType = SDK::EReflectionsType::RayTracing;
    Settings.bOverride_RayTracingReflectionsMaxRoughness = true;
    Settings.RayTracingAOIntensity = 0;
    Settings.bOverride_AutoExposureMethod = true;
    Settings.AutoExposureMethod = SDK::EAutoExposureMethod::AEM_Histogram;
    Settings.bOverride_AutoExposureBias = true;
    Settings.AutoExposureBias = 0.3f;
    Settings.bOverride_SceneFringeIntensity = true;
    Settings.SceneFringeIntensity = 1.0f;
    Settings.bOverride_FilmGrainIntensity = true;
    Settings.FilmGrainIntensity = 0.35f;
    Settings.bOverride_AmbientCubemapIntensity = true;
    Settings.AmbientCubemapIntensity = 0.5f;
    Settings.bOverride_AmbientCubemapTint = true;
    Settings.AmbientCubemapTint = SDK::FLinearColor(1.0f, 0.8f, 0.5f);
    Settings.bOverride_DepthOfFieldFocalDistance = true;
    Settings.DepthOfFieldFocalDistance = 250.0f;
    Settings.bOverride_DepthOfFieldFocalRegion = true;
    Settings.DepthOfFieldFocalRegion = 150.0f;
    Settings.bOverride_SceneColorTint = true;
    Settings.SceneColorTint = SDK::FLinearColor(240.0f / 255.0f, 180.0f / 255.0f, 120.0f / 255.0f);

    GameInstances::Initialize(PostProcessVolume);

    KeyHandler* keyHandler = KeyHandler::GetInstance();
    keyHandler->LoadKeyBindings();

    auto bindings = keyHandler->GetKeyBindings();

    SDK::AWillie_BP_C* CurrentPawn = GameInstances::GetPawn();
    CurrentPawn = static_cast<SDK::AWillie_BP_C*>(GameInstances::GetPawn());

    HSMessage();
    InitializeHook();

    while (true)
    {
        if (GetAsyncKeyState(VK_F6) & 1) // F6
        {
            Actions::Saveloadoutpreset();
            HSMessage();
        }

        if (GetAsyncKeyState(VK_F8) & 1) // F7
        {
            Actions::LoadLoadoutPreset();
            HSMessage();
        }

        if (GetAsyncKeyState(VK_F1) & 1) // F1
        {
            Actions::SpawnItem();
            HSMessage();
        };

        if (GetAsyncKeyState(VK_F2) & 1) // F2
        {
            Actions::SetPlayerSpeed();
            HSMessage();
        };
        if (GetAsyncKeyState(90) & 1) // Z
        {
            Actions::SetSlowMo();
            HSMessage();
        };
        if (GetAsyncKeyState(84) & 1) // T
        {
            Actions::SaveLoadout();
            HSMessage();
        };
        if (GetAsyncKeyState(VK_F5) & 1) // F5
        {
            Actions::TogglePostProcess();
        };
        if (GetAsyncKeyState(VK_F3) & 1) // F3
        {
            Actions::ToggleInfiniteStamina();
            HSMessage();
        };
        if (GetAsyncKeyState(VK_F4) & 1) // F4
        {
            Actions::ToggleMass();
            HSMessage();
        };

        if (GetAsyncKeyState(VK_HOME) & 1) // HOME
        {
            Actions::UnloadDLL();
        };

        Sleep(300); 
    }
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH)
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, 0);

    return TRUE;
}