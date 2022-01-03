#include "Overlay.h"

COverlay::COverlay(IDXGISwapChain* pSwapChain)
{
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	pSwapChain->GetDesc(&swapChainDesc);

	// Getting Device pointer and Context
	pSwapChain->GetDevice(__uuidof(ID3D11Device), (PVOID*)&m_pDevice);
	m_pDevice->GetImmediateContext(&m_pDeviceContext);

	ImGui::CreateContext();
	ImGui_ImplWin32_Init(swapChainDesc.OutputWindow);
	ImGui_ImplDX11_Init(m_pDevice, m_pDeviceContext);

	auto& imguiIO = ImGui::GetIO();
	imguiIO.ImeWindowHandle = swapChainDesc.OutputWindow;

	// Changing font to normal
	ImFontConfig cfg;
	cfg.FontBuilderFlags |= ImGuiFreeTypeBuilderFlags_Monochrome;
	imguiIO.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Verdana.ttf", 15.0f, &cfg);

}
void COverlay::Render()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();


	auto drawer =  CEspDrawer();
	auto draw_list = (CArchitectImGuiCustomDrawList*)ImGui::GetBackgroundDrawList();
	for (auto ent : GEnityList::list)
	{
		auto pos = drawer.WorldToScreen(ent->m_vecOrigin);
		if (pos.z > 0 and ent->m_iHealth > 0)
		{

			drawer.DrawBox(ent, ImColor(255, 255, 255), draw_list);

		}
	}
	draw_list->AddOutlinedText(ImVec2(), ImColor(255, 255, 255), "ARCHITECT BY LSS");

	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}
void COverlay::Detach()
{
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}