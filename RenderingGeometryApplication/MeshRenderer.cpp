#include <gl_core_4_4.h>
#include "MeshRenderer.h"

MeshRenderer::MeshRenderer()
{
}

MeshRenderer::~MeshRenderer()
{
}

int MeshRenderer::initialize(std::vector<unsigned int>& indices, std::vector<Vertex>& vertices)
{
	m_indices = indices;
	m_vertices = vertices;
	create_buffers();

	return 1;
}

int MeshRenderer::render()
{
	glBindVertexArray(m_vao);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDrawElements(GL_TRIANGLE_STRIP, m_indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	return 1;
}

std::vector<MeshRenderer::Vertex> MeshRenderer::GetPosition()
{
	return m_vertices;
}

int MeshRenderer::create_buffers()
{
	//generate vertex array object
	glGenVertexArrays(1, &m_vao);

	//generate buffers
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ibo);

	glBindVertexArray(m_vao);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), m_vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), m_indices.data(), GL_STATIC_DRAW);

	//positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

	//colors
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)sizeof(glm::vec4));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	return 1;
}

void MeshRenderer::Move(glm::vec4 move)
{
	Vertex A = { m_vertices[0].position += move, m_vertices[0].color};
	Vertex B = { m_vertices[1].position += move, m_vertices[1].color};
	Vertex C = { m_vertices[2].position += move, m_vertices[2].color};
	Vertex D = { m_vertices[3].position += move, m_vertices[3].color};
	std::vector<Vertex> vertices = { A,B,C,D };
	m_vertices = vertices;
}

