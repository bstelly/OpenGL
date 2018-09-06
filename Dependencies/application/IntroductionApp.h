#pragma once
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "Application.h"
#include "FlyCamera.h"

class IntroductionApp : public Application
{
public:
	IntroductionApp();
	~IntroductionApp();

	void startup();
	void shutdown();
	void update(float dt);
	void draw();

	glm::mat4 model = glm::mat4(1);//model
	glm::mat4 view = glm::lookAt(glm::vec3(10, 10, 25), glm::vec3(0), glm::vec3(0, 1, 0));//view
	glm::mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);
	FlyCamera camera = FlyCamera();

};