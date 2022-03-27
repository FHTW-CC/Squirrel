// The main entry-point of any Squirrel application
// To use Squirrel create a class inheriting from Squirrel::Application
// Implement the Application::CreateApplication() function to return a new instance of your application subclass.
// TestApplication.cpp in the Sandbox Project for reference

#pragma once

#ifdef SQ_PLATFORM_WINDOWS

extern Squirrel::Application* Squirrel::CreateApplication();

int main(int argc, char** argv) {

	Squirrel::Log::Init();
	SQ_CORE_WARN("Initing Log!");


	//printf("Running Squirrel Engine\n");
	auto application = Squirrel::CreateApplication();
	application->Run();
	delete application;

}
#endif // SQ_PLATTFORM_WINDWOS
