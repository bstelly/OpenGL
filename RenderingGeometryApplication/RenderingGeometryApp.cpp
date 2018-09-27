#define GLM_FORCE_SWIZZLE
#include "gl_core_4_4.h"
#include "RenderingGeometryApp.h"
#include <imgui.h>
#include "Shader.h"
#include <iostream>
#include <Transform.h>


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
	transform.m_model = glm::mat4(1);

	std::vector<glm::vec4> points = genHalfCircle(12, 3);
	points = genSphere(points, 3);

	std::vector<unsigned int> indices = genIndices(12, 4);
	std::vector<MeshRenderer::Vertex> vertices;

	for(int i = 0; i < points.size(); i++)
	{
		MeshRenderer::Vertex vertex = { points[i], glm::vec4(1) };
		vertices.push_back(vertex);
	}
	
	mesh = new MeshRenderer();
	mesh->initialize(indices, vertices);

	shader = new Shader();
	shader->DefaultLoad();
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

	glUseProgram(0);
}

void RenderingGeometryApp::shutdown()
{
}

std::vector<glm::vec4> RenderingGeometryApp::genHalfCircle(int np, int radius)
{
	std::vector<glm::vec4> points;


	for (float i = 0; i < np; i ++)
	{
		float angle = glm::pi<float>() / ((float)np - 1);
		float theta = i * angle;
		points.push_back(glm::vec4(glm::cos(theta) * radius, glm::sin(theta) * radius, 0, 1));
	}
	return points;
}

std::vector<glm::vec4> RenderingGeometryApp::genSphere(std::vector<glm::vec4> points, int meridians)
{

	std::vector<glm::vec4> totalPoints;
	
	for (float i = 0; i < meridians + 1; i++)
	{
		float angle = glm::pi<float>() * 2 / meridians;
		float theta = i * angle;
		for (int j = 0; j < points.size(); j++)
		{
			float x = points[j].x;
			float y = points[j].y * cos(theta) + points[j].z * -sin(theta);
			float z = points[j].z * cos(theta) + points[j].y * sin(theta);
			totalPoints.push_back(glm::vec4(x, y, z, 1));
		}
	}
	return totalPoints;
}


std::vector<unsigned int> RenderingGeometryApp::genIndices(int np, int nm)
{
	std::vector<unsigned int> indices;
	unsigned int bot_left;
	unsigned int bot_right;
	int start = 0;

	for (int i = 0; i < nm; i++)
	{
		start = i * np;

		for (int j = 0; j < np; j++)
		{
			bot_left = start + j;
			bot_right = bot_left + np;
			indices.push_back(bot_left);
			indices.push_back(bot_right);
		}

		indices.push_back(0xFFFF);
	}

	return indices;
}