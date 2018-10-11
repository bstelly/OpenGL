#include "CameraApplication.h"

int main()
{
	CameraApplication* app = new CameraApplication;
	app->run("Camera App", 1280, 720, false);
}
