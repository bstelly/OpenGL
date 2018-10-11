#pragma once
#include <Application.h>

class CameraApplication : public Application
{
public:
	CameraApplication();
	~CameraApplication();

	void startup();
	void shutdown();
	void update(float dt);
	void draw();
	
	glm::mat4 model = glm::mat4(1);
	glm::mat4 view = glm::lookAt(glm::vec3(10, 10, 25), glm::vec3(0), glm::vec3(0, 1, 0));
	glm::mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);
	Camera* cam = new Camera;
};