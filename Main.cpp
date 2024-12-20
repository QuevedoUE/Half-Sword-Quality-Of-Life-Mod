#include "pch.h"
#include "KeyHandler.h"
#include "GameInstances.h"

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
    AllocConsole();
    FILE* Dummy;
    freopen_s(&Dummy, "CONOUT$", "w", stdout);
    freopen_s(&Dummy, "CONIN$", "r", stdin);

    SDK::FTransform SpawnOriginTransform{};
    SpawnOriginTransform.Translation = SDK::FVector(0.0f, 0.0f, 0.0f);
    SpawnOriginTransform.Rotation = SDK::FQuat(180.0f, 0.0f, 0.0f, 1.0f);
    SpawnOriginTransform.Scale3D = SDK::FVector(1.0f, 1.0f, 1.0f);

    SDK::AActor* SpawnedActor = ItemSpawner::SpawnActorFromClass(GameInstances::GetWorld(), SDK::APostProcessVolume::StaticClass(), SpawnOriginTransform, nullptr);
    SDK::APostProcessVolume* PostProcessVolume = static_cast<SDK::APostProcessVolume*>(SpawnedActor);

    if (SpawnedActor)
    {
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
            << "\n\nPost Process Created and Settings Applied!\n\n" << std::endl;
    }

    GameInstances::Initialize(PostProcessVolume);
    Actions::Initialize(Module);

    KeyHandler* keyHandler = KeyHandler::GetInstance();
    keyHandler->LoadKeyBindings();

    auto bindings = keyHandler->GetKeyBindings();
    std::cout << "Key bindings:\n";
    for (const auto& [key, actionId] : bindings)
    {
        std::cout << keyHandler->GetKeyName(key) << " -> " << Actions::GetActionName(actionId) << "\n";
    }

    while (true)
    {
        keyHandler->HandleKeys();

        if (IsMouseMoving() && Actions::bInfiniteStaminaEnabled)
            GameInstances::GetPawn()->Stamina = 100;

        Sleep(50);
    }
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH)
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, 0);

    return TRUE;
}