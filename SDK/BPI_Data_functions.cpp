#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BPI_Data

#include "Basic.hpp"

#include "BPI_Data_classes.hpp"
#include "BPI_Data_parameters.hpp"


namespace SDK
{

// Function BPI_Data.BPI_Data_C.SendPhotoData
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FS_PhotosData                    PhotoData                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)

void IBPI_Data_C::SendPhotoData(const struct FS_PhotosData& PhotoData)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPI_Data_C", "SendPhotoData");

	Params::BPI_Data_C_SendPhotoData Parms{};

	Parms.PhotoData = std::move(PhotoData);

	UObject::ProcessEvent(Func, &Parms);
}


// Function BPI_Data.BPI_Data_C.TabToOpen
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   TabIndex                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UUI_TabButton_C*                  CommonButtonPressed                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)

void IBPI_Data_C::TabToOpen(int32 TabIndex, class UUI_TabButton_C* CommonButtonPressed)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPI_Data_C", "TabToOpen");

	Params::BPI_Data_C_TabToOpen Parms{};

	Parms.TabIndex = TabIndex;
	Parms.CommonButtonPressed = CommonButtonPressed;

	UObject::ProcessEvent(Func, &Parms);
}

}
