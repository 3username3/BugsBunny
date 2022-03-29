#pragma once

#ifdef BB_PLATFORM_WINDOWS
	#ifdef BB_BUILD_DLL

		#define BB_API _declspec(dllexport)

	#else

		#define BB_API _declspec(dllimport)

	#endif // BB_BUILD_DLL

#else

	#error BugsBunny only supports windows	

#endif

//checks a certain condition and logs a certain message & sets a breakpoint, if it fails
#ifdef BB_ENABLE_ASSERTS
	#define BB_ASSERT(x, ...) { if(!(x)) { BB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define BB_CORE_ASSERT(x, ...) { if(!(x)) { BB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BB_ASSERT(x, ...)
	#define BB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
