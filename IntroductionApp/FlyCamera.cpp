#include <glfw3.h>
#include "FlyCamera.h"
#include "Transform.h"

FlyCamera::FlyCamera()
{
	
}

FlyCamera::~FlyCamera()
{

}

void FlyCamera::Update(GLFWwindow* window, float deltaTime)
{
	if (glfwGetKey(window, GLFW_KEY_W))
	{
		SetPosition(glm::vec3(0, -m_speed * deltaTime, 0));
	}
	if (glfwGetKey(window, GLFW_KEY_A))
	{
		SetPosition(glm::vec3(m_speed*deltaTime, 0, 0));
	}
	if (glfwGetKey(window, GLFW_KEY_S))
	{
		SetPosition(glm::vec3(0, m_speed * deltaTime, 0));
	}
	if (glfwGetKey(window, GLFW_KEY_D))
	{
		SetPosition(glm::vec3(-m_speed * deltaTime, 0, 0));
	}
}

void FlyCamera::SetSpeed(float speed)
{
	m_speed = speed;
	
}