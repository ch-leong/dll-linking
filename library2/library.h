#ifdef LIBRARY2_EXPORTS
#define LIBRARY2_API __declspec(dllexport)
#else
#define LIBRARY2_API __declspec(dllimport)
#endif
#pragma once
