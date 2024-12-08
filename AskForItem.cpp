#include "AskForItemToSpawn.h"
#include "SDK.hpp"
#include <Windows.h>
#include <iostream>
#include "pch.h"
#include "SDK/Engine_classes.hpp"
#include "SDK/Engine_parameters.hpp"
#include "SDK/Engine_structs.hpp"
#include <thread> 
#include <chrono> 


SDK::UEngine* Engine = SDK::UEngine::GetEngine();
SDK::UWorld* World = SDK::UWorld::GetWorld();
SDK::APlayerController* MyController = World->OwningGameInstance->LocalPlayers[0]->PlayerController;

class SDK::AWillie_BP_C* CurrentPawn = static_cast<SDK::AWillie_BP_C*>(MyController->Pawn);


//Spawn Funcion
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

void AskForItemToSpawn::AskForItemAndSpawn() {

	int ItemID;

	std::cout << "Enter Item ID:";
	std::cin >> ItemID;

    class SDK::AWillie_BP_C* CurrentPawn = static_cast<SDK::AWillie_BP_C*>(MyController->Pawn);
    SDK::FTransform CurrentPlayerTransform = CurrentPawn->GetTransform();
   
    CurrentPlayerTransform.Translation = CurrentPlayerTransform.Translation + (CurrentPawn->GetActorForwardVector() * 40);
    SDK::ESpawnActorCollisionHandlingMethod CollisionHandling = SDK::ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    SDK::ESpawnActorScaleMethod SpawnMethod = SDK::ESpawnActorScaleMethod::SelectDefaultAtRuntime;

    SDK::AActor* SpawnedActor = nullptr;

switch (ItemID)
{
    /*ARMORS*/
    case 1:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Arms_Chains_T1_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 2:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Arms_Chains_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 3:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Arms_Vambrace_A_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 4:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Arms_Vambrace_A_T3_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 5:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Arms_Vambrace_B_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 6:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Arms_Vambrace_B_T3_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 7:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Arms_Vambrace_C_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 8:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Arms_Vambrace_C_T3_B_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 9:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Arms_Vambrace_C_T3_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 10:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Brestplate_A_T1_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 11:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Brestplate_A_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 12:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Brestplate_B_T1_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 13:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Brestplate_B_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 14:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Cuirass_A_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 15:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Cuirass_B_T1_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 16:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Cuirass_C_T1_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 17:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Cuirass_C_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 18:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Cuirass_C_T3_B_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 19:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Cuirass_C_T3_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 20:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Doublet_Arming_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 21:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Doublet_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 22:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Gambeson_A_T1_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 23:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Gambeson_A_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 24:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Gambeson_B_T1_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 25:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Gambeson_B_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 26:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Plackard_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 27:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Shirt_A_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 28:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Body_Shirt_B_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 30:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Feet_Sabbatons_AB_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 31:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Feet_Sabbatons_A_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 32:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Feet_Shoes_A_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 33:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Feet_Shoes_B_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 34:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Feet_Shoes_C_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 35:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Hands_Gauntlets_T1_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 36:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Hands_Gauntlets_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 37:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Hands_Gauntlets_T3B_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 38:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Hands_Gauntlets_T3_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 39:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Hands_HalfGauntlets_T1_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 40:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Hands_HalfGauntlets_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 41:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Armet_001_B_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 42:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Armet_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 43:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Armet_001_R_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 44:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Barbute_A_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 45:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Barbute_B_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 46:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Hat_Bycocket_A_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 47:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Hat_Bycocket_A_002_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 48:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Hat_Bycocket_B_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 49:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Hat_Bycocket_B_002_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 50:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Hat_Bycocket_C_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 51:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Hat_Bycocket_D_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 52:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Hat_Bycocket_E_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 53:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Hat_Bycocket_F_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 54:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Hat_Bycocket_G_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 55:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Hat_Bycocket_H_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 57:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Hat_Bycocket_I_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 58:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Hat_Bycocket_J_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 59:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Hat_Gnome_A_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 60:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Hat_Gnome_B_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 61:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Kettle_Helm_A_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 62:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Kettle_Helm_B_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 63:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Kettle_Helm_C_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 64:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Kettle_Helm_D_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 65:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Sallet_Open_A_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 66:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Sallet_Open_B_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 67:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Sallet_Open_CA_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 68:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Sallet_Open_CB_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 69:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Sallet_Solid_A_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 70:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Sallet_Solid_A_002_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 71:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Sallet_Solid_B_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 72:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Sallet_Solid_B_002_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 73:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Sallet_Solid_C_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 74:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Sallet_Solid_C_002_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 75:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Sallet_Solid_D_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 76:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Sallet_Solid_D_002_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 77:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Sallet_Solid_E_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 78:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Sallet_Solid_E_002_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 79:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Sallet_Visor_A_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 80:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Head_Sallet_Visor_B_001_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 81:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Legs_Cuisse_A_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 82:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Legs_Cuisse_A_T3_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 83:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Legs_Cuisse_B_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 84:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Legs_Greaves_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 85:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Legs_Greaves_T3_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 86:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Legs_Hosen_Arming_A_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 87:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Legs_Hosen_A_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 88:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Legs_Hosen_B_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 89:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Legs_Hosen_C_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 90:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Legs_Panties_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 91:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Neck_Bevor_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 92:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Neck_Bevor_T3_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 93:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Neck_Standard_T1_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 94:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Neck_Standard_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 95:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Neck_Standard_T3_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 96:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Shoulders_Pauldron_C_B_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 97:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Shoulders_Pauldron_C_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 98:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Shoulders_Spaulder_A_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 99:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Shoulders_Spaulder_A_T3_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 100:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Shoulders_Spaulder_B_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 101:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Shoulders_Spaulder_B_T3_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 102:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Waist_Foulds_T1_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 103:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Waist_Foulds_T2_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    case 104:
        SpawnedActor = SpawnActorFromClass(World, SDK::ABP_Armor_Waist_Foulds_T3_C::StaticClass(), CurrentPlayerTransform, CollisionHandling, nullptr, SpawnMethod); break;
    /*WAPEONS*/
}
}

