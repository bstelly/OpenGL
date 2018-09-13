#include "GUIApplication.h"


int main()
{
	GUIApplication* app = new GUIApplication();
	app->run("GUI Application", 1280, 720, false);
}