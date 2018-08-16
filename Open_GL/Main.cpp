#include <glfw3.h>
#include <glfw3native.h>
#include "gl_core_4_4.h"
#include "Gizmos.h"

int main()
{
	GLFWwindow* window;
	if (!glfwInit())
	{
		return -1;
	}

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	
	while (!glfwWindowShouldClose(window))
	{
		if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
		{
			glfwDestroyWindow(window);
			glfwTerminate();
			return -3;
		}
	}
	glfwTerminate();
	return 0;
}