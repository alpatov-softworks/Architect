#pragma once
#include <Windows.h>
#include <d3d11.h>
#include "../imgui/imgui_impl_dx11.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_win32.h"
#include "../imgui/misc/freetype/imgui_freetype.h"
#include "../imgui/architect/ArchitectImGuiDrawList.h"
#include "../Hack/ESP/CEspDrawer.h"
#include "../Globals/GlobalVars.h"


class COverlay
{
public:
	COverlay(IDXGISwapChain* pSwapChain);
	void Render();
	void Detach();
private:
	ID3D11Device*        m_pDevice        = nullptr;
	ID3D11DeviceContext* m_pDeviceContext = nullptr;
};