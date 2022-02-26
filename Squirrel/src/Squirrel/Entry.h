#pragma once

#ifdef SQ_PLATFORM_WINDOWS

extern Squirrel::Application* Squirrel::CreateApplication();

int main(int argc, char** argv) {

	Squirrel::Log::Init();
	const char* gamename = "TestApp";
	SQ_CORE_WARN("Initing Log!");
	SQ_INFO("Starting {0}!!!!", gamename);

	//printf("Running Squirrel Engine\n");
	auto application = Squirrel::CreateApplication();
	application->Run();
	delete application;

}
#endif // SQ_PLATTFORM_WINDWOS
