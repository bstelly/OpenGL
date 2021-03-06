#pragma once
#include <glm/ext.hpp>
#include <Application.h>
#include "MeshRenderer.h"
#include "Shader.h"
#include "Camera.h"
#include <vector>
#include "Texture.h"


class RenderingGeometryApp : public Application
{
public:
	RenderingGeometryApp();
	~RenderingGeometryApp();
	
	MeshRenderer* mesh;
	Shader* shader;
	Texture* texture = new Texture();
	

	
	glm::mat4 m_model;
	glm::mat4 m_view;
	glm::mat4 m_projection;

	std::vector<glm::vec4> genHalfCircle(int np, int radius);
	void genSphere(int radius, int numPoints, int meridians);
	std::vector<unsigned int> genIndices(int np, int nm);
	void genCube();
	void genPlane();
	
	void startup();
	void update(float dt);
	void shutdown();
	void draw();

};
