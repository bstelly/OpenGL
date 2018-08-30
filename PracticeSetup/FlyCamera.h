#pragma once
#include <glm\ext.hpp>
#include "Camera.h"




class FlyCamera : Camera
{
private:
	float m_speed;
	glm::vec3 up;

public:
	FlyCamera();
	~FlyCamera();
	void Update(GLFWwindow* window, float deltaTime);
	void SetSpeed(float speed);
};