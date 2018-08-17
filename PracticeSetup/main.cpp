
#include "gl_core_4_4.h"
#include <glfw3.h>
#include "Gizmos.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>


GLFWwindow* window;

void DrawLines()
{

}

void Update()
{
	glm::mat4 model = glm::mat4(1);//model
	glm::mat4 view = glm::lookAt(glm::vec3(10, 10, 25), glm::vec3(0), glm::vec3(0, 1, 0));//view
	glm::mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);//projection

	bool lines = false;
	while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Gizmos::clear();
		model = glm::mat4(1);
		Gizmos::addSphere(glm::vec3(0, 0, 0), 10, 10, 10, glm::vec4(.05, .05, .25, 1), &model);
		Gizmos::draw(projection * view * model);
		//glm::vec4 white(1, 1, 1, 1);
		//glm::vec4 black(0, 0, 0, 1);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

int Start()
{
	glfwInit();
	window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);
	glfwMakeContextCurrent(window);
	ogl_LoadFunctions();
	Gizmos::create();
	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST);
	return 1;
}

int main()
{
	Application* app = new IntroductionApp;

}