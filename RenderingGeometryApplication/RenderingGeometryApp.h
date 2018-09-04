#pragma once
#include <glm/ext.hpp>
#include <vector>
#include <Application.h>


class RenderingGeometryApp : public Application
{	
public:

	std::vector<unsigned int> m_indices;
	std::vector<Vertex> m_vertices;
	unsigned int m_ibo;
	unsigned int m_vbo;
	unsigned int m_vao;

	RenderingGeometryApp();
	~RenderingGeometryApp();
	
	void startup();
	void update(float dt);
	void shutdown();
	void draw();
};
struct Vertex
{
	glm::vec4 position;
	glm::vec4 color;
};