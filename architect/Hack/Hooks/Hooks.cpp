#include "Hooks.h"

void Hooks::Attach()
{
    MH_Initialize();
    uintptr_t present_addr = (uintptr_t)GetModuleHandle("dxgi.dll") + 0x2A40;

    MH_Initialize();

    MH_CreateHook((LPVOID)present_addr, &hPresent, &Hooks::originalPresentAddr);
    MH_EnableHook(MH_ALL_HOOKS);
}
void Hooks::Detach()
{
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