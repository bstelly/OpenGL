#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include "Camera.h"


Camera::Camera()
{
	worldTransform = glm::mat4{ 1 };
}

Camera::~Camera()
{

}

void Camera::UpdateProjectionViewTransform()
{
	viewTransform = glm::inverse(worldTransform);
	projectionTransform =  projectionTransform * viewTransform;
}

void Camera::SetPerspective(float fieldOfView, float aspectRatio, float near, float far)
{
	projectionTransform = glm::perspective(glm::pi<float>() * fieldOfView,
		aspectRatio, near, far);
}

void Camera::SetLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up)
{
	viewTransform = glm::lookAt(from, to, up);
}

void Camera::SetPosition(glm::vec3 position)
{
	//worldTransform[3].xyz = position
	worldTransform[3].x += position.x;
	worldTransform[3].y += position.y;
	worldTransform[3].z += position.z;

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