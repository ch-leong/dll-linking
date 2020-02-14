#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
#include "library.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

// We need this due to name mangling.
#ifdef __cplusplus
extern "C"
{
#endif

    void LIBRARY2_API Load()
    {
        std::cout << "Library2::Load()\n";
    }

#ifdef __cplusplus
}
#endif
