#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BPI_Data

#include "Basic.hpp"

#include "S_PhotosData_structs.hpp"


namespace SDK::Params
{

// Function BPI_Data.BPI_Data_C.SendPhotoData
// 0x0030 (0x0030 - 0x0000)
struct BPI_Data_C_SendPhotoData final
{
public:
	struct FS_PhotosData                          PhotoData;                                         // 0x0000(0x0030)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
};
static_assert(alignof(BPI_Data_C_SendPhotoData) == 0x000008, "Wrong alignment on BPI_Data_C_SendPhotoData");
static_assert(sizeof(BPI_Data_C_SendPhotoData) == 0x000030, "Wrong size on BPI_Data_C_SendPhotoData");
static_assert(offsetof(BPI_Data_C_SendPhotoData, PhotoData) == 0x000000, "Member 'BPI_Data_C_SendPhotoData::PhotoData' has a wrong offset!");

// Function BPI_Data.BPI_Data_C.TabToOpen
// 0x0010 (0x0010 - 0x0000)
struct BPI_Data_C_TabToOpen final
{
public:
	int32                                         TabIndex;                                          // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UUI_TabButton_C*                        CommonButtonPressed;                               // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(BPI_Data_C_TabToOpen) == 0x000008, "Wrong alignment on BPI_Data_C_TabToOpen");
static_assert(sizeof(BPI_Data_C_TabToOpen) == 0x000010, "Wrong size on BPI_Data_C_TabToOpen");
static_assert(offsetof(BPI_Data_C_TabToOpen, TabIndex) == 0x000000, "Member 'BPI_Data_C_TabToOpen::TabIndex' has a wrong offset!");
static_assert(offsetof(BPI_Data_C_TabToOpen, CommonButtonPressed) == 0x000008, "Member 'BPI_Data_C_TabToOpen::CommonButtonPressed' has a wrong offset!");

}
