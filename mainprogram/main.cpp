#include <iostream>
#include <windows.h>
#include "../library1/library.h"

// Loading dynamic library 1. This can also be done though project properties.
#ifdef _DEBUG
  #ifdef _WIN64
    #pragma comment(lib, "../x64/Debug/library1.lib")
  #else
    #pragma comment(lib, "../Win32/Debug/library1.lib")
  #endif
#else
  #ifdef _WIN64
    #pragma comment(lib, "../x64/Release/library1.lib")
  #else
    #pragma comment(lib, "../Win32/Release/library1.lib")
  #endif
#endif

int main()
{
    // We already loaded Library1's symbol at load time, so we can simply call it.
    Load();

    // Loading of Library2 is more complicated...

    // Loading dynamic library 2.
    HMODULE hModule = LoadLibraryA("library2.dll");
    if (hModule == nullptr)
    {
        std::cerr << "Library2 not found. Error: " << GetLastError() << "\n";
        return -1;
    }

    // Finding the function and calling it.
    auto load = (void(*)())GetProcAddress(hModule, "Load");
    if (load != nullptr)
    {
        load();
    }
    else
    {
        std::cerr << "Load() in Library2 not found. Error: " << GetLastError() << "\n";
        return -1;
    }

    system("PAUSE");
    return 0;
}
