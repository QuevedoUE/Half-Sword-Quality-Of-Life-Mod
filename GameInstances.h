#pragma once

#include "SDK.hpp"

using namespace SDK;

namespace GameInstances
{
    static APostProcessVolume* PostProcessVolume;

    inline void Initialize(APostProcessVolume* PPVolume) { PostProcessVolume = PPVolume; }

    inline UWorld* GetWorld()                          { return UWorld::GetWorld(); }
    inline APlayerController* GetPlayerController()    { return GetWorld()->OwningGameInstance->LocalPlayers[0]->PlayerController; }
    inline AWorldSettings* GetWorldSettings()          { return GetWorld()->K2_GetWorldSettings(); }
    inline AWillie_BP_C* GetPawn()                     { return static_cast<AWillie_BP_C*>(GetPlayerController()->Pawn); }
    inline APostProcessVolume* GetPostProcessVolume()  { return PostProcessVolume; }
}