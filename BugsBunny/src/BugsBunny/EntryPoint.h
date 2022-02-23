#pragma once

#ifdef BB_PLATFORM_WINDOWS

extern BugsBunny::Application* BugsBunny::CreateApplication();

int main(int argc, char** argv) {
	
	printf("BugsBunny Engine");
	auto app = BugsBunny::CreateApplication();
	app->Run();
	delete app;

}

#endif // BB_PLATFORM_WINDOWS

