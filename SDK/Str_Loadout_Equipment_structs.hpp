#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Str_Loadout_Equipment

#include "Basic.hpp"

#include "Str_Loadout_Weapons_structs.hpp"
#include "Str_Loadout_Armor_structs.hpp"


namespace SDK
{

// UserDefinedStruct Str_Loadout_Equipment.Str_Loadout_Equipment
// 0x08A0 (0x08A0 - 0x0000)
struct FStr_Loadout_Equipment final
{
public:
	struct FStr_Loadout_Weapons                   Weapons_83_06F076E247B54D0D9942B383323C1968;       // 0x0000(0x0850)(Edit, BlueprintVisible, HasGetValueTypeHash)
	struct FStr_Loadout_Armor                     Armor_84_A1BA4DD44FD262BCA53B9DACF03CDF04;         // 0x0850(0x0050)(Edit, BlueprintVisible, HasGetValueTypeHash)
};
static_assert(alignof(FStr_Loadout_Equipment) == 0x000008, "Wrong alignment on FStr_Loadout_Equipment");
static_assert(sizeof(FStr_Loadout_Equipment) == 0x0008A0, "Wrong size on FStr_Loadout_Equipment");
static_assert(offsetof(FStr_Loadout_Equipment, Weapons_83_06F076E247B54D0D9942B383323C1968) == 0x000000, "Member 'FStr_Loadout_Equipment::Weapons_83_06F076E247B54D0D9942B383323C1968' has a wrong offset!");
static_assert(offsetof(FStr_Loadout_Equipment, Armor_84_A1BA4DD44FD262BCA53B9DACF03CDF04) == 0x000850, "Member 'FStr_Loadout_Equipment::Armor_84_A1BA4DD44FD262BCA53B9DACF03CDF04' has a wrong offset!");

}
