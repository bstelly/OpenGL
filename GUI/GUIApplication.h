#pragma once
#include <Application.h>

class GUIApplication : public Application
{
public:
	GUIApplication();
	~GUIApplication();
	void startup() override;
	void shutdown() override;
	void update(float dt) override;
	void draw() override;
};