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
	
	transform.m_model = glm::mat4(1);
	std::vector<unsigned int> indices = { 0, 1, 2, 2, 3, 0 };
	MeshRenderer::Vertex A = { glm::vec4(-2, 2, 0, 1), glm::vec4(0, 1, 0, 1) };
	MeshRenderer::Vertex B = { glm::vec4(2, 2, 0, 1), glm::vec4(1, 0, 0, 1) };
	MeshRenderer::Vertex C = { glm::vec4(2, -2, 0, 1), glm::vec4(0, 0, 1, 1) };
	MeshRenderer::Vertex D = { glm::vec4(-2, -2, 0, 1), glm::vec4(1, 0.5, 0, 1) };
	std::vector<MeshRenderer::Vertex> vertices = { A, B, C, D };

	mesh = new MeshRenderer();
	mesh->initialize(indices, vertices);

	shader = new Shader();
	//shader->DefaultLoad("#version 410\n \
 //                       layout(location = 0) in vec4 Position; \
 //                       layout(location = 1) in vec4 Color; \
 //                       out vec4 vColor; \
 //                       uniform mat4 ProjectionViewWorld; \
 //                       void main() { vColor = Color; \
 //                       gl_Position = ProjectionViewWorld * Position; }",

	//					"#version 410\n \
 //                       in vec4 vColor; \
 //                       out vec4 FragColor; \
 //                       void main() { FragColor = vColor; }");
	shader->Load("shader.txt");
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
	
	
	//glm::mat4 mvp = m_projection * m_view * transform.m_model * translation;

	//get an id that is the variable from the shader
	int variableId = glGetUniformLocation(shader->m_program, "ProjectionViewWorld");

	/*glUniformMatrix4fv(variableId, 1, GL_FALSE, &mvp[0][0]);*/

	//mesh->render();
	int ypos = 4;
	int xMultiple = 0;
	for (int i = 0; i < 64; i++)
	{
		glm::mat4 matrix = glm::mat4(1);
		matrix = glm::translate(matrix,glm::vec3(xMultiple * 4, ypos, 0));
		glm::mat4 mvp = m_projection * m_view * matrix * translation;
		glUniformMatrix4fv(variableId, 1, GL_FALSE, &mvp[0][0]);
		mesh->render();
		xMultiple++;
		if (xMultiple == 8)
		{
			ypos -= 4;
			xMultiple = 0;
		}
	}
	//for (int i = 1; i < 8; i++)
	//{
	//	for (int j = 1; j < 8; j++)
	//	{
	//		matrix = glm::mat4(1);
	//		matrix = glm::translate(matrix, glm::vec3(0, 0, 0));
	//		matrix *= glm::translate(glm::mat4(1), glm::vec3(10, 0, 0));

	//		mvp = m_projection * m_view * matrix * translation;
	//		mvp *= transform.Translate(glm::vec3(matrix[0].x + 50, matrix[1].y, matrix[2].z));
	//		glUniformMatrix4fv(variableId, 1, GL_FALSE, &mvp[0][0]);
	//		mesh->render();
	//	}
	//	mvp = m_projection * m_view * matrix * translation;
	//	mvp *= transform.Translate(glm::vec3(m_model[0].x = 0, m_model[1].y - 15, m_model[2].z));
	//	glUniformMatrix4fv(variableId, 1, GL_FALSE, &mvp[0][0]);
	//	mesh->render();
	//}

	glUseProgram(0);
}

void RenderingGeometryApp::shutdown()
{
	
}
