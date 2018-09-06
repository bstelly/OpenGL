#pragma once
#include <glm/ext.hpp>
#include <vector>
#include <Application.h>



class RenderingGeometryApp : public Application
{
public:

	struct Vertex
	{
		glm::vec4 position;
		glm::vec4 color;
	};
	
	RenderingGeometryApp();
	~RenderingGeometryApp();
	
	std::vector<unsigned int> m_indices;
	std::vector<Vertex> m_vertices;

	unsigned int m_ibo;
	unsigned int m_vbo;
	unsigned int m_vao;
	unsigned int m_program;

	glm::mat4 m_model;
	glm::mat4 m_view;
	glm::mat4 m_projection;

	void startup();
	void update(float dt);
	void shutdown();
	void draw();
};