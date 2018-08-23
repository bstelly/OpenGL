#pragma once
#include <glm/fwd.hpp>
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
	glm::vec3 m_worldPosition;
	glm::vec3 m_localPosition;
	glm::vec3 m_worldScale;
	glm::vec3 m_localScale;
	glm::vec3 m_worldRotation;
	glm::vec3 m_localRotation;

};