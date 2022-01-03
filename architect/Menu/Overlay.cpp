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
	imguiIO.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Verdana.ttf", 13.0f, &cfg);

}
void COverlay::Render()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	// draw stuff here
	reinterpret_cast<CArchitectImGuiCustomDrawList*>(ImGui::GetBackgroundDrawList())->AddOutlinedText(ImVec2(), ImColor(255, 255, 255), "Hello world!");

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