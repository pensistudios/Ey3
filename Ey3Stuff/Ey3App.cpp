#include "Ey3App.h"

using namespace Ey3;

App* App::theApp = 0;
App::EntryFunction App::Main = 0;

App::App()
{

}

App::~App()
{

}

int main(int quantity, char** args)
{	
	if (App::Main) 
    {
        App::Main(quantity,args);
    }

    delete App::theApp;
    App::theApp = 0;

}