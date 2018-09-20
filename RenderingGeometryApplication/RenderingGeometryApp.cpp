#define GLM_FORCE_SWIZZLE
#include "gl_core_4_4.h"
#include "RenderingGeometryApp.h"
#include <imgui.h>
#include "Shader.h"
#include <imgui_internal.h>
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
	std::vector<glm::vec4> points = genHalfCircle(6);


	std::vector<unsigned int> indices = { 0, 1, 2, 2, 3, 0 };
	MeshRenderer::Vertex A = { glm::vec4(-2, 2, 0, 1), glm::vec4(0, 1, 0, 1) };
	MeshRenderer::Vertex B = { glm::vec4(2, 2, 0, 1), glm::vec4(1, 0, 0, 1) };
	MeshRenderer::Vertex C = { glm::vec4(2, -2, 0, 1), glm::vec4(0, 0, 1, 1) };
	MeshRenderer::Vertex D = { glm::vec4(-2, -2, 0, 1), glm::vec4(1, 0.5, 0, 1) };
	std::vector<MeshRenderer::Vertex> vertices = { A, B, C, D };
	//for (int i = 0; i < points.size(); i++)
	//{
	//	vertices.push_back(MeshRenderer::Vertex({ glm::vec4(points[i].x * 10, points[i].y * 10, 0, 1), glm::vec4(0, 0, 1, 1) }));
	//}
	


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
	int ypos = 4;
	int xMultiple = 0;
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

std::vector<glm::vec4> RenderingGeometryApp::genHalfCircle(int np)
{
	glm::vec4 point;
	std::vector<glm::vec4> points;

	float angle = 3.14 / np;
	for (float theta = 0; theta < 3.14; theta += angle)
	{
		points.push_back(glm::vec4(glm::cos(theta), glm::sin(theta), 0, 1));
	}
	return points;
}

void RenderingGeometryApp::genSphere(std::vector<glm::vec4> points, int numRotations)
{

}