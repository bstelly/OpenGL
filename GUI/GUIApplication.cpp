#include "GUIApplication.h"
#include <imgui.h>
#include <imgui_internal.h>

GUIApplication::GUIApplication()
{
	
}

GUIApplication::~GUIApplication()
{
	
}

void GUIApplication::startup()
{
	
}

void GUIApplication::update(float dt)
{
	
}


void GUIApplication::draw()
{	
	if(ImGui::Button("A Button", ImVec2(300, 100)))
	{
		int a = 0;
	}
}

void GUIApplication::shutdown()
{
	
}