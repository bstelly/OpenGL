#pragma once
#include <glm\ext.hpp>
#include "Camera.h"




class FlyCamera : public Camera
{
private:
	float m_speed;

public:
	FlyCamera();
	~FlyCamera();
	void Update(GLFWwindow* window, float deltaTime);
	void SetSpeed(float speed);
};