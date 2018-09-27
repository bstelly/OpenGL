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
	mesh = new MeshRenderer();
	transform.m_model = glm::mat4(1);

	int nm = 20;
	int np = 20;
	int radius = 5;
	genSphere(radius, np, nm);
	//genCube();
	//genPlane();


	shader = new Shader();
	shader->DefaultLoad();
}

int v3[3];

float running_time = 0.0f;
void RenderingGeometryApp::update(float dt)
{
	running_time += dt;
	transform.m_model = glm::mat4(1) * glm::rotate(glm::mat4(1), running_time, glm::vec3(1,0,0));
	m_view = glm::lookAt(glm::vec3(0, 0, 20), glm::vec3(0), glm::vec3(0, 1, 0));
	m_projection = glm::perspective(glm::quarter_pi<float>(), 800 / (float)600, 0.1f, 1000.f);
}

float speed = 3;
void RenderingGeometryApp::draw()
{

	glUseProgram(shader->m_program);

	if (ImGui::SliderInt3("Position", v3, -100, 100));
	auto trans = glm::translate(transform.m_model, glm::vec3(v3[0], v3[1], v3[2]));
	
	glm::mat4 mvp = m_projection * m_view * transform.m_model * trans;

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

	for (float i = 0; i < np; i++)
	{
		float angle = glm::pi<float>() / ((float)np - 1);
		float theta = i * angle;
		points.push_back(glm::vec4(glm::cos(theta) * radius, glm::sin(theta) * radius, 0, 1));
	}
	return points;
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

void RenderingGeometryApp::genPlane()
{
	std::vector<unsigned int> indices = { 0, 1, 2, 2, 3, 0 };
	MeshRenderer::Vertex A = { glm::vec4(-10, 10, 0, 1), glm::vec4(1, 0, 0, 1) };
	MeshRenderer::Vertex B = { glm::vec4(10, 10, 0, 1), glm::vec4(0, 1, 0, 1) };
	MeshRenderer::Vertex C = { glm::vec4(10, -10, 0, 1), glm::vec4(0, 0, 1, 1) };
	MeshRenderer::Vertex D = { glm::vec4(-10, -10, 0, 1), glm::vec4(0, 0, 0, 1) };
	std::vector<MeshRenderer::Vertex> vertices = { A, B, C, D };

	mesh->initialize(indices, vertices);
}

std::vector<glm::vec4> RenderingGeometryApp::genSphere(int radius, int numPoints, int meridians)
{
	std::vector<glm::vec4> points = genHalfCircle(numPoints, radius);

	std::vector<glm::vec4> totalPoints;

	for (float i = 0; i <= meridians; i++)
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

	std::vector<unsigned int> indices = genIndices(numPoints, meridians);
	std::vector<MeshRenderer::Vertex> vertices;

	for (int i = 0; i < totalPoints.size(); i++)
	{
		MeshRenderer::Vertex vertex = { totalPoints[i], glm::vec4(1) };
		vertices.push_back(vertex);
	}
	
	mesh->initialize(indices, vertices);

	return totalPoints;
}

std::vector<glm::vec4> RenderingGeometryApp::genCube()
{
	std::vector<MeshRenderer::Vertex> vertices
	{
	//front
	{ glm::vec4(0.0, 1.0, 1.0, 1.0), glm::vec4(1, 0, 0, 1) },
	{ glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(0, 1, 0, 1) },
	{ glm::vec4(1.0, 0.0, 1.0, 1.0), glm::vec4(0, 0, 1, 1) },
	{ glm::vec4(0.0, 0.0, 1.0, 1.0), glm::vec4(1, 1, 0, 1) },
	//bot
	{ glm::vec4(0.0, 0.0, 0.0, 1.0), glm::vec4(1, 0, 0, 1) },
	{ glm::vec4(1.0, 0.0, 0.0, 1.0), glm::vec4(0, 1, 1, 1) },
	//back
	{ glm::vec4(1.0, 1.0, 0.0, 1.0), glm::vec4(1, 1, 1, 1) },
	{ glm::vec4(0.0, 1.0, 0.0, 1.0), glm::vec4(1, 0, 0, 1) },
	//top
	{ glm::vec4(0.0, 1.0, 1.0, 1.0), glm::vec4(1, 1, 1, 1) },
	{ glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1, 0, 1, 1) },
	//right
	{ glm::vec4(1.0, 1.0, 0.0, 1.0), glm::vec4(1, 0, 1, 1) },
	{ glm::vec4(1.0, 0.0, 0.0, 1.0), glm::vec4(1, 0, 1, 1) },
	//left
	{ glm::vec4(1.0, 1.0, 0.0, 1.0), glm::vec4(1, 0, 1, 1) },
	{ glm::vec4(0.0, 0.0, 0.0, 1.0), glm::vec4(1, 0, 0, 1) }
	};

	std::vector<unsigned int> indices =
	{

		0,1,2,2,3,0,//front
		3,2,4,4,5,2,//Bot
		4,5,6,6,7,4,//Back
		6,7,8,8,9,6,//Top
		2,1,10,10,11,2,//Right
		0,3,12,12,13,0//Left
	};

	mesh->initialize(indices, vertices);
	return std::vector<glm::vec4>();
}