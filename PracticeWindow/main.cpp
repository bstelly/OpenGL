#include "gl_core_4_4.h"
#include <glm.hpp>
#include <glfw3.h>

//To set up a window, you must first link all necessary libraries to the project.
//Once the libraries are added and linked to the project, add the Gizmos and
//gl_core_4_4 header and source files to the project. Include the gl_core_4_4.h header
//file at the top of your main.cpp to avoid errors. To set up the window, in the int main()
//function, initialize glfw with "glfwInit()". Then create a GLFWwindow pointer object and
//initialize it with "glfwCreateWindow()". Now set this instance of the GLFWwindow to the
//current glfw context. Finally Initialize OpenGL with "ogl_LoadFunctions()". This will
//create a window but the window will automatically close. To keep the window open, create
//a while loop that will check if the window should close using the function glfwWindowShouldClose().
//The while loop should contain the functions glfwPollEvents() and glfwSwapBuffers().



int main()
{
	glfwInit();
	GLFWwindow * window = glfwCreateWindow(1280, 720, "Window", NULL, NULL);
	glfwMakeContextCurrent(window);
	ogl_LoadFunctions();
	auto variable = glfwWindowShouldClose;
	
	while (!variable(window))
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}