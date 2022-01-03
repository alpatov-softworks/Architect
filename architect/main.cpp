#include <Windows.h>


DWORD WINAPI InitCheat(HMODULE hModule)
{

    FreeLibraryAndExitThread(hModule, 0);
}


BOOL APIENTRY DllMain( HMODULE hModule,DWORD  callReason, LPVOID lpReserved)
{
    if (callReason == DLL_PROCESS_ATTACH)
    {

    }
    return TRUE;
}

