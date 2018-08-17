#include "Application.h"
#include "gl_core_4_4.h"
#include "Gizmos.h"
#include <glfw3.h>


Application::Application() :
	m_window(nullptr),
	m_gameover(false),
	m_clearColor{1, 1, 1, 1},
	m_runningTime(0)
{}

void Application::run(const char * title, unsigned int width, unsigned int height, bool fullscreen)
{
	glfwInit();
	m_window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);
	glfwMakeContextCurrent(m_window);
	ogl_LoadFunctions();
	Gizmos::create();
	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST);

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