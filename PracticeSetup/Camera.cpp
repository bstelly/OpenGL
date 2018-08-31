#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include "Camera.h"

Camera::Camera()
{
	
}

Camera::~Camera()
{

}

void Camera::UpdateProjectionViewTransform()
{

}

void Camera::Update(GLFWwindow * window, float deltaTime)
{

}

void Camera::SetPerspective(float fieldOfView, float aspectRatio, float near, float far)
{

}

void Camera::SetLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up)
{

}

void Camera::SetPosition(glm::vec3 position)
{
}

glm::mat4 Camera::GetWorldTransform()
{
	return worldTransform;
}

glm::mat4 Camera::GetView()
{
	return viewTransform;
}

glm::mat4 Camera::GetProjection()
{
	return projectionTransform;
}

glm::mat4 Camera::GetProjectionView()
{
	return projectionViewTransform;
}