#include "Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

Entity* Entity::Polymorph()
{
	Entity* temp = new Entity();
	temp->m_name = m_name;
	return temp;
}