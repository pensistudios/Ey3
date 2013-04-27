#include "Ey3WindowApplication.h"

using namespace Ey3;

WindowApplication::WindowApplication(Str& title, Str& className)
{
	fullscreen = false;
}

WindowApplication::~WindowApplication()
{
}

void WindowApplication::setStrings(Str& title, Str& name)
{
	_title = title;
	_className = name;
}

Application* WindowApplication::create()
{
	return new WindowApplication;
}

void WindowApplication::setWindow(int h, int w, int b)
{
	windowWidth = w;
	windowHeight = h;
	windowBits = b;
}