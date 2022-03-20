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

#define BIT(x) (1 << x)
