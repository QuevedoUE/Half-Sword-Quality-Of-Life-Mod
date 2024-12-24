#pragma once

#include "SDK.hpp"

using namespace SDK;

class GameInstances
{
public:
    static APostProcessVolume* PostProcessVolume;

    static void Initialize(APostProcessVolume* PPVolume) { PostProcessVolume = PPVolume; }

    static UWorld* GetWorld()                          { return UWorld::GetWorld(); }
    static APlayerController* GetPlayerController()    { return GetWorld()->OwningGameInstance->LocalPlayers[0]->PlayerController; }
    static AWorldSettings* GetWorldSettings()          { return GetWorld()->K2_GetWorldSettings(); }
    static AWillie_BP_C* GetPawn()                     { return static_cast<AWillie_BP_C*>(GetPlayerController()->Pawn); }
    static APostProcessVolume* GetPostProcessVolume()  { return PostProcessVolume; }
};