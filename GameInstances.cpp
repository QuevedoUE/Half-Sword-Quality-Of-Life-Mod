#include "GameInstances.h"

APostProcessVolume* GameInstances::PostProcessVolume = nullptr;

void GameInstances::Initialize(APostProcessVolume* PPVolume)
{
    PostProcessVolume = PPVolume;
}

UWorld* GameInstances::GetWorld()
{
    return UWorld::GetWorld();
}

APlayerController* GameInstances::GetPlayerController()
{
    return GetWorld()->OwningGameInstance->LocalPlayers[0]->PlayerController;
}

AWorldSettings* GameInstances::GetWorldSettings()
{
    return GetWorld()->K2_GetWorldSettings();
}

AWillie_BP_C* GameInstances::GetPawn()
{
    return static_cast<AWillie_BP_C*>(GetPlayerController()->Pawn);
}

APostProcessVolume* GameInstances::GetPostProcessVolume()
{
    return PostProcessVolume;
}