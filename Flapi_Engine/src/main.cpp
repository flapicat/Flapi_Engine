#include "App.h"

int main()
{
	Log::init();
	App app;
	app.start();
	app.run();
	app.close();
}