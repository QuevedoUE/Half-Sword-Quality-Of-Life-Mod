#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Modular_PA_Head_SubModule_Maul

#include "Basic.hpp"

#include "Modular_PA_Head_SubModule_Master_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Modular_PA_Head_SubModule_Maul.Modular_PA_Head_SubModule_Maul_C
// 0x0018 (0x0500 - 0x04E8)
class AModular_PA_Head_SubModule_Maul_C final : public AModular_PA_Head_SubModule_Master_C
{
public:
	class USceneComponent*                        Tip3;                                              // 0x04E8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        Tip2;                                              // 0x04F0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        Tip1;                                              // 0x04F8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Modular_PA_Head_SubModule_Maul_C">();
	}
	static class AModular_PA_Head_SubModule_Maul_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AModular_PA_Head_SubModule_Maul_C>();
	}
};
static_assert(alignof(AModular_PA_Head_SubModule_Maul_C) == 0x000008, "Wrong alignment on AModular_PA_Head_SubModule_Maul_C");
static_assert(sizeof(AModular_PA_Head_SubModule_Maul_C) == 0x000500, "Wrong size on AModular_PA_Head_SubModule_Maul_C");
static_assert(offsetof(AModular_PA_Head_SubModule_Maul_C, Tip3) == 0x0004E8, "Member 'AModular_PA_Head_SubModule_Maul_C::Tip3' has a wrong offset!");
static_assert(offsetof(AModular_PA_Head_SubModule_Maul_C, Tip2) == 0x0004F0, "Member 'AModular_PA_Head_SubModule_Maul_C::Tip2' has a wrong offset!");
static_assert(offsetof(AModular_PA_Head_SubModule_Maul_C, Tip1) == 0x0004F8, "Member 'AModular_PA_Head_SubModule_Maul_C::Tip1' has a wrong offset!");

}
