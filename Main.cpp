#include "SDK.hpp"
#include <Windows.h>
#include <iostream>
#include "pch.h"
#include "SDK/Engine_classes.hpp"
#include "SDK/Engine_parameters.hpp"
#include "SDK/Engine_structs.hpp"
#include <thread> 
#include <chrono> 

SDK::AActor* SpawnActorFromClass(class SDK::UObject* WorldContextObject,
    SDK::TSubclassOf<class SDK::AActor> ActorClass,
    struct SDK::FTransform& SpawnTransform,
    SDK::ESpawnActorCollisionHandlingMethod CollisionHandlingOverride,
    class SDK::AActor* Owner,
    SDK::ESpawnActorScaleMethod SpawnActorScaleMethod)
{
 
    SDK::ESpawnActorScaleMethod NormalScaleMethod = SDK::ESpawnActorScaleMethod::SelectDefaultAtRuntime;

   
    auto Spawned = SDK::UGameplayStatics::BeginDeferredActorSpawnFromClass(WorldContextObject,
        ActorClass,
        SpawnTransform,
        CollisionHandlingOverride,
        Owner,
        SpawnActorScaleMethod);

    Spawned = SDK::UGameplayStatics::FinishSpawningActor(Spawned, SpawnTransform, NormalScaleMethod);


    
    return Spawned; 
}



// Last Position OF The Mouse
POINT lastMousePosition = { 0, 0 };

bool IsMouseMoving()
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

void ClearConsole()
{
    system("cls");
}

DWORD MainThread(HMODULE Module)
{
    Sleep(800);
    /* Code to open a console window */
    AllocConsole();
    Sleep(800);
    FILE* Dummy;
    freopen_s(&Dummy, "CONOUT$", "w", stdout);
    Sleep(800);
    freopen_s(&Dummy, "CONIN$", "r", stdin);
    Sleep(800);

    /* Functions returning "static" instances */
    SDK::UEngine* Engine = SDK::UEngine::GetEngine();
    Sleep(800);
    SDK::UWorld* World = SDK::UWorld::GetWorld();
    Sleep(800);
    SDK::APlayerController* MyController = World->OwningGameInstance->LocalPlayers[0]->PlayerController;
    Sleep(800);
    SDK::APawn PlayerPawn = *MyController->K2_GetPawn();
    Sleep(800);
    SDK::AWorldSettings* WorldSettings = World->K2_GetWorldSettings();
    Sleep(800);
    static float ActualTimeDilation = 1.0f;
    Sleep(800);
    MyController->EnableCheats();
    Sleep(800);
    /* Print the full-name of an object ("ClassName PackageName.OptionalOuter.ObjectName") */
    std::cout << Engine->ConsoleClass->GetFullName() << std::endl;
    Sleep(800);
    /* Manually iterating GObjects and printing the FullName of every UObject that is a Pawn (not recommended) */
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 0; i < SDK::UObject::GObjects->Num(); i++)
    {
        SDK::UObject* Obj = SDK::UObject::GObjects->GetByIndex(i);

        if (!Obj)
            continue;
        
        if (Obj->IsDefaultObject())
            continue;


        /* Only the 'IsA' check using the cast flags is required, the other 'IsA' is redundant */
        if (Obj->IsA(SDK::APawn::StaticClass()) || Obj->HasTypeFlag(SDK::EClassCastFlags::Pawn))
        {
            std::cout << Obj->GetFullName() << "\n";
        }
    }
    Sleep(800);
    /* You might need to loop all levels in UWorld::Levels */
    SDK::ULevel* Level = World->PersistentLevel;
    Sleep(800);
    SDK::TArray<SDK::AActor*>& Actors = Level->Actors;
    Sleep(800);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (SDK::AActor* Actor : Actors)
    {
        /* The 2nd and 3rd checks are equal, prefer using EClassCastFlags if available for your class. */
        if (!Actor || !Actor->IsA(SDK::EClassCastFlags::Pawn) || !Actor->IsA(SDK::APawn::StaticClass()))
            continue;

        SDK::APawn* Pawn = static_cast<SDK::APawn*>(Actor);
        // Use Pawn here
    }
    /*
    * Changes the keyboard-key that's used to open the UE console
    *Sleep(800);
    * This is a rare case of a DefaultObjects' member-variables being changed.
    * By default you do not want to use the DefaultObject, this is a rare exception.
    */
    Sleep(800);
    SDK::UInputSettings::GetDefaultObj()->ConsoleKeys[0].KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"F2");
    Sleep(800);
    SDK::UObject* NewObject = SDK::UGameplayStatics::SpawnObject(Engine->ConsoleClass, Engine->GameViewport);
    Sleep(800);
    SDK::FTransform SpawnOriginTransform; Sleep(800);
    Sleep(800);
    // Asignar ubicaci�n directamente
    SpawnOriginTransform.Translation = SDK::FVector(0.0f, 0.0f, 0.0f); // Ajusta la posici�n deseada
    Sleep(800);
    // Asignar rotaci�n directamente (usa una rotaci�n por defecto, como una identidad)
    SpawnOriginTransform.Rotation = SDK::FQuat(180.0f, 0.0f, 0.0f, 1.0f); // Quaternion identidad
    Sleep(800);
    // Asignar escala directamente
    SpawnOriginTransform.Scale3D = SDK::FVector(1.0f, 1.0f, 1.0f); // Escala unitaria
    Sleep(800);
    Engine->GameViewport->ViewportConsole = static_cast<SDK::UConsole*>(NewObject);
    /* Creates a new UObject of class-type specified by Engine->ConsoleClass */
    Sleep(800);
    Sleep(800);
    Sleep(5000);
    ClearConsole();
    Sleep(800);
    Sleep(800);
    MyController->EnableCheats();
    Sleep(800);
    class SDK::AWillie_BP_C* CurrentPawn = static_cast<SDK::AWillie_BP_C*>(MyController->Pawn);
    Sleep(800);
    SDK::FVector MenuCameraBetterLoc(-100, 920, 100);
    Sleep(800);
    CurrentPawn->K2_SetActorLocation(MenuCameraBetterLoc, false, nullptr, true);
    Sleep(800);
    std::this_thread::sleep_for(std::chrono::seconds(1));
        Sleep(800);
        SDK::ESpawnActorCollisionHandlingMethod CollisionHandling = SDK::ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        SDK::ESpawnActorScaleMethod SpawnMethod = SDK::ESpawnActorScaleMethod::SelectDefaultAtRuntime;
        Sleep(800);
        
        SDK::AActor* SpawnedActor = SpawnActorFromClass(World, SDK::APostProcessVolume::StaticClass(), SpawnOriginTransform, CollisionHandling, nullptr, SpawnMethod);
        Sleep(800);

        Sleep(800);
        if (SpawnedActor)
        {
            Sleep(800);
            SDK::APostProcessVolume* PostProcessCreatedVolume = static_cast<SDK::APostProcessVolume*>(SpawnedActor);
            Sleep(800);

            PostProcessCreatedVolume->bUnbound = true;
            Sleep(800);
            PostProcessCreatedVolume->Settings.bOverride_ColorGradingIntensity = true;
            PostProcessCreatedVolume->Settings.ColorGradingIntensity = 0.7f;
            Sleep(800);
            PostProcessCreatedVolume->Settings.bOverride_RayTracingGI = true;
            PostProcessCreatedVolume->Settings.RayTracingTranslucencyMaxRoughness = 0.6f;
            Sleep(800);

            PostProcessCreatedVolume->Settings.bOverride_BloomIntensity = true;
            PostProcessCreatedVolume->Settings.BloomIntensity = 2.5f;
            PostProcessCreatedVolume->Settings.bOverride_BloomSizeScale = true;
            Sleep(800);
            PostProcessCreatedVolume->Settings.BloomSizeScale = 1.2f;
            PostProcessCreatedVolume->Settings.bOverride_BloomThreshold = true;
            PostProcessCreatedVolume->Settings.BloomThreshold = 1.0f;
            Sleep(800);

            PostProcessCreatedVolume->Settings.bOverride_MotionBlurAmount = true;
            PostProcessCreatedVolume->Settings.MotionBlurAmount = 0.7f;


            PostProcessCreatedVolume->Settings.bOverride_VignetteIntensity = true;
            PostProcessCreatedVolume->Settings.VignetteIntensity = 0.45f;
            Sleep(800);

            PostProcessCreatedVolume->Settings.bOverride_ReflectionsType = true;
            PostProcessCreatedVolume->Settings.ReflectionsType = SDK::EReflectionsType::RayTracing;
            PostProcessCreatedVolume->Settings.bOverride_RayTracingReflectionsMaxRoughness = true;
            PostProcessCreatedVolume->Settings.RayTracingAOIntensity = 0;
            Sleep(800);

            PostProcessCreatedVolume->Settings.bOverride_AutoExposureMethod = true;
            PostProcessCreatedVolume->Settings.AutoExposureMethod = SDK::EAutoExposureMethod::AEM_Histogram;
            PostProcessCreatedVolume->Settings.bOverride_AutoExposureBias = true;
            PostProcessCreatedVolume->Settings.AutoExposureBias = 0.3f;


            PostProcessCreatedVolume->Settings.bOverride_SceneFringeIntensity = true;
            PostProcessCreatedVolume->Settings.SceneFringeIntensity = 1.0f;


            PostProcessCreatedVolume->Settings.bOverride_FilmGrainIntensity = true;
            PostProcessCreatedVolume->Settings.FilmGrainIntensity = 0.35f;
            Sleep(800);

            PostProcessCreatedVolume->Settings.bOverride_AmbientCubemapIntensity = true;
            PostProcessCreatedVolume->Settings.AmbientCubemapIntensity = 0.5f;
            PostProcessCreatedVolume->Settings.bOverride_AmbientCubemapTint = true;
            PostProcessCreatedVolume->Settings.AmbientCubemapTint = SDK::FLinearColor(1.0f, 0.8f, 0.5f);
            Sleep(800);


            PostProcessCreatedVolume->Settings.bOverride_DepthOfFieldFocalDistance = true;
            PostProcessCreatedVolume->Settings.DepthOfFieldFocalDistance = 250.0f;
            Sleep(200);
            PostProcessCreatedVolume->Settings.bOverride_DepthOfFieldFocalRegion = true;
            PostProcessCreatedVolume->Settings.DepthOfFieldFocalRegion = 150.0f;
            Sleep(800);

            PostProcessCreatedVolume->Settings.bOverride_SceneColorTint = true;
            PostProcessCreatedVolume->Settings.SceneColorTint = SDK::FLinearColor(240.0f / 255.0f, 180.0f / 255.0f, 120.0f / 255.0f);

            std::cout << "!Post Process Created and Settings Applied!" << std::endl;
            Sleep(800);

            SDK::AWorldSettings* WorldSettings = World->K2_GetWorldSettings();
        }
    while (true)
    {

        class SDK::AWillie_BP_C* CurrentPawn = static_cast<SDK::AWillie_BP_C*>(MyController->Pawn);



        if (GetAsyncKeyState(VK_F3) & 1)
        {
            std::cout << "Enter new speed: ";
            std::cin >> CurrentPawn->Running_Speed_Rate;
            class SDK::AWillie_BP_C* CurrentPawn = static_cast<SDK::AWillie_BP_C*>(MyController->Pawn);
            CurrentPawn->CharacterMovement->MaxAcceleration = 9999999;
            CurrentPawn->CharacterMovement->bCheatFlying = 1;
        }

        if (GetAsyncKeyState (IsMouseMoving() & 1))
        {
            CurrentPawn->Stamina = 100;
        }

        if (GetAsyncKeyState(VK_LBUTTON) & 1)
        {
            CurrentPawn->Default_Pelvis_Mass = 0;
            CurrentPawn->R_Weapon_Mass = 0;
            CurrentPawn->L_Weapon_Mass = 0;
            CurrentPawn->Aim_Swing_Speed = 999.0;
        }

        if (GetAsyncKeyState(71) & 1)
        {
            class SDK::AWillie_BP_C* CurrentPawn = static_cast<SDK::AWillie_BP_C*>(MyController->Pawn);
            CurrentPawn->Save_Loadout();
        };
        if (GetAsyncKeyState(9) & 1)
        {
            Level->WorldSettings->bForceNoPrecomputedLighting = true;
        };

        if (GetAsyncKeyState(90) & 1)
        {
 
            if (ActualTimeDilation != 0.7f) {
                WorldSettings->TimeDilation = 0.7f;  
                ActualTimeDilation = 0.7f;           
            }
            else {
                WorldSettings->TimeDilation = 1.0f; 
                ActualTimeDilation = 1.0f;           
            }
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