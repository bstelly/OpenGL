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

int v4[4];


void RenderingGeometryApp::update(float dt)
{
	transform.m_model = glm::mat4(1);	
	glm::vec3 eye = glm::vec3(0, -20, 20);
	m_view = glm::lookAt(eye, transform.m_model[3].xyz(), glm::vec3(0, 1, 0));
	m_projection = glm::perspective(glm::quarter_pi<float>(), 800 / (float)600, 0.1f, 1000.f);
}
float speed = 3;
void RenderingGeometryApp::draw()
{

	glUseProgram(shader->m_program);

	
	
	//send the variable 

	if (ImGui::SliderInt4("position", v4, -100, 100));
	translation = transform.Translate(glm::vec3(v4[0]/* * speed*/, v4[1] /** speed*/, v4[2]/* * speed*/));
	//translation *= glm::translate(m_model, glm::vec3(v4[0], v4[1], v4[2]));
	
	
	//create a variable to send
	glm::mat4 mvp = m_projection * m_view * transform.m_model * translation;

	//get an id that is the variable from the shader
	int variableId = glGetUniformLocation(shader->m_program, "ProjectionViewWorld");

	glUniformMatrix4fv(variableId, 1, GL_FALSE, &mvp[0][0]);

	mesh->render();

	//mvp *= transform.Translate(glm::vec3(m_model[0].x, m_model[1].y, m_model[2].z));
	//glUniformMatrix4fv(variableId, 1, GL_FALSE, &mvp[0][0]);
	//mesh->render();

	glUseProgram(0);
}

void RenderingGeometryApp::shutdown()
{
	
}