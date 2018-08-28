#include "IntroductionApp.h"
#include "gl_core_4_4.h"
#include <glfw3.h>
#include "Gizmos.h"
#include "Transform.h"


void IntroductionApp::startup()
{
	Gizmos::create();
}

void IntroductionApp::update(float dt)
{
	Transform transform = Transform();
	transform.m_model = model;
	model = transform.Rotate(dt, glm::vec3(0, 1, 0));
}

IntroductionApp::IntroductionApp()
{
}


IntroductionApp::~IntroductionApp()
{
}

void IntroductionApp::draw()
{
	Gizmos::addSphere(glm::vec3(0, 0, 0), 10, 100, 100, glm::vec4(.05, .05, .50, 1), &model);
	Gizmos::draw(projection * view * model);
	
}

void IntroductionApp::shutdown()
{

}
