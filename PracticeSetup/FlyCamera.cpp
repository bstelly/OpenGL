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
	Transform transform = Transform();
	transform.m_model = worldTransform;

	if (glfwGetKey(window, GLFW_KEY_W))
	{
		worldTransform += transform.Translate(glm::vec3(0, 1, 0) * deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_A))
	{
		worldTransform += transform.Translate(glm::vec3(-1, 0, 0) * deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_S))
	{
		worldTransform += transform.Translate(glm::vec3(0, -1, 0) * deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_D))
	{
		worldTransform += transform.Translate(glm::vec3(1, 0, 0) * deltaTime);
	}

}

void FlyCamera::SetSpeed(float speed)
{
	m_speed = speed;
	
}