#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: UI_Checkbox

#include "Basic.hpp"

#include "UI_Checkbox_classes.hpp"
#include "UI_Checkbox_parameters.hpp"


namespace SDK
{

// Function UI_Checkbox.UI_Checkbox_C.BndEvt__ToggleDoF_1_K2Node_ComponentBoundEvent_3_OnCheckBoxComponentStateChanged__DelegateSignature
// (BlueprintEvent)
// Parameters:
// bool                                    bIsChecked                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UUI_Checkbox_C::BndEvt__ToggleDoF_1_K2Node_ComponentBoundEvent_3_OnCheckBoxComponentStateChanged__DelegateSignature(bool bIsChecked)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Checkbox_C", "BndEvt__ToggleDoF_1_K2Node_ComponentBoundEvent_3_OnCheckBoxComponentStateChanged__DelegateSignature");

	Params::UI_Checkbox_C_BndEvt__ToggleDoF_1_K2Node_ComponentBoundEvent_3_OnCheckBoxComponentStateChanged__DelegateSignature Parms{};

	Parms.bIsChecked = bIsChecked;

	UObject::ProcessEvent(Func, &Parms);
}


// Function UI_Checkbox.UI_Checkbox_C.ChangeValue
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    bValue                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Param_bShouldFocus                                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UUI_Checkbox_C::ChangeValue(bool bValue, bool Param_bShouldFocus)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Checkbox_C", "ChangeValue");

	Params::UI_Checkbox_C_ChangeValue Parms{};

	Parms.bValue = bValue;
	Parms.Param_bShouldFocus = Param_bShouldFocus;

	UObject::ProcessEvent(Func, &Parms);
}


// Function UI_Checkbox.UI_Checkbox_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UUI_Checkbox_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Checkbox_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function UI_Checkbox.UI_Checkbox_C.ExecuteUbergraph_UI_Checkbox
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UUI_Checkbox_C::ExecuteUbergraph_UI_Checkbox(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Checkbox_C", "ExecuteUbergraph_UI_Checkbox");

	Params::UI_Checkbox_C_ExecuteUbergraph_UI_Checkbox Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function UI_Checkbox.UI_Checkbox_C.Initialize
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Param_bDefaultValue                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UUI_Checkbox_C::Initialize(bool Param_bDefaultValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Checkbox_C", "Initialize");

	Params::UI_Checkbox_C_Initialize Parms{};

	Parms.Param_bDefaultValue = Param_bDefaultValue;

	UObject::ProcessEvent(Func, &Parms);
}


// Function UI_Checkbox.UI_Checkbox_C.OnCheckboxValueChanged__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Value                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UUI_Checkbox_C::OnCheckboxValueChanged__DelegateSignature(bool Value)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Checkbox_C", "OnCheckboxValueChanged__DelegateSignature");

	Params::UI_Checkbox_C_OnCheckboxValueChanged__DelegateSignature Parms{};

	Parms.Value = Value;

	UObject::ProcessEvent(Func, &Parms);
}


// Function UI_Checkbox.UI_Checkbox_C.OnMouseEnter
// (BlueprintCosmetic, Event, Public, HasOutParams, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    MouseEvent                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)

void UUI_Checkbox_C::OnMouseEnter(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Checkbox_C", "OnMouseEnter");

	Params::UI_Checkbox_C_OnMouseEnter Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.MouseEvent = std::move(MouseEvent);

	UObject::ProcessEvent(Func, &Parms);
}


// Function UI_Checkbox.UI_Checkbox_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UUI_Checkbox_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Checkbox_C", "PreConstruct");

	Params::UI_Checkbox_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function UI_Checkbox.UI_Checkbox_C.ResetCheckbox
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Param_bShouldFocus                                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UUI_Checkbox_C::ResetCheckbox(bool Param_bShouldFocus)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Checkbox_C", "ResetCheckbox");

	Params::UI_Checkbox_C_ResetCheckbox Parms{};

	Parms.Param_bShouldFocus = Param_bShouldFocus;

	UObject::ProcessEvent(Func, &Parms);
}


// Function UI_Checkbox.UI_Checkbox_C.ResetToggleFocus
// (BlueprintCallable, BlueprintEvent)

void UUI_Checkbox_C::ResetToggleFocus()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Checkbox_C", "ResetToggleFocus");

	UObject::ProcessEvent(Func, nullptr);
}


// Function UI_Checkbox.UI_Checkbox_C.Set Focused or Unfocused Color
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Param_bChangeCheckboxColorWhenFocused                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Param_bChangeTextColorWhenFocused                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UCheckBox*                        Param_CheckBox                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
// class UWidget*                          CheckboxTitle                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
// class UWidget*                          Param_CheckboxValue                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)

void UUI_Checkbox_C::Set_Focused_or_Unfocused_Color(bool Param_bChangeCheckboxColorWhenFocused, bool Param_bChangeTextColorWhenFocused, class UCheckBox* Param_CheckBox, class UWidget* CheckboxTitle, class UWidget* Param_CheckboxValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Checkbox_C", "Set Focused or Unfocused Color");

	Params::UI_Checkbox_C_Set_Focused_or_Unfocused_Color Parms{};

	Parms.Param_bChangeCheckboxColorWhenFocused = Param_bChangeCheckboxColorWhenFocused;
	Parms.Param_bChangeTextColorWhenFocused = Param_bChangeTextColorWhenFocused;
	Parms.Param_CheckBox = Param_CheckBox;
	Parms.CheckboxTitle = CheckboxTitle;
	Parms.Param_CheckboxValue = Param_CheckboxValue;

	UObject::ProcessEvent(Func, &Parms);
}


// Function UI_Checkbox.UI_Checkbox_C.SetToggleFocus
// (BlueprintCallable, BlueprintEvent)

void UUI_Checkbox_C::SetToggleFocus()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Checkbox_C", "SetToggleFocus");

	UObject::ProcessEvent(Func, nullptr);
}


// Function UI_Checkbox.UI_Checkbox_C.setTxtValue
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FText                             ReturnValue                                            (Parm, OutParm, ReturnParm)

class FText UUI_Checkbox_C::SetTxtValue()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Checkbox_C", "setTxtValue");

	Params::UI_Checkbox_C_SetTxtValue Parms{};

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function UI_Checkbox.UI_Checkbox_C.ToggleUsingArrows
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// EUINavigation                           Param_Navigation                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UWidget*                          ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, NoDestructor, HasGetValueTypeHash)

class UWidget* UUI_Checkbox_C::ToggleUsingArrows(EUINavigation Param_Navigation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("UI_Checkbox_C", "ToggleUsingArrows");

	Params::UI_Checkbox_C_ToggleUsingArrows Parms{};

	Parms.Param_Navigation = Param_Navigation;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}

}

