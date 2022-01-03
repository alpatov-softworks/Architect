#pragma once
#include <Windows.h>
#include <d3d11.h>
#include "MinHook.h"
#include "../../Menu/Overlay.h"
namespace Hooks
{
	inline PVOID     originalPresentAddr = nullptr;
	inline COverlay* pOverlay            = nullptr;

	void Attach();
	void Detach();
	HRESULT __fastcall hPresent(IDXGISwapChain* pChain, UINT SyncInterval, UINT Flags);

}