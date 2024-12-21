#include "GameInstances.h"

SDK::APostProcessVolume* GameInstances::PostProcessVolume = nullptr;

void GameInstances::Initialize(SDK::APostProcessVolume* PPVolume)
{
    PostProcessVolume = PPVolume;
}

SDK::UWorld* GameInstances::GetWorld()
{
    return SDK::UWorld::GetWorld();
}

SDK::APlayerController* GameInstances::GetPlayerController()
{
    return GetWorld()->OwningGameInstance->LocalPlayers[0]->PlayerController;
}

SDK::AWorldSettings* GameInstances::GetWorldSettings()
{
    return GetWorld()->K2_GetWorldSettings();
}

SDK::AWillie_BP_C* GameInstances::GetPawn()
{
    return static_cast<SDK::AWillie_BP_C*>(GetPlayerController()->Pawn);
}

SDK::APostProcessVolume* GameInstances::GetPostProcessVolume()
{
    return PostProcessVolume;
}