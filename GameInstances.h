#pragma once

#include "SDK.hpp"

class GameInstances
{
public:
    static void Initialize(SDK::APostProcessVolume* PPVolume);

    static SDK::UWorld* GetWorld();
    static SDK::APlayerController* GetPlayerController();
    static SDK::AWorldSettings* GetWorldSettings();
    static SDK::AWillie_BP_C* GetPawn();
    static SDK::APostProcessVolume* GetPostProcessVolume();

private:
    static SDK::APostProcessVolume* PostProcessVolume;
};