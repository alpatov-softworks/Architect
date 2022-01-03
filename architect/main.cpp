#include <Windows.h>
#include "Hack/Hooks/Hooks.h"
#include "Threads/Threads.h"

DWORD WINAPI InitCheat(HMODULE hModule)
{
    Hooks::Attach();
    Threads cheatThreads;
    
    while (!GetAsyncKeyState(VK_END))
    {
        Sleep(100);
    }
    cheatThreads.KillAll();
    Hooks::Detach();
    Hooks::pOverlay->Detach();
    delete Hooks::pOverlay;
    FreeLibraryAndExitThread(hModule, 0);
}


BOOL APIENTRY DllMain( HMODULE hModule,DWORD  callReason, LPVOID lpReserved)
{
    if (callReason == DLL_PROCESS_ATTACH)
    {
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)InitCheat, hModule, 0, nullptr);
    }
    return TRUE;
}

