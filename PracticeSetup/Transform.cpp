#include "Transform.h"

Transform::Transform()
{
	m_worldPosition = glm::vec3(0, 0, 0);
	m_localPosition = glm::vec3(0, 0, 0);
	m_worldScale = glm::vec3(0, 0, 0);
	m_localScale = glm::vec3(0, 0, 0);
	m_worldRotation = glm::vec3(0, 0, 0);
	m_localRotation = glm::vec3(0, 0, 0);
}

Transform::~Transform()
{

}

glm::mat4 Transform::Translate(glm::vec3 move)
{

}

glm::mat4 Transform::Rotation(float radius, glm::vec3 axis)
{

}

glm::mat4 Transform::Scale(float scale)
{

}