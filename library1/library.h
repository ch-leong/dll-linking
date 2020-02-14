#ifdef LIBRARY1_EXPORTS
#define LIBRARY1_API __declspec(dllexport)
#else
#define LIBRARY1_API __declspec(dllimport)
#endif
#pragma once

// The main program knows of this function.
void LIBRARY1_API Load();
