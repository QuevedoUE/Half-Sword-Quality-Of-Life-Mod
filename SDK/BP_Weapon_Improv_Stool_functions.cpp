#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_Weapon_Improv_Stool

#include "Basic.hpp"

#include "BP_Weapon_Improv_Stool_classes.hpp"
#include "BP_Weapon_Improv_Stool_parameters.hpp"


namespace SDK
{

// Function BP_Weapon_Improv_Stool.BP_Weapon_Improv_Stool_C.BndEvt__Buckler_Buckler_K2Node_ComponentBoundEvent_0_ComponentHitSignature__DelegateSignature
// (HasOutParams, BlueprintEvent)
// Parameters:
// class UPrimitiveComponent*              HitComponent                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
// class AActor*                           OtherActor                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
// class UPrimitiveComponent*              OtherComp                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
// struct FVector                          NormalImpulse                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FHitResult                       Hit                                                    (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, IsPlainOldData, NoDestructor, ContainsInstancedReference)

void ABP_Weapon_Improv_Stool_C::BndEvt__Buckler_Buckler_K2Node_ComponentBoundEvent_0_ComponentHitSignature__DelegateSignature(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, const struct FVector& NormalImpulse, const struct FHitResult& Hit)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Weapon_Improv_Stool_C", "BndEvt__Buckler_Buckler_K2Node_ComponentBoundEvent_0_ComponentHitSignature__DelegateSignature");

	Params::BP_Weapon_Improv_Stool_C_BndEvt__Buckler_Buckler_K2Node_ComponentBoundEvent_0_ComponentHitSignature__DelegateSignature Parms{};

	Parms.HitComponent = HitComponent;
	Parms.OtherActor = OtherActor;
	Parms.OtherComp = OtherComp;
	Parms.NormalImpulse = std::move(NormalImpulse);
	Parms.Hit = std::move(Hit);

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_Weapon_Improv_Stool.BP_Weapon_Improv_Stool_C.ExecuteUbergraph_BP_Weapon_Improv_Stool
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_Weapon_Improv_Stool_C::ExecuteUbergraph_BP_Weapon_Improv_Stool(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Weapon_Improv_Stool_C", "ExecuteUbergraph_BP_Weapon_Improv_Stool");

	Params::BP_Weapon_Improv_Stool_C_ExecuteUbergraph_BP_Weapon_Improv_Stool Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_Weapon_Improv_Stool.BP_Weapon_Improv_Stool_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void ABP_Weapon_Improv_Stool_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Weapon_Improv_Stool_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}

}
