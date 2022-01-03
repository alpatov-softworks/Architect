#pragma once
#include <Windows.h>
#include <d3d11.h>

namespace Hooks
{
	inline PVOID originalPresentAddr = nullptr;

	void Attach();
	void Detach();
	HRESULT __fastcall hPresent(IDXGISwapChain* pChain, UINT SyncInterval, UINT Flags);

}