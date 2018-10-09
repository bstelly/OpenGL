#include "gl_core_4_4.h"
#include "IntroductionApp.h"
#include <glfw3.h>
#include "Gizmos.h"
#include "Transform.h"


void IntroductionApp::startup()
{
	Gizmos::create();
	flyCamera->SetLookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	flyCamera->SetPerspective(90, 16 / 9.0f, 0.1f, 1000.0f);	
	flyCamera->SetSpeed(5.0f);

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
	Gizmos::clear();
	Gizmos::addSphere(glm::vec3(0, 0, 0), 10, 20, 20, glm::vec4(.05, .05, .50, 1), &model);
	Gizmos::draw(flyCamera->GetProjection() * flyCamera->GetView() *  flyCamera->GetWorldTransform());
}

void IntroductionApp::shutdown()
{
	Gizmos::destroy();
}
