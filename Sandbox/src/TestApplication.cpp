#include <Squirrel.h>

class ExampleLayer : public Squirrel::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		SQ_INFO("ExampleLayer::Update");
	}

	void OnEvent(Squirrel::Event& event) override
	{
		SQ_TRACE("{0}", event);
	}

};

class Sandbox :public Squirrel::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer);
		PushOverlay(new Squirrel::ImGuiLayer);
	}
	~Sandbox() {
	}
};

Squirrel::Application* Squirrel::CreateApplication() {
	return new Sandbox();
}
