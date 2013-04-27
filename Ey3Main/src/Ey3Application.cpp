#include "Ey3Application.h"

using namespace Ey3;

Application::Application()
{
}

Application::~Application()
{
}

Application* Application::create()
{
	return new Application;
}

int main(int quanity, char** args)
{
	
	Application* app = Application::create();

	app->init();

	app->run();

	app->end();

	delete app; //Possible memproblems?

}