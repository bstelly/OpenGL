#pragma once
#include <glm/glm.hpp>
#include <vector>

class MeshRenderer
{
public:
	MeshRenderer();
	~MeshRenderer();

	struct Vertex
	{
		glm::vec4 position;
		glm::vec4 color;
	};

	int initialize(std::vector<unsigned int>& indices, std::vector<Vertex>& vertices);
	void Move(glm::vec4 move);
	int render();

private:
	std::vector<unsigned int> m_indices;
	std::vector<Vertex> m_vertices;
	unsigned int m_vao;
	unsigned int m_vbo;
	unsigned int m_ibo;

	int create_buffers();


};