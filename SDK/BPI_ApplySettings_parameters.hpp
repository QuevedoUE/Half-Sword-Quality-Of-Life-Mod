#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BPI_ApplySettings

#include "Basic.hpp"


namespace SDK::Params
{

// Function BPI_ApplySettings.BPI_ApplySettings_C.Apply Settings
// 0x0008 (0x0008 - 0x0000)
struct BPI_ApplySettings_C_Apply_Settings final
{
public:
	double                                        FOV;                                               // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(BPI_ApplySettings_C_Apply_Settings) == 0x000008, "Wrong alignment on BPI_ApplySettings_C_Apply_Settings");
static_assert(sizeof(BPI_ApplySettings_C_Apply_Settings) == 0x000008, "Wrong size on BPI_ApplySettings_C_Apply_Settings");
static_assert(offsetof(BPI_ApplySettings_C_Apply_Settings, FOV) == 0x000000, "Member 'BPI_ApplySettings_C_Apply_Settings::FOV' has a wrong offset!");

}
