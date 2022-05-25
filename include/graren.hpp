#ifdef _WIN32
#ifdef GRAREN_DLL_EXPORT
#define GRAREN __declspec(dllexport)
#else
#define GRAREN __declspec(dllimport)
#endif
#else
#define GRAREN // nothing
#endif