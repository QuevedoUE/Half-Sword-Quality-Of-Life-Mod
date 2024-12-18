#include "SDK.hpp"

class ItemSpawner
{
public:
    SDK::AActor* SpawnActorFromClass(class SDK::UObject* WorldContextObject, SDK::TSubclassOf<class SDK::AActor> ActorClass, SDK::FTransform& SpawnTransform, SDK::AActor* Owner);
    void AskForItemAndSpawn();
};