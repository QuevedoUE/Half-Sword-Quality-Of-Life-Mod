#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: EngineUserSettings

#include "Basic.hpp"

#include "EngineUserSettings_structs.hpp"


namespace SDK::Params
{

// Function EngineUserSettings.EngineUserSettingsBPLibrary.GetCurrentFeatureLevel
// 0x0001 (0x0001 - 0x0000)
struct EngineUserSettingsBPLibrary_GetCurrentFeatureLevel final
{
public:
	EShaderFormat                                 ReturnValue;                                       // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(EngineUserSettingsBPLibrary_GetCurrentFeatureLevel) == 0x000001, "Wrong alignment on EngineUserSettingsBPLibrary_GetCurrentFeatureLevel");
static_assert(sizeof(EngineUserSettingsBPLibrary_GetCurrentFeatureLevel) == 0x000001, "Wrong size on EngineUserSettingsBPLibrary_GetCurrentFeatureLevel");
static_assert(offsetof(EngineUserSettingsBPLibrary_GetCurrentFeatureLevel, ReturnValue) == 0x000000, "Member 'EngineUserSettingsBPLibrary_GetCurrentFeatureLevel::ReturnValue' has a wrong offset!");

// Function EngineUserSettings.EngineUserSettingsBPLibrary.GetCurrentRHI
// 0x0001 (0x0001 - 0x0000)
struct EngineUserSettingsBPLibrary_GetCurrentRHI final
{
public:
	EGraphicsRHI                                  ReturnValue;                                       // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(EngineUserSettingsBPLibrary_GetCurrentRHI) == 0x000001, "Wrong alignment on EngineUserSettingsBPLibrary_GetCurrentRHI");
static_assert(sizeof(EngineUserSettingsBPLibrary_GetCurrentRHI) == 0x000001, "Wrong size on EngineUserSettingsBPLibrary_GetCurrentRHI");
static_assert(offsetof(EngineUserSettingsBPLibrary_GetCurrentRHI, ReturnValue) == 0x000000, "Member 'EngineUserSettingsBPLibrary_GetCurrentRHI::ReturnValue' has a wrong offset!");

// Function EngineUserSettings.EngineUserSettingsBPLibrary.GetMaxFeatureLevel
// 0x0001 (0x0001 - 0x0000)
struct EngineUserSettingsBPLibrary_GetMaxFeatureLevel final
{
public:
	EShaderFormat                                 ReturnValue;                                       // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(EngineUserSettingsBPLibrary_GetMaxFeatureLevel) == 0x000001, "Wrong alignment on EngineUserSettingsBPLibrary_GetMaxFeatureLevel");
static_assert(sizeof(EngineUserSettingsBPLibrary_GetMaxFeatureLevel) == 0x000001, "Wrong size on EngineUserSettingsBPLibrary_GetMaxFeatureLevel");
static_assert(offsetof(EngineUserSettingsBPLibrary_GetMaxFeatureLevel, ReturnValue) == 0x000000, "Member 'EngineUserSettingsBPLibrary_GetMaxFeatureLevel::ReturnValue' has a wrong offset!");

// Function EngineUserSettings.EngineUserSettingsBPLibrary.GetPreferredFeatureLevel
// 0x0001 (0x0001 - 0x0000)
struct EngineUserSettingsBPLibrary_GetPreferredFeatureLevel final
{
public:
	EShaderFormat                                 ReturnValue;                                       // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(EngineUserSettingsBPLibrary_GetPreferredFeatureLevel) == 0x000001, "Wrong alignment on EngineUserSettingsBPLibrary_GetPreferredFeatureLevel");
static_assert(sizeof(EngineUserSettingsBPLibrary_GetPreferredFeatureLevel) == 0x000001, "Wrong size on EngineUserSettingsBPLibrary_GetPreferredFeatureLevel");
static_assert(offsetof(EngineUserSettingsBPLibrary_GetPreferredFeatureLevel, ReturnValue) == 0x000000, "Member 'EngineUserSettingsBPLibrary_GetPreferredFeatureLevel::ReturnValue' has a wrong offset!");

// Function EngineUserSettings.EngineUserSettingsBPLibrary.GetPreferredRHI
// 0x0001 (0x0001 - 0x0000)
struct EngineUserSettingsBPLibrary_GetPreferredRHI final
{
public:
	EGraphicsRHI                                  ReturnValue;                                       // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(EngineUserSettingsBPLibrary_GetPreferredRHI) == 0x000001, "Wrong alignment on EngineUserSettingsBPLibrary_GetPreferredRHI");
static_assert(sizeof(EngineUserSettingsBPLibrary_GetPreferredRHI) == 0x000001, "Wrong size on EngineUserSettingsBPLibrary_GetPreferredRHI");
static_assert(offsetof(EngineUserSettingsBPLibrary_GetPreferredRHI, ReturnValue) == 0x000000, "Member 'EngineUserSettingsBPLibrary_GetPreferredRHI::ReturnValue' has a wrong offset!");

// Function EngineUserSettings.EngineUserSettingsBPLibrary.SetGameUserSettingsIniValue
// 0x0030 (0x0030 - 0x0000)
struct EngineUserSettingsBPLibrary_SetGameUserSettingsIniValue final
{
public:
	class FString                                 Section;                                           // 0x0000(0x0010)(Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 Key;                                               // 0x0010(0x0010)(Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 Value;                                             // 0x0020(0x0010)(Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(EngineUserSettingsBPLibrary_SetGameUserSettingsIniValue) == 0x000008, "Wrong alignment on EngineUserSettingsBPLibrary_SetGameUserSettingsIniValue");
static_assert(sizeof(EngineUserSettingsBPLibrary_SetGameUserSettingsIniValue) == 0x000030, "Wrong size on EngineUserSettingsBPLibrary_SetGameUserSettingsIniValue");
static_assert(offsetof(EngineUserSettingsBPLibrary_SetGameUserSettingsIniValue, Section) == 0x000000, "Member 'EngineUserSettingsBPLibrary_SetGameUserSettingsIniValue::Section' has a wrong offset!");
static_assert(offsetof(EngineUserSettingsBPLibrary_SetGameUserSettingsIniValue, Key) == 0x000010, "Member 'EngineUserSettingsBPLibrary_SetGameUserSettingsIniValue::Key' has a wrong offset!");
static_assert(offsetof(EngineUserSettingsBPLibrary_SetGameUserSettingsIniValue, Value) == 0x000020, "Member 'EngineUserSettingsBPLibrary_SetGameUserSettingsIniValue::Value' has a wrong offset!");

// Function EngineUserSettings.EngineUserSettingsBPLibrary.SetPreferredFeatureLevel
// 0x0001 (0x0001 - 0x0000)
struct EngineUserSettingsBPLibrary_SetPreferredFeatureLevel final
{
public:
	EShaderFormat                                 ShaderFormat;                                      // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(EngineUserSettingsBPLibrary_SetPreferredFeatureLevel) == 0x000001, "Wrong alignment on EngineUserSettingsBPLibrary_SetPreferredFeatureLevel");
static_assert(sizeof(EngineUserSettingsBPLibrary_SetPreferredFeatureLevel) == 0x000001, "Wrong size on EngineUserSettingsBPLibrary_SetPreferredFeatureLevel");
static_assert(offsetof(EngineUserSettingsBPLibrary_SetPreferredFeatureLevel, ShaderFormat) == 0x000000, "Member 'EngineUserSettingsBPLibrary_SetPreferredFeatureLevel::ShaderFormat' has a wrong offset!");

// Function EngineUserSettings.EngineUserSettingsBPLibrary.SetPreferredRHI
// 0x0001 (0x0001 - 0x0000)
struct EngineUserSettingsBPLibrary_SetPreferredRHI final
{
public:
	EGraphicsRHI                                  GraphicsRHI;                                       // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(EngineUserSettingsBPLibrary_SetPreferredRHI) == 0x000001, "Wrong alignment on EngineUserSettingsBPLibrary_SetPreferredRHI");
static_assert(sizeof(EngineUserSettingsBPLibrary_SetPreferredRHI) == 0x000001, "Wrong size on EngineUserSettingsBPLibrary_SetPreferredRHI");
static_assert(offsetof(EngineUserSettingsBPLibrary_SetPreferredRHI, GraphicsRHI) == 0x000000, "Member 'EngineUserSettingsBPLibrary_SetPreferredRHI::GraphicsRHI' has a wrong offset!");

}
