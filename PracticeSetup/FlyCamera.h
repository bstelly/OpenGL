#pragma once
#include "Camera.h"
#include <glm\ext.hpp>


class FlyCamera : Camera
{
private:
	float m_speed;
	glm::vec3 up;

public:
	FlyCamera();
	~FlyCamera();
	void Update(float deltaTime);
	void SetSpeed(float speed);
};