#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: UI_Lose

#include "Basic.hpp"

#include "UI_Lose_classes.hpp"
#include "UI_Lose_parameters.hpp"


namespace SDK
{

// Function UI_Lose.UI_Lose_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UUI_Lose_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Lose_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function UI_Lose.UI_Lose_C.ExecuteUbergraph_UI_Lose
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UUI_Lose_C::ExecuteUbergraph_UI_Lose(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Lose_C", "ExecuteUbergraph_UI_Lose");

	Params::UI_Lose_C_ExecuteUbergraph_UI_Lose Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function UI_Lose.UI_Lose_C.Get_Score_Text
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FText                             ReturnValue                                            (Parm, OutParm, ReturnParm)

class FText UUI_Lose_C::Get_Score_Text()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Lose_C", "Get_Score_Text");

	Params::UI_Lose_C_Get_Score_Text Parms{};

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function UI_Lose.UI_Lose_C.Tick
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// float                                   InDeltaTime                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UUI_Lose_C::Tick(const struct FGeometry& MyGeometry, float InDeltaTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Lose_C", "Tick");

	Params::UI_Lose_C_Tick Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.InDeltaTime = InDeltaTime;

	UObject::ProcessEvent(Func, &Parms);
}

}
