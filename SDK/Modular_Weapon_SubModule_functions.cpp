#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Modular_Weapon_SubModule

#include "Basic.hpp"

#include "Modular_Weapon_SubModule_classes.hpp"


namespace SDK
{

// Function Modular_Weapon_SubModule.Modular_Weapon_SubModule_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void AModular_Weapon_SubModule_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Modular_Weapon_SubModule_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}

}
