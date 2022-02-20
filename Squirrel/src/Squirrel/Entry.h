#pragma once

#ifdef SQ_PLATFORM_WINDOWS

extern Squirrel::Application* Squirrel::CreateApplication();

int main(int argc, char** argv) {
	printf("Running Squirrel Engine\n");
	auto application = Squirrel::CreateApplication();
	application->Run();
	delete application;

}
#endif // SQ_PLATTFORM_WINDWOS
