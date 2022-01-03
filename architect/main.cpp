#include <Windows.h>
#include "Hack/Hooks/Hooks.h"


DWORD WINAPI InitCheat(HMODULE hModule)
{

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

