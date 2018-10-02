#pragma once

class Entity
{
public:
	Entity();
	~Entity();

	Entity* Polymorph();

private:
	const char* m_name;

};