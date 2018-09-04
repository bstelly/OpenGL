#include "gl_core_4_4.h"
#include "RenderingGeometryApp.h"



RenderingGeometryApp::RenderingGeometryApp()
{
	m_indices = { 0, 1, 2, 2, 3, 0 };
}

RenderingGeometryApp::~RenderingGeometryApp()
{
}

void RenderingGeometryApp::startup()
{


	glGenBuffers(1, &m_vbo);
	glGenVertexArrays(1, &m_vao);

	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);


	glBufferData(GL_ARRAY_BUFFER, 4 * 32, &m_vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}