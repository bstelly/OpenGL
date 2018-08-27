#include "Transform.h"
//#include <winuser.h>

Transform::Transform()
{
	m_model = glm::mat4(1);
	
	m_worldPosition = m_model[3];
	m_localPosition = m_model[3];
	
	m_worldScale = glm::vec3(1, 1, 1);
	m_localScale = glm::vec3(1, 1, 1);
	m_worldRotation = glm::vec3(1);
	for (int col = 0; col < 3; col++)
	{
		m_worldRotation = m_model[col];
		m_localRotation = m_model[col];
	}
}

Transform::~Transform()
{

}

glm::mat4 Transform::Translate(glm::vec3 move)
{
	glm::mat4 translation = glm::mat4(1);
	translation[3].xyz = move;
	m_model = m_model * translation;
	return m_model;
}

glm::mat4 Transform::Rotation(float radius, glm::vec3 axis)
{
	float cosine = cos(radius);
	float sine = sin(radius);

	//Create columns
	glm::vec3 x_axis = glm::vec3{ 1, 0, 0 };
	glm::vec3 y_axis = glm::vec3{ 0, 1, 0 };
	glm::vec3 z_axis = glm::vec3{ 0, 0, 1 };

	//Create rotation matrix with columns
	glm::mat4 rotationMatrix = glm::mat3(x_axis, y_axis, z_axis);

	//Plug values into the rotation matrix
	if(axis == x_axis)
	{
		rotationMatrix[1].y = cosine;
		rotationMatrix[1].z = sine;
		rotationMatrix[2].y = -sine;
		rotationMatrix[2].z = cosine;
	}
	if(axis == y_axis)
	{
		rotationMatrix[0].x = cosine;
		rotationMatrix[0].z = -sine;
		rotationMatrix[2].x = sine;
		rotationMatrix[2].z = cosine;
	}
	if(axis == z_axis)
	{
		rotationMatrix[0].x = cosine;
		rotationMatrix[0].y = sine;
		rotationMatrix[1].x = -sine;
		rotationMatrix[1].y = cosine;
	}

	m_model = m_model * rotationMatrix;

	return m_model;









	//if (axis[0] == 0 && axis[1] == 0 && axis[2] == 1)
	//{
	//	m_model = m_model * glm::mat4{
	//		cos(radius), -sin(radius), 0, 0,	//rotate on Z
	//		sin(radius), cos(radius), 0, 0,
	//		0, 0, 1, 0,
	//		0, 0, 0, 0};
	//	return m_model;
	//}

	//if (axis[0] == 1 && axis[1] == 0 && axis[2] == 0)
	//{
	//	m_model = m_model * glm::mat4{
	//		1, 0, 0, 0,
	//		0, cos(radius), -sin(radius), 0,	//rotate on x
	//		0, sin(radius), cos(radius), 0,
	//		0, 0, 0, 0
	//	};
	//	return m_model;
	//}

	//if (axis[0] == 0 && axis[1] == 1 && axis[2] == 0)
	//{
	//	m_model = m_model * glm::mat4{
	//		cos(radius), 0, sin(radius), 0,		//rotate on y
	//		0, 1, 0, 0,
	//		-sin(radius), 0, cos(radius), 0,
	//		0, 0, 0, 0
	//	};
	//	return m_model;
	//}
}

glm::mat4 Transform::Scale(float scale)
{
	m_model[0].x = scale;
	m_model[1].y = scale;
	m_model[2].z = scale;
	return m_model;
}