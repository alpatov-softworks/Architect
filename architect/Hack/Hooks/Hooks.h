#pragma once
#include <Windows.h>
#include <d3d11.h>
#include "MinHook.h"
#include "../../Menu/Overlay.h"
#include "../../ASDK/CLocalPlayer.h"

namespace Hooks
{
	inline PVOID     originalPresentAddr = nullptr;
	inline COverlay* pOverlay            = nullptr;
	inline PVOID     originalUpdateViewAnglesAddr = nullptr;
	inline WNDPROC OriginalWndProcHandler;
	void Attach();
	void Detach();
	HRESULT __fastcall hPresent(IDXGISwapChain* pChain, UINT SyncInterval, UINT Flags);
	__int64 __fastcall hUpdateLocalViewAngles(__int64 a1, CLocalPlayer* pLocalPlayer);
	LRESULT CALLBACK hWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

}