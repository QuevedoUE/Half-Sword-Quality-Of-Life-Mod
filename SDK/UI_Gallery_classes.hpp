#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: UI_Gallery

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "S_PhotosData_structs.hpp"
#include "UMG_structs.hpp"
#include "UMG_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass UI_Gallery.UI_Gallery_C
// 0x01F0 (0x04D0 - 0x02E0)
class UUI_Gallery_C final : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x02E0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       OpeningNotification;                               // 0x02E8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UCanvasPanel*                           AlbumMinusCanvasPanel;                             // 0x02F0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBackgroundBlur*                        BackgroundBlur;                                    // 0x02F8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBorder*                                BlackBackground;                                   // 0x0300(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UButton*                                btnFullscreen;                                     // 0x0308(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBorder*                                ButtonsMinusBorder_2;                              // 0x0310(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBorder*                                ButtonsMinusBottom;                                // 0x0318(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBorder*                                ButtonsMinusTop;                                   // 0x0320(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCanvasPanel*                           ButtonsPanel;                                      // 0x0328(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UUI_CommandButton_C*                    Command_BackFullScreen;                            // 0x0330(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UUI_CommandButton_C*                    Command_Close;                                     // 0x0338(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UUI_CommandButton_C*                    Command_Delete;                                    // 0x0340(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UUI_CommandButton_C*                    Command_Fullscreen_Next;                           // 0x0348(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UUI_CommandButton_C*                    Command_Fullscreen_Previous;                       // 0x0350(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UUI_CommandButton_C*                    Command_Next;                                      // 0x0358(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UUI_CommandButton_C*                    Command_PhotoMode;                                 // 0x0360(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UUI_CommandButton_C*                    Command_Previous;                                  // 0x0368(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UUI_CommandButton_C*                    Command_Select;                                    // 0x0370(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UUI_CommandButton_C*                    Command_ShowHideMouseFullScreen;                   // 0x0378(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UUI_CommandButton_C*                    Command_ShowMouse;                                 // 0x0380(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UUI_CommandButton_C*                    CommandButton_OpenPhotoModeFullscreen;             // 0x0388(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 FadeImage;                                         // 0x0390(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCanvasPanel*                           FullscreenMinusPanel;                              // 0x0398(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 FullscreenImage;                                   // 0x03A0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCanvasPanel*                           GalleryMinusPanel;                                 // 0x03A8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image_19;                                          // 0x03B0(0x0008)(ExportObject, ZeroConstructor, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetSwitcher*                        MainPanelSwitcher;                                 // 0x03B8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UHorizontalBox*                         NextPageMinusHorizontalBox;                        // 0x03C0(0x0008)(ExportObject, ZeroConstructor, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UButton*                                NextPageButton;                                    // 0x03C8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UHorizontalBox*                         PagesMinusHorizontalBox;                           // 0x03D0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UScrollBox*                             PagesScrollBox;                                    // 0x03D8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UHorizontalBox*                         PreviousPageMinusHorizontalBox;                    // 0x03E0(0x0008)(ExportObject, ZeroConstructor, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UButton*                                PreviousPageButton;                                // 0x03E8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UScaleBox*                              ScaleBox_0;                                        // 0x03F0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USpacer*                                Spacer_11;                                         // 0x03F8(0x0008)(ExportObject, ZeroConstructor, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USpacer*                                Spacer_13;                                         // 0x0400(0x0008)(ExportObject, ZeroConstructor, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USpacer*                                Spacer_14;                                         // 0x0408(0x0008)(ExportObject, ZeroConstructor, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTextBlock*                             TextBlock_1;                                       // 0x0410(0x0008)(ExportObject, ZeroConstructor, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UVerticalBox*                           VerticalBox;                                       // 0x0418(0x0008)(ExportObject, ZeroConstructor, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UVerticalBox*                           VerticalBox_241;                                   // 0x0420(0x0008)(ExportObject, ZeroConstructor, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	bool                                          ShowingMouse_;                                     // 0x0428(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ShowMouseCursorOption_;                            // 0x0429(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	bool                                          InFullscreen_;                                     // 0x042A(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_42B[0x5];                                      // 0x042B(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	class UBPC_PhotoMode_C*                       PhotoModeComponent;                                // 0x0430(0x0008)(Edit, BlueprintVisible, ZeroConstructor, InstancedReference, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	class UWidget*                                LastValidFocusedElement;                           // 0x0438(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, NoDestructor, HasGetValueTypeHash)
	TArray<struct FS_PhotosData>                  FullPhotosData;                                    // 0x0440(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	class UTexture2D*                             Fullscreen2DTexture;                               // 0x0450(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	TArray<class UUI_PhotoPage_C*>                Pages;                                             // 0x0458(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, ContainsInstancedReference)
	TArray<class UUI_PhotoThumbnail_C*>           PhotosThumbs;                                      // 0x0468(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, ContainsInstancedReference)
	int32                                         PhotosPerPage;                                     // 0x0478(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CurrentPage;                                       // 0x047C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         PageOffsetToLoad;                                  // 0x0480(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         TotalPhotos;                                       // 0x0484(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CanFreeMemory_;                                    // 0x0488(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_489[0x7];                                      // 0x0489(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FS_PhotosData                          CurrentDataInFullscreen;                           // 0x0490(0x0030)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	class UWidget*                                LastValidThumb;                                    // 0x04C0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, NoDestructor, HasGetValueTypeHash)
	bool                                          GamepadInput;                                      // 0x04C8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          KeyboardInput;                                     // 0x04C9(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CanDelete;                                         // 0x04CA(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DeleteFunction;                                    // 0x04CB(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void BndEvt__Command_BackFullScreen_K2Node_ComponentBoundEvent_4_OnPressed__DelegateSignature();
	void BndEvt__Command_Close_K2Node_ComponentBoundEvent_1_OnPressed__DelegateSignature();
	void BndEvt__Command_Fullscreen_Next_K2Node_ComponentBoundEvent_3_OnPressed__DelegateSignature();
	void BndEvt__Command_Fullscreen_Previous_K2Node_ComponentBoundEvent_2_OnPressed__DelegateSignature();
	void BndEvt__Command_Next_K2Node_ComponentBoundEvent_1_OnPressed__DelegateSignature();
	void BndEvt__Command_PhotoMode_K2Node_ComponentBoundEvent_0_OnPressed__DelegateSignature();
	void BndEvt__Command_Previous_K2Node_ComponentBoundEvent_0_OnPressed__DelegateSignature();
	void BndEvt__Command_Select_K2Node_ComponentBoundEvent_3_OnPressed__DelegateSignature();
	void BndEvt__Command_ShowMouse_K2Node_ComponentBoundEvent_2_OnPressed__DelegateSignature();
	void BndEvt__CommandButton_OpenPhotoModeFullscreen_K2Node_ComponentBoundEvent_5_OnPressed__DelegateSignature();
	void BndEvt__NextPageButton_K2Node_ComponentBoundEvent_0_OnButtonClickedEvent__DelegateSignature();
	void BndEvt__PreviousPageButton_K2Node_ComponentBoundEvent_1_OnButtonClickedEvent__DelegateSignature();
	void CloseFullscreen();
	void Construct();
	void CreatePages();
	void DeletePhoto();
	void Destruct();
	void ExecuteUbergraph_UI_Gallery(int32 EntryPoint);
	void Get_Any_Key(const struct FKey& Key);
	void LoadNextPrevPage(int32 NewPageIndex, bool PrevFocusOnTheFirstPhoto);
	ESlateVisibility Next_Page_Button_Visibility();
	void NextPage(bool NextFocusOnTheFirstPhoto);
	struct FEventReply OnKeyDown(const struct FGeometry& MyGeometry, const struct FKeyEvent& InKeyEvent);
	struct FEventReply OnMouseButtonDown(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	void OnMouseEnter(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	void OnMouseLeave(const struct FPointerEvent& MouseEvent);
	struct FEventReply OnMouseMove(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	struct FEventReply OnMouseWheel(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	void OnRemovedFromFocusPath(const struct FFocusEvent& InFocusEvent);
	void PreConstruct(bool IsDesignTime);
	ESlateVisibility Previous_Page_Button_Visibility();
	void PreviousPage(bool PrevFocusOnTheFirstPhoto);
	void ResetFocus();
	void ResetKeyboardIcons();
	void ResetShowMouseCursor();
	void SendPhotoData(const struct FS_PhotosData& PhotoData);
	void SetIcons(int32 Param_Index);
	ESlateVisibility ShowHideDeleteOption();
	class FText ShowHideMouseTxt();
	ESlateVisibility ShowHideMouseVisibility();
	void ShowMouse();
	ESlateVisibility SwapUpDownLeftRightVisibility();
	void TabToOpen(int32 TabIndex, class UUI_TabButton_C* CommonButtonPressed);
	void Tick(const struct FGeometry& MyGeometry, float InDeltaTime);
	void UpdatePhotosData();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"UI_Gallery_C">();
	}
	static class UUI_Gallery_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUI_Gallery_C>();
	}
};
static_assert(alignof(UUI_Gallery_C) == 0x000008, "Wrong alignment on UUI_Gallery_C");
static_assert(sizeof(UUI_Gallery_C) == 0x0004D0, "Wrong size on UUI_Gallery_C");
static_assert(offsetof(UUI_Gallery_C, UberGraphFrame) == 0x0002E0, "Member 'UUI_Gallery_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, OpeningNotification) == 0x0002E8, "Member 'UUI_Gallery_C::OpeningNotification' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, AlbumMinusCanvasPanel) == 0x0002F0, "Member 'UUI_Gallery_C::AlbumMinusCanvasPanel' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, BackgroundBlur) == 0x0002F8, "Member 'UUI_Gallery_C::BackgroundBlur' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, BlackBackground) == 0x000300, "Member 'UUI_Gallery_C::BlackBackground' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, btnFullscreen) == 0x000308, "Member 'UUI_Gallery_C::btnFullscreen' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, ButtonsMinusBorder_2) == 0x000310, "Member 'UUI_Gallery_C::ButtonsMinusBorder_2' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, ButtonsMinusBottom) == 0x000318, "Member 'UUI_Gallery_C::ButtonsMinusBottom' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, ButtonsMinusTop) == 0x000320, "Member 'UUI_Gallery_C::ButtonsMinusTop' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, ButtonsPanel) == 0x000328, "Member 'UUI_Gallery_C::ButtonsPanel' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, Command_BackFullScreen) == 0x000330, "Member 'UUI_Gallery_C::Command_BackFullScreen' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, Command_Close) == 0x000338, "Member 'UUI_Gallery_C::Command_Close' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, Command_Delete) == 0x000340, "Member 'UUI_Gallery_C::Command_Delete' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, Command_Fullscreen_Next) == 0x000348, "Member 'UUI_Gallery_C::Command_Fullscreen_Next' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, Command_Fullscreen_Previous) == 0x000350, "Member 'UUI_Gallery_C::Command_Fullscreen_Previous' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, Command_Next) == 0x000358, "Member 'UUI_Gallery_C::Command_Next' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, Command_PhotoMode) == 0x000360, "Member 'UUI_Gallery_C::Command_PhotoMode' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, Command_Previous) == 0x000368, "Member 'UUI_Gallery_C::Command_Previous' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, Command_Select) == 0x000370, "Member 'UUI_Gallery_C::Command_Select' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, Command_ShowHideMouseFullScreen) == 0x000378, "Member 'UUI_Gallery_C::Command_ShowHideMouseFullScreen' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, Command_ShowMouse) == 0x000380, "Member 'UUI_Gallery_C::Command_ShowMouse' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, CommandButton_OpenPhotoModeFullscreen) == 0x000388, "Member 'UUI_Gallery_C::CommandButton_OpenPhotoModeFullscreen' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, FadeImage) == 0x000390, "Member 'UUI_Gallery_C::FadeImage' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, FullscreenMinusPanel) == 0x000398, "Member 'UUI_Gallery_C::FullscreenMinusPanel' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, FullscreenImage) == 0x0003A0, "Member 'UUI_Gallery_C::FullscreenImage' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, GalleryMinusPanel) == 0x0003A8, "Member 'UUI_Gallery_C::GalleryMinusPanel' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, Image_19) == 0x0003B0, "Member 'UUI_Gallery_C::Image_19' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, MainPanelSwitcher) == 0x0003B8, "Member 'UUI_Gallery_C::MainPanelSwitcher' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, NextPageMinusHorizontalBox) == 0x0003C0, "Member 'UUI_Gallery_C::NextPageMinusHorizontalBox' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, NextPageButton) == 0x0003C8, "Member 'UUI_Gallery_C::NextPageButton' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, PagesMinusHorizontalBox) == 0x0003D0, "Member 'UUI_Gallery_C::PagesMinusHorizontalBox' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, PagesScrollBox) == 0x0003D8, "Member 'UUI_Gallery_C::PagesScrollBox' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, PreviousPageMinusHorizontalBox) == 0x0003E0, "Member 'UUI_Gallery_C::PreviousPageMinusHorizontalBox' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, PreviousPageButton) == 0x0003E8, "Member 'UUI_Gallery_C::PreviousPageButton' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, ScaleBox_0) == 0x0003F0, "Member 'UUI_Gallery_C::ScaleBox_0' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, Spacer_11) == 0x0003F8, "Member 'UUI_Gallery_C::Spacer_11' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, Spacer_13) == 0x000400, "Member 'UUI_Gallery_C::Spacer_13' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, Spacer_14) == 0x000408, "Member 'UUI_Gallery_C::Spacer_14' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, TextBlock_1) == 0x000410, "Member 'UUI_Gallery_C::TextBlock_1' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, VerticalBox) == 0x000418, "Member 'UUI_Gallery_C::VerticalBox' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, VerticalBox_241) == 0x000420, "Member 'UUI_Gallery_C::VerticalBox_241' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, ShowingMouse_) == 0x000428, "Member 'UUI_Gallery_C::ShowingMouse_' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, ShowMouseCursorOption_) == 0x000429, "Member 'UUI_Gallery_C::ShowMouseCursorOption_' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, InFullscreen_) == 0x00042A, "Member 'UUI_Gallery_C::InFullscreen_' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, PhotoModeComponent) == 0x000430, "Member 'UUI_Gallery_C::PhotoModeComponent' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, LastValidFocusedElement) == 0x000438, "Member 'UUI_Gallery_C::LastValidFocusedElement' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, FullPhotosData) == 0x000440, "Member 'UUI_Gallery_C::FullPhotosData' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, Fullscreen2DTexture) == 0x000450, "Member 'UUI_Gallery_C::Fullscreen2DTexture' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, Pages) == 0x000458, "Member 'UUI_Gallery_C::Pages' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, PhotosThumbs) == 0x000468, "Member 'UUI_Gallery_C::PhotosThumbs' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, PhotosPerPage) == 0x000478, "Member 'UUI_Gallery_C::PhotosPerPage' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, CurrentPage) == 0x00047C, "Member 'UUI_Gallery_C::CurrentPage' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, PageOffsetToLoad) == 0x000480, "Member 'UUI_Gallery_C::PageOffsetToLoad' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, TotalPhotos) == 0x000484, "Member 'UUI_Gallery_C::TotalPhotos' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, CanFreeMemory_) == 0x000488, "Member 'UUI_Gallery_C::CanFreeMemory_' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, CurrentDataInFullscreen) == 0x000490, "Member 'UUI_Gallery_C::CurrentDataInFullscreen' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, LastValidThumb) == 0x0004C0, "Member 'UUI_Gallery_C::LastValidThumb' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, GamepadInput) == 0x0004C8, "Member 'UUI_Gallery_C::GamepadInput' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, KeyboardInput) == 0x0004C9, "Member 'UUI_Gallery_C::KeyboardInput' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, CanDelete) == 0x0004CA, "Member 'UUI_Gallery_C::CanDelete' has a wrong offset!");
static_assert(offsetof(UUI_Gallery_C, DeleteFunction) == 0x0004CB, "Member 'UUI_Gallery_C::DeleteFunction' has a wrong offset!");

}
