#define GLM_FORCE_SWIZZLE
#include "gl_core_4_4.h"
#include "RenderingGeometryApp.h"
#include <imgui.h>
#include "Shader.h"
#include <imgui_internal.h>
#include "iostream"


RenderingGeometryApp::RenderingGeometryApp()
{
}

RenderingGeometryApp::~RenderingGeometryApp()
{
}

void RenderingGeometryApp::startup()
{
	std::vector<unsigned int> indices = { 0, 1, 2, 2, 3, 0 };
	MeshRenderer::Vertex A = { glm::vec4(-10, 10, 0, 1), glm::vec4(1, 0, 0, 1) };
	MeshRenderer::Vertex B = { glm::vec4(10, 10, 0, 1), glm::vec4(0, 1, 0, 1) };
	MeshRenderer::Vertex C = { glm::vec4(10, -10, 0, 1), glm::vec4(0, 0, 1, 1) };
	MeshRenderer::Vertex D = { glm::vec4(-10, -10, 0, 1), glm::vec4(0, 0, 0, 1) };
	std::vector<MeshRenderer::Vertex> vertices = { A, B, C, D };

	mesh = new MeshRenderer();
	mesh->initialize(indices, vertices);

	shader = new Shader();
	shader->Initialize("#version 410\n \
                            layout(location = 0) in vec4 Position; \
                            layout(location = 1) in vec4 Color; \
                            out vec4 vColor; \
                            uniform mat4 ProjectionViewWorld; \
                            void main() { vColor = Color; \
                            gl_Position = ProjectionViewWorld * Position; }",

							"#version 410\n \
                            in vec4 vColor; \
                            out vec4 FragColor; \
                            void main() { FragColor = vColor; }");
	
	//const char* vsSource = "#version 410\n \
 //                           layout(location = 0) in vec4 Position; \
 //                           layout(location = 1) in vec4 Color; \
 //                           out vec4 vColor; \
 //                           uniform mat4 ProjectionViewWorld; \
 //                           void main() { vColor = Color; \
 //                           gl_Position = ProjectionViewWorld * Position; }";
	//
	//const char* fsSource = "#version 410\n \
 //                           in vec4 vColor; \
 //                           out vec4 FragColor; \
                            void main() { FragColor = vColor; }";


}

void RenderingGeometryApp::update(float dt)
{
	m_model = glm::mat4(1);
	glm::vec3 eye = glm::vec3(0, -20, -20);
	m_view = glm::lookAt(eye, m_model[3].xyz(), glm::vec3(0, 1, 0));
	m_projection = glm::perspective(glm::quarter_pi<float>(), 800 / (float)600, 0.1f, 1000.f);
}

void RenderingGeometryApp::draw()
{
	glUseProgram(shader->m_program);

	//get an id that is the variable from the shader
	int variableId = glGetUniformLocation(shader->m_program, "ProjectionViewWorld");

	//create a variable to send
	glm::mat4 mvp = m_projection * m_view * m_model;

	//send the variable
	glUniformMatrix4fv(variableId, 1, GL_FALSE, &mvp[0][0]);

	mesh->render();

	if (ImGui::Button("UP", ImVec2(100, 100)))
	{
		mesh->Move(glm::vec4(0, 100, 0, 0));
	}
	if (ImGui::Button("DOWN", ImVec2(100, 100)))
	{
		mesh->Move(glm::vec4(0, -100, 0, 0));
	}
	if (ImGui::Button("LEFT", ImVec2(100, 100)))
	{
		mesh->Move(glm::vec4(-100, 0, 0, 0));
	}
	if (ImGui::Button("RIGHT", ImVec2(100, 100)))
	{
		mesh->Move(glm::vec4(100, 0, 0, 0));
	}

	glUseProgram(0);
}

void RenderingGeometryApp::shutdown()
{
	
}