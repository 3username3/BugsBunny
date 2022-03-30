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
