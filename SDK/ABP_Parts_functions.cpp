#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ABP_Parts

#include "Basic.hpp"

#include "ABP_Parts_classes.hpp"
#include "ABP_Parts_parameters.hpp"


namespace SDK
{

// Function ABP_Parts.ABP_Parts_C.AnimGraph
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FPoseLink                        Param_AnimGraph                                        (Parm, OutParm, NoDestructor)

void UABP_Parts_C::AnimGraph(struct FPoseLink* Param_AnimGraph)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ABP_Parts_C", "AnimGraph");

	Params::ABP_Parts_C_AnimGraph Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Param_AnimGraph != nullptr)
		*Param_AnimGraph = std::move(Parms.Param_AnimGraph);
}


// Function ABP_Parts.ABP_Parts_C.BlueprintBeginPlay
// (Event, Public, BlueprintEvent)

void UABP_Parts_C::BlueprintBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ABP_Parts_C", "BlueprintBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function ABP_Parts.ABP_Parts_C.BlueprintInitializeAnimation
// (Event, Public, BlueprintEvent)

void UABP_Parts_C::BlueprintInitializeAnimation()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ABP_Parts_C", "BlueprintInitializeAnimation");

	UObject::ProcessEvent(Func, nullptr);
}


// Function ABP_Parts.ABP_Parts_C.BlueprintUpdateAnimation
// (Event, Public, BlueprintEvent)
// Parameters:
// float                                   DeltaTimeX                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UABP_Parts_C::BlueprintUpdateAnimation(float DeltaTimeX)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ABP_Parts_C", "BlueprintUpdateAnimation");

	Params::ABP_Parts_C_BlueprintUpdateAnimation Parms{};

	Parms.DeltaTimeX = DeltaTimeX;

	UObject::ProcessEvent(Func, &Parms);
}


// Function ABP_Parts.ABP_Parts_C.EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_Parts_AnimGraphNode_TwoWayBlend_4F1E5A824D23E69605A424860020F3BF
// (BlueprintEvent)

void UABP_Parts_C::EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_Parts_AnimGraphNode_TwoWayBlend_4F1E5A824D23E69605A424860020F3BF()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ABP_Parts_C", "EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_Parts_AnimGraphNode_TwoWayBlend_4F1E5A824D23E69605A424860020F3BF");

	UObject::ProcessEvent(Func, nullptr);
}


// Function ABP_Parts.ABP_Parts_C.EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_Parts_AnimGraphNode_TwoWayBlend_8891B42B473E6ED5862E26A9705F4AC6
// (BlueprintEvent)

void UABP_Parts_C::EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_Parts_AnimGraphNode_TwoWayBlend_8891B42B473E6ED5862E26A9705F4AC6()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ABP_Parts_C", "EvaluateGraphExposedInputs_ExecuteUbergraph_ABP_Parts_AnimGraphNode_TwoWayBlend_8891B42B473E6ED5862E26A9705F4AC6");

	UObject::ProcessEvent(Func, nullptr);
}


// Function ABP_Parts.ABP_Parts_C.ExecuteUbergraph_ABP_Parts
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UABP_Parts_C::ExecuteUbergraph_ABP_Parts(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ABP_Parts_C", "ExecuteUbergraph_ABP_Parts");

	Params::ABP_Parts_C_ExecuteUbergraph_ABP_Parts Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}

}
