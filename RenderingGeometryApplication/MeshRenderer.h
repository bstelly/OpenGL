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
		Vertex();
		Vertex(glm::vec4 pos, glm::vec4 rgb)
		{
			position = pos;
			color = rgb;
		}
		Vertex(glm::vec4 pos, glm::vec4 rgb, glm::vec2 uv)
		{
			position = pos;
			color = rgb;
			_uv = uv;
		}

		glm::vec4 position;
		glm::vec4 color;
		glm::vec4 normal;
		glm::vec2 _uv;
	};

	int initialize(std::vector<unsigned int>& indices, std::vector<Vertex>& vertices);
	int render();
	std::vector<Vertex> GetPosition();

private:
	std::vector<unsigned int> m_indices;
	std::vector<Vertex> m_vertices;
	unsigned int m_vao;
	unsigned int m_vbo;
	unsigned int m_ibo;

	int create_buffers();
};