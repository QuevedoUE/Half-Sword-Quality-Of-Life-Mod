#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: EngineUserSettings

#include "Basic.hpp"

#include "EngineUserSettings_classes.hpp"
#include "EngineUserSettings_parameters.hpp"


namespace SDK
{

// Function EngineUserSettings.EngineUserSettingsBPLibrary.GetCurrentFeatureLevel
// (Final, Native, Static, Public, BlueprintCallable, BlueprintPure)
// Parameters:
// EShaderFormat                           ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

EShaderFormat UEngineUserSettingsBPLibrary::GetCurrentFeatureLevel()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("EngineUserSettingsBPLibrary", "GetCurrentFeatureLevel");

	Params::EngineUserSettingsBPLibrary_GetCurrentFeatureLevel Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function EngineUserSettings.EngineUserSettingsBPLibrary.GetCurrentRHI
// (Final, Native, Static, Public, BlueprintCallable, BlueprintPure)
// Parameters:
// EGraphicsRHI                            ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

EGraphicsRHI UEngineUserSettingsBPLibrary::GetCurrentRHI()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("EngineUserSettingsBPLibrary", "GetCurrentRHI");

	Params::EngineUserSettingsBPLibrary_GetCurrentRHI Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function EngineUserSettings.EngineUserSettingsBPLibrary.GetMaxFeatureLevel
// (Final, Native, Static, Public, BlueprintCallable, BlueprintPure)
// Parameters:
// EShaderFormat                           ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

EShaderFormat UEngineUserSettingsBPLibrary::GetMaxFeatureLevel()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("EngineUserSettingsBPLibrary", "GetMaxFeatureLevel");

	Params::EngineUserSettingsBPLibrary_GetMaxFeatureLevel Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function EngineUserSettings.EngineUserSettingsBPLibrary.GetPreferredFeatureLevel
// (Final, Native, Static, Public, BlueprintCallable, BlueprintPure)
// Parameters:
// EShaderFormat                           ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

EShaderFormat UEngineUserSettingsBPLibrary::GetPreferredFeatureLevel()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("EngineUserSettingsBPLibrary", "GetPreferredFeatureLevel");

	Params::EngineUserSettingsBPLibrary_GetPreferredFeatureLevel Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function EngineUserSettings.EngineUserSettingsBPLibrary.GetPreferredRHI
// (Final, Native, Static, Public, BlueprintCallable, BlueprintPure)
// Parameters:
// EGraphicsRHI                            ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

EGraphicsRHI UEngineUserSettingsBPLibrary::GetPreferredRHI()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("EngineUserSettingsBPLibrary", "GetPreferredRHI");

	Params::EngineUserSettingsBPLibrary_GetPreferredRHI Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function EngineUserSettings.EngineUserSettingsBPLibrary.SetGameUserSettingsIniValue
// (Final, Native, Static, Public, BlueprintCallable)
// Parameters:
// class FString                           Section                                                (Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class FString                           Key                                                    (Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class FString                           Value                                                  (Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UEngineUserSettingsBPLibrary::SetGameUserSettingsIniValue(const class FString& Section, const class FString& Key, const class FString& Value)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("EngineUserSettingsBPLibrary", "SetGameUserSettingsIniValue");

	Params::EngineUserSettingsBPLibrary_SetGameUserSettingsIniValue Parms{};

	Parms.Section = std::move(Section);
	Parms.Key = std::move(Key);
	Parms.Value = std::move(Value);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function EngineUserSettings.EngineUserSettingsBPLibrary.SetPreferredFeatureLevel
// (Final, Native, Static, Public, BlueprintCallable)
// Parameters:
// EShaderFormat                           ShaderFormat                                           (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UEngineUserSettingsBPLibrary::SetPreferredFeatureLevel(EShaderFormat ShaderFormat)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("EngineUserSettingsBPLibrary", "SetPreferredFeatureLevel");

	Params::EngineUserSettingsBPLibrary_SetPreferredFeatureLevel Parms{};

	Parms.ShaderFormat = ShaderFormat;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function EngineUserSettings.EngineUserSettingsBPLibrary.SetPreferredRHI
// (Final, Native, Static, Public, BlueprintCallable)
// Parameters:
// EGraphicsRHI                            GraphicsRHI                                            (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UEngineUserSettingsBPLibrary::SetPreferredRHI(EGraphicsRHI GraphicsRHI)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("EngineUserSettingsBPLibrary", "SetPreferredRHI");

	Params::EngineUserSettingsBPLibrary_SetPreferredRHI Parms{};

	Parms.GraphicsRHI = GraphicsRHI;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}

}
