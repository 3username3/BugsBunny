#pragma once

//If we want to use the Application class from Application.h in Sandbox, 
//we need to export it from the Hazel dll and import it to Sandbox.
//This is done by using _declspec(dllexport) and _declspec(dllimport), which 
//are a Windows only thing. Therefore, we first check whether the platform is windows.
#ifdef BB_PLATFORM_WINDOWS
	#ifdef BB_BUILD_DLL
		//This one is active if the BugsBunny library is built.
		#define BB_API _declspec(dllexport)

	#else
		//For Sandbox "import" is active.
		#define BB_API _declspec(dllimport)

	#endif //BB_BUILD_DLL

#else

	#error BugsBunny only supports windows	

#endif

//Checks a certain condition and logs a certain message & sets a breakpoint, if it fails.
#ifdef BB_ENABLE_ASSERTS
	#define BB_ASSERT(x, ...) { if(!(x)) { BB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define BB_CORE_ASSERT(x, ...) { if(!(x)) { BB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BB_ASSERT(x, ...)
	#define BB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
