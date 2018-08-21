#include "gl_core_4_4.h"
#include <glfw3.h>
#include "Application.h"


Application::Application() :
	m_window(nullptr),
	m_gameover(false),
	m_clearColor{1, 1, 1, 1},
	m_runningTime(0)
{}

Application::~Application()
{

}


void Application::run(const char * title, unsigned int width, unsigned int height, bool fullscreen)
{
	glfwInit();
	m_window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);
	glfwMakeContextCurrent(m_window);
	ogl_LoadFunctions();

	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST);
	startup();

	while (!glfwWindowShouldClose(m_window) && glfwGetKey(m_window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		update(0);
		draw();

		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE))
	{
		m_gameover = true;
	}
	if (m_gameover)
	{
		shutdown();
	}
}