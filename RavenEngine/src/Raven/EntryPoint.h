#pragma once

#ifdef RAVEN_PLATFORM_WINDOWS

#include <stdio.h>

extern Raven::Application*  Raven::CreateApplication();

int main(int argc, char** argv)
{

	

	auto app = Raven::CreateApplication();
	app->Run();
	delete app;
	
}

#endif

