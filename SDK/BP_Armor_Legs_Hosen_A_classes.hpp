#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_Armor_Legs_Hosen_A

#include "Basic.hpp"

#include "BP_Armor_Master_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_Armor_Legs_Hosen_A.BP_Armor_Legs_Hosen_A_C
// 0x0000 (0x07F0 - 0x07F0)
class ABP_Armor_Legs_Hosen_A_C final : public ABP_Armor_Master_C
{
public:
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_Armor_Legs_Hosen_A_C">();
	}
	static class ABP_Armor_Legs_Hosen_A_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_Armor_Legs_Hosen_A_C>();
	}
};
static_assert(alignof(ABP_Armor_Legs_Hosen_A_C) == 0x000010, "Wrong alignment on ABP_Armor_Legs_Hosen_A_C");
static_assert(sizeof(ABP_Armor_Legs_Hosen_A_C) == 0x0007F0, "Wrong size on ABP_Armor_Legs_Hosen_A_C");

}
