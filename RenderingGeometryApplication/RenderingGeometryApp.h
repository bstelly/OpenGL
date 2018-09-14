#pragma once
#include <glm/ext.hpp>
#include <Application.h>
#include "MeshRenderer.h"
#include "Shader.h"


class RenderingGeometryApp : public Application
{
public:
	RenderingGeometryApp();
	~RenderingGeometryApp();
	
	MeshRenderer* mesh;
	Shader* shader;

	glm::mat4 m_model;
	glm::mat4 m_view;
	glm::mat4 m_projection;

	unsigned int m_program;

	void startup();
	void update(float dt);
	void shutdown();
	void draw();
};