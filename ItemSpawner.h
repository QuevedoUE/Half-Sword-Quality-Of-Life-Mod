#include "SDK.hpp"

class ItemSpawner
{
public:
    static std::unordered_map<int, SDK::TSubclassOf<class SDK::AActor>> ItemMap;
    static SDK::AActor* SpawnActorFromClass(class SDK::UObject* WorldContextObject, SDK::TSubclassOf<class SDK::AActor> ActorClass, SDK::FTransform& SpawnTransform, SDK::AActor* Owner);
    static void AskForItemAndSpawn(SDK::UWorld* World, SDK::AWillie_BP_C* CurrentPawn);
};