#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include "Camera.h"


Camera::Camera()
{
	worldTransform = glm::mat4(1);
}

Camera::~Camera()
{

}

void Camera::UpdateProjectionViewTransform()
{
	projectionViewTransform =  projectionTransform * viewTransform;
}

glm::mat4 Camera::SetPerspective(float fieldOfView, float aspectRatio, float near, float far)
{
	projectionTransform = glm::mat4(1);
	projectionTransform[0].x = 1 / (aspectRatio * tan(fieldOfView / 2));
	projectionTransform[1].y = 1 / tan(fieldOfView / 2);
	projectionTransform[2].z = -((far + near) / (far - near));
	projectionTransform[3].z = -((2 * far * near) / (far - near));
	projectionTransform[2].w = -1;

	return projectionTransform;
}

glm::mat4 Camera::SetOrthographic(float left, float right, float top, float bottom, float far, float near)
{
	projectionTransform = glm::mat4(1);
	projectionTransform[0].x = 2 / (right - left);
	projectionTransform[1].y = 2 / (top - bottom);
	projectionTransform[2].z = -2 / (far - near);
	projectionTransform[3].x = -((right + left) / (right - left));
	projectionTransform[3].y = -((top + bottom) / (top - bottom));
	projectionTransform[3].z = -((far + near) / (far - near));
	projectionTransform[3].w = 1;

	return projectionTransform;
}


glm::mat4 Camera::SetLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up)
{
	glm::vec3 forward = glm::normalize(from - to);
	glm::vec3 right = glm::cross(glm::normalize(up), forward);
	glm::vec3 _up = glm::cross(forward, right);

	viewTransform = glm::mat4(1);

	viewTransform[0][0] = right.x;
	viewTransform[0][1] = right.y;
	viewTransform[0][2] = right.z;
	viewTransform[1][0] = _up.x;
	viewTransform[1][1] = _up.y;
	viewTransform[1][2] = _up.z;
	viewTransform[2][0] = forward.x;
	viewTransform[2][1] = forward.y;
	viewTransform[2][2] = forward.z;
	viewTransform[3][0] = from.x;
	viewTransform[3][1] = from.y;
	viewTransform[3][2] = from.z;

	return viewTransform;
}

void Camera::SetPosition(glm::vec3 position)
{
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