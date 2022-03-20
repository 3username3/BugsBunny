#include "bbpch.h"
#include <BugsBunny.h>

class Sandbox : public BugsBunny::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

BugsBunny::Application* BugsBunny::CreateApplication() {
	return new Sandbox();
}


/*
ENGINE STARTUP
.)Rechtsklick(Sandbox) -> "Set as startup project"
.)BugsBunny.dll in bin>Debug-x64>Sandbox kopieren
*/