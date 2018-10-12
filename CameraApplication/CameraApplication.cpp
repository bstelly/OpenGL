#include "CameraApplication.h"
#include "Gizmos.h"
#include <Transform.h>


CameraApplication::CameraApplication()
{

}

CameraApplication::~CameraApplication()
{

}

void CameraApplication::startup()
{
	Gizmos::create();
	cam->SetLookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	cam->SetPerspective(90, 16 / 9.0f, 0.1f, 1000.0f);

}

void CameraApplication::update(float dt)
{
	//Transform transform = Transform();
	//transform.m_model = model;
	//model = transform.Rotate(dt, glm::vec3(0, 1, 0));
}

void CameraApplication::draw()
{
	Gizmos::draw(cam->GetProjection() * cam->GetView() *  cam->GetWorldTransform());
}

void CameraApplication::shutdown()
{
	Gizmos::destroy();
}