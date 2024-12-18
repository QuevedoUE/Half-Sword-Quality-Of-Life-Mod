#include <Windows.h>
#include "pch.h"
#include "ItemSpawner.h"
#include <thread>

static bool IsMassReduced = false;
static float OriginalPelvisMass = -1.0f;
static float OriginalRWeaponMass = -1.0f;
static float OriginalLWeaponMass = -1.0f;
static float OriginalAimSwingSpeed = -1.0f;
static float OriginalSpine05Mass = -1.0f;

// Last Position OF The Mouse
POINT lastMousePosition = { 0, 0 };

static bool IsMouseMoving()
{
    POINT currentMousePosition;
    if (GetCursorPos(&currentMousePosition))
    {
        if (currentMousePosition.x != lastMousePosition.x || currentMousePosition.y != lastMousePosition.y)
        {
            lastMousePosition = currentMousePosition;
            return true;
        }
    }
    return false;
}

static DWORD MainThread(HMODULE Module)
{
    /* Code to open a console window */
    AllocConsole();
    FILE* Dummy;
    freopen_s(&Dummy, "CONOUT$", "w", stdout);
    freopen_s(&Dummy, "CONIN$", "r", stdin);

    /* Functions returning "static" instances */
    static ItemSpawner ItemSpawner;
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    SDK::UWorld* World = SDK::UWorld::GetWorld();
    SDK::APlayerController* PlayerController = World->OwningGameInstance->LocalPlayers[0]->PlayerController;
    SDK::AWorldSettings* WorldSettings = World->K2_GetWorldSettings();

    SDK::FTransform SpawnOriginTransform{};
    // Asignar ubicaci�n directamente
    SpawnOriginTransform.Translation = SDK::FVector(0.0f, 0.0f, 0.0f);
    // Asignar rotaci�n directamente (usa una rotaci�n por defecto, como una identidad)
    SpawnOriginTransform.Rotation = SDK::FQuat(180.0f, 0.0f, 0.0f, 1.0f); // Quaternion identidad
    // Asignar escala directamente
    SpawnOriginTransform.Scale3D = SDK::FVector(1.0f, 1.0f, 1.0f); // Escala unitaria
    class SDK::AWillie_BP_C* CurrentPawn = static_cast<SDK::AWillie_BP_C*>(PlayerController->Pawn);
    SDK::FVector MenuCameraBetterLoc(-100, 920, 100);
    CurrentPawn->K2_SetActorLocation(MenuCameraBetterLoc, false, nullptr, true);

    SDK::AActor* SpawnedActor = ItemSpawner.SpawnActorFromClass(World, SDK::APostProcessVolume::StaticClass(), SpawnOriginTransform, nullptr);
    SDK::APostProcessVolume* PostProcessCreatedVolume = static_cast<SDK::APostProcessVolume*>(SpawnedActor);

    if (SpawnedActor)
    {
        auto& Settings = PostProcessCreatedVolume->Settings;

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
               )"
            << "\n\nPost Process Created and Settings Applied!\n\n"
            << "Keybinds:\n"
            << "All function keys work with it's number on the numpad\n\n"
            << "F1: Spawn custom item\n"
            << "F3: Set custom player speed\n"
            << "F4: Toggle player mass mod\n"
            << "F5: Toggle postprocessing effects\n"
            << "Z: Toggle slow motion\n"
            << "G: Save current loadout\n"
            << "END: Unload DLL\n" << std::endl;
    }

    while (true)
    {
        class SDK::AWillie_BP_C* CurrentPawn = static_cast<SDK::AWillie_BP_C*>(PlayerController->Pawn);

        if ((GetAsyncKeyState(VK_F1) & 1) || (GetAsyncKeyState(VK_NUMPAD1) & 1))
            ItemSpawner.AskForItemAndSpawn();

        if ((GetAsyncKeyState(VK_F5) & 1) || (GetAsyncKeyState(VK_NUMPAD5) & 1))
            PostProcessCreatedVolume->bUnbound = ~PostProcessCreatedVolume->bUnbound;

        if (IsMouseMoving())
            CurrentPawn->Stamina = 100;

        if (GetAsyncKeyState(71) & 1) // G
            CurrentPawn->Save_Loadout();

        if (GetAsyncKeyState(90) & 1) // Z
        {
            WorldSettings->TimeDilation == 1.0f ? WorldSettings->TimeDilation = 0.4f : WorldSettings->TimeDilation = 1.0f;
            Sleep(200);
        }

        if ((GetAsyncKeyState(VK_F3) & 1) || (GetAsyncKeyState(VK_NUMPAD3) & 1))
        {
            std::cout << "Enter new speed: ";
            std::cin >> CurrentPawn->Running_Speed_Rate;
            CurrentPawn->CharacterMovement->MaxAcceleration = 9999999;
            CurrentPawn->CharacterMovement->bCheatFlying = 1;
        }

       /* if (GetAsyncKeyState(84) & 1) { 

        }
       */

        if ((GetAsyncKeyState(VK_F4) & 1) || (GetAsyncKeyState(VK_NUMPAD4) & 1))
        {
            if (!IsMassReduced) {
                OriginalPelvisMass = CurrentPawn->Default_Pelvis_Mass;
                OriginalRWeaponMass = CurrentPawn->R_Weapon_Mass;
                OriginalLWeaponMass = CurrentPawn->L_Weapon_Mass;
                OriginalAimSwingSpeed = static_cast<float>(CurrentPawn->Aim_Swing_Speed);
                OriginalSpine05Mass = CurrentPawn->Default_Spine_05_Mass;

                CurrentPawn->Default_Pelvis_Mass = 0;
                CurrentPawn->R_Weapon_Mass = 0;
                CurrentPawn->L_Weapon_Mass = 0;
                CurrentPawn->Aim_Swing_Speed = 999.0;
                CurrentPawn->Default_Spine_05_Mass = 0;

                IsMassReduced = true;
            }
            else {
                CurrentPawn->Default_Pelvis_Mass = OriginalPelvisMass;
                CurrentPawn->R_Weapon_Mass = OriginalRWeaponMass;
                CurrentPawn->L_Weapon_Mass = OriginalLWeaponMass;
                CurrentPawn->Aim_Swing_Speed = OriginalAimSwingSpeed;
                CurrentPawn->Default_Spine_05_Mass = OriginalSpine05Mass;

                IsMassReduced = false;
            }
        }

        if (GetAsyncKeyState(VK_END) & 1)
        {
            std::cout << "DLL unloaded. You can now close this window." << std::endl;
            FreeConsole();
            FreeLibraryAndExitThread(Module, 0);
        }

        Sleep(100);
    }
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, 0);
        break;
    }

    return TRUE;
}
