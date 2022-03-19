#pragma once

#ifdef BB_PLATFORM_WINDOWS

extern BugsBunny::Application* BugsBunny::CreateApplication();

int main(int argc, char** argv) {
	
	BugsBunny::Log::Init();
	BB_CORE_WARN("Initialized Log!");
	int a = 5;
	BB_INFO("Hello! Var={0}", a);

	auto app = BugsBunny::CreateApplication();
	app->Run();
	delete app;

}

#endif // BB_PLATFORM_WINDOWS

