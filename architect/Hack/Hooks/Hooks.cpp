#include "Hooks.h"
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void Hooks::Attach()
{
    MH_Initialize();
    uintptr_t present_addr = (uintptr_t)GetModuleHandle("dxgi.dll") + 0x2A40;
    uintptr_t updatePlayerViewAngesAddr = (uintptr_t)GetModuleHandle(NULL) + 0x858170;

    MH_Initialize();

    MH_CreateHook((LPVOID)present_addr, &hPresent, &Hooks::originalPresentAddr);
    MH_CreateHook((LPVOID)updatePlayerViewAngesAddr, &hUpdateLocalViewAngles, &Hooks::originalUpdateViewAnglesAddr);
    MH_EnableHook(MH_ALL_HOOKS);
    OriginalWndProcHandler = (WNDPROC)SetWindowLongPtr(FindWindow(NULL, "Apex Legends"), GWLP_WNDPROC, (LONG_PTR)hWndProc);
}
void Hooks::Detach()
{
    SetWindowLongPtr(FindWindowA(NULL, "Apex Legends"), GWLP_WNDPROC, (LONG_PTR)OriginalWndProcHandler);
    MH_DisableHook(MH_ALL_HOOKS);
    MH_RemoveHook(MH_ALL_HOOKS);
    MH_Uninitialize();
}
HRESULT __fastcall Hooks::hPresent(IDXGISwapChain* pChain, UINT SyncInterval, UINT Flags)
{
    // init Overlay if function detour was called first time
    if (pOverlay == nullptr)
    {
        pOverlay = new COverlay(pChain);
    }
    pOverlay->Render();
    typedef HRESULT(__fastcall* tPresent)(IDXGISwapChain*, UINT, UINT);
    return reinterpret_cast<tPresent>(Hooks::originalPresentAddr)(pChain, SyncInterval, Flags);

}
//Updating local player view angles
__int64 __fastcall Hooks::hUpdateLocalViewAngles(__int64 a1, CLocalPlayer* pLocalPlayer)
{
    
    GlobalVars::pLocalViewAngles = &pLocalPlayer->m_vecViewAngles;

    if (GetAsyncKeyState(VK_LBUTTON))
    {
        for (auto pEnt : GlobalVars::entityList)
        {
            if (pEnt->m_iHealth <= 0)
                continue;
            pLocalPlayer->AimAt(pEnt->m_vecCameraOrigin);
        }
    }

    typedef __int64(__fastcall* tUpdateViewAngles)(__int64 a1, CLocalPlayer* pLocalPlayer);
    return reinterpret_cast<tUpdateViewAngles>(Hooks::originalUpdateViewAnglesAddr)(a1, pLocalPlayer);
}
LRESULT CALLBACK Hooks::hWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);

    return CallWindowProc(OriginalWndProcHandler, hWnd, uMsg, wParam, lParam);
}