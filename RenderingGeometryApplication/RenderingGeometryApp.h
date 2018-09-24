#pragma once
#include <glm/ext.hpp>
#include <Application.h>
#include "MeshRenderer.h"
#include "Shader.h"
#include <vector>


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

	std::vector<glm::vec4> genHalfCircle(int np, int radius);
	std::vector<glm::vec4> genSphere(std::vector<glm::vec4> points, int numRotations);
	std::vector<unsigned int> genIndices(int np, int nm);
	
	void startup();
	void update(float dt);
	void shutdown();
	void draw();
};