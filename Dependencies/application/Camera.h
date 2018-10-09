#pragma once
#include <glfw3.h>
#include <glm\ext.hpp>
#define GLM_FORCE_SWIZZLE

class Camera
{
protected:
	glm::mat4 worldTransform;
	glm::mat4 viewTransform;
	glm::mat4 projectionTransform;
	glm::mat4 projectionViewTransform;

	void UpdateProjectionViewTransform();

public:
	Camera();
	~Camera();
	glm::mat4 SetPerspective(float fieldOfView, float aspectRatio, float near, float far);
	glm::mat4 SetOrthographic(float left, float right, float top, float bottom, float far, float near);
	glm::mat4 SetLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up);
	void SetPosition(glm::vec3 position);
	glm::mat4 GetWorldTransform();
	glm::mat4 GetView();
	glm::mat4 GetProjection();
	glm::mat4 GetProjectionView();

};