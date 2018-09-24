#define GLM_FORCE_SWIZZLE
#include "gl_core_4_4.h"
#include "RenderingGeometryApp.h"
#include <imgui.h>
#include "Shader.h"
#include "iostream"
#include "../IntroductionApp/Transform.h"


RenderingGeometryApp::RenderingGeometryApp()
{
}

RenderingGeometryApp::~RenderingGeometryApp()
{
}

glm::mat4 translation;
Transform transform;
void RenderingGeometryApp::startup()
{
	std::vector<glm::vec4> points = genHalfCircle(6, 3);
	points = genSphere(points, 3);

	std::vector<unsigned int> indices = genIndices(points.size(), 3);
	std::vector<MeshRenderer::Vertex> vertices;


	for(int i = 0; i < points.size(); i++)
	{
		MeshRenderer::Vertex vertex = { points[i], glm::vec4(0, 0, 1, 1) };
		vertices.push_back(vertex);
	}
	
	transform.m_model = glm::mat4(1);

	mesh = new MeshRenderer();
	mesh->initialize(indices, vertices);

	shader = new Shader();
	//shader->DefaultLoad();
	shader->Load("vertexShader.txt", 1);
	shader->Load("fragmentShader.txt", 2);
	shader->Attach();
}

int v3[3];


void RenderingGeometryApp::update(float dt)
{
	transform.m_model = glm::mat4(1);	
	glm::vec3 eye = glm::vec3(0, 0, 20);
	m_view = glm::lookAt(eye, transform.m_model[3].xyz(), glm::vec3(0, 1, 0));
	m_projection = glm::perspective(glm::quarter_pi<float>(), 800 / (float)600, 0.1f, 1000.f);
}
float speed = 3;
void RenderingGeometryApp::draw()
{

	glUseProgram(shader->m_program);

	
	
	if (ImGui::SliderInt3("Position", v3, -100, 100));
	translation = transform.Translate(glm::vec3(v3[0], v3[1], v3[2]));
	
	
	glm::mat4 mvp = m_projection * m_view * transform.m_model * translation;

	//get an id that is the variable from the shader
	int variableId = glGetUniformLocation(shader->m_program, "ProjectionViewWorld");

	glUniformMatrix4fv(variableId, 1, GL_FALSE, &mvp[0][0]);

	mesh->render();

	//int ypos = 4;
	//int xMultiple = 0;
	//for (int i = 0; i < 64; i++)
	//{
	//	glm::mat4 matrix = glm::mat4(1);
	//	matrix = glm::translate(matrix,glm::vec3(xMultiple * 4, ypos, 0));
	//	glm::mat4 mvp = m_projection * m_view * matrix * translation;
	//	glUniformMatrix4fv(variableId, 1, GL_FALSE, &mvp[0][0]);
	//	mesh->render();
	//	xMultiple++;
	//	if (xMultiple == 8)
	//	{
	//		ypos -= 4;
	//		xMultiple = 0;
	//	}
	//}

	glUseProgram(0);
}

void RenderingGeometryApp::shutdown()
{
	
}

std::vector<glm::vec4> RenderingGeometryApp::genHalfCircle(int np, int radius)
{
	std::vector<glm::vec4> points;

	float angle = 3.14 / np;
	for (float theta = 0; theta < 3.14; theta += angle)
	{
		points.push_back(glm::vec4(glm::cos(theta) * radius, glm::sin(theta) * radius, 0, 1));
	}
	return points;
}

std::vector<glm::vec4> RenderingGeometryApp::genSphere(std::vector<glm::vec4> points, int meridians)
{
	float angle = 3.14 / meridians;
	std::vector<glm::vec4> totalPoints;
	
	for (int theta = 0; theta < meridians; theta += angle)
	{
		for (int j = 0; j < points.size(); j++)
		{
			float x = points[j].x * glm::cos(theta) + points[j].z * sin(theta);
			float y = 0;
			float z = -points[j].x * sin(theta) + points[j].z * cos(theta);
			totalPoints.push_back(glm::vec4(x, y, z, 1));
		}
	}
	return totalPoints;
}



std::vector<unsigned int> genIndices(int np, int nm)
{
	std::vector<unsigned int> indices;
	std::vector<unsigned int> bot_left;
	std::vector<unsigned int> bot_right;
	for (int i = 0; i < nm - 1; i++)
	{
		for (int j = 0; j < np; j++)
		{
			bot_left.push_back(i);
			bot_right.push_back(i + np);
		}
	}

	for (int x = 0; x < bot_left.size(); x++)
	{
		indices.push_back(bot_left[x]);
		indices.push_back(bot_right[x]);
		if(x % 3 == 0)
		{
			indices.push_back(0xFFFF);
		}
	}
	return indices;

}
