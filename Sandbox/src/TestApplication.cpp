#include <Squirrel.h>

class Sandbox :public Squirrel::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

Squirrel::Application* Squirrel::CreateApplication() {
	return new Sandbox();
}
