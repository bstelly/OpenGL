#pragma once
#define GLM_FORCE_SWIZZLE
#include <glm/ext.hpp>


class Transform
{
public:
	Transform();
	~Transform();

	glm::mat4 Translate(glm::vec3 move);
	glm::mat4 Rotation(float radius, glm::vec3 axis);
	glm::mat4 Scale(float scale);

private:

	glm::mat4 m_model; //Identity
	
	glm::vec3 m_worldPosition; //m_model[3]
	glm::vec3 m_localPosition;
	
	glm::vec3 m_worldScale; //Matrix diagonal
	glm::vec3 m_localScale;
	
	glm::vec3 m_worldRotation; //3x3 matrix; X, Y, Z
	glm::vec3 m_localRotation;
};