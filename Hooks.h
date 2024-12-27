#pragma once

#include <iostream>
#include "MinHook.h"
#include "SDK.hpp"
#include "Actions.h"
#include "GameInstances.h"

using namespace SDK;

void (*ProcessEvent)(UObject*, UFunction*, void*);

inline static void* ProcessEventDetour(UObject* pObj, UFunction* pFunc, void* pParams) {
    // std::string nObj = pObj->GetName();
    // std::string nFunc = pFunc->GetName();

    if (pFunc->GetName() == "Camera Shake Timeline__UpdateFunc" && Actions::bInfiniteStaminaEnabled)
        GameInstances::GetPawn()->Stamina = 100;
    ProcessEvent(pObj, pFunc, pParams);
}

namespace Hooks
{

    inline void Init() {
        if (MH_Initialize() != MH_OK) {
            std::cerr << "Error initializing MinHook" << std::endl;
            return;
        }
        UObject* pObject = UObject::GObjects->GetByIndex(0);

        if (!pObject) {
            std::cerr << "Could not get an instance of UObject." << std::endl;
            return;
        }

        uintptr_t* vtable = *reinterpret_cast<uintptr_t**>(pObject);
        uintptr_t ProcessEventAddress = vtable[Offsets::ProcessEventIdx];

        if (MH_CreateHook(reinterpret_cast<LPVOID>(ProcessEventAddress), reinterpret_cast<LPVOID>(&ProcessEventDetour), reinterpret_cast<LPVOID*>(&ProcessEvent)) != MH_OK) {
            std::cerr << "Error creating hook for ProcessEvent" << std::endl;
            return;
        }

        if (MH_EnableHook(reinterpret_cast<LPVOID>(ProcessEventAddress)) != MH_OK) {
            std::cerr << "Error enabling hook for ProcessEvent" << std::endl;
            return;
        }

        std::cout << "Hooks initialized successfully!" << std::endl;
    }
}