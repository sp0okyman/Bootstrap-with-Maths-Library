#include "GameObject.h"
#include <ctime>

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::Update()
{
	if (parent_pointer == nullptr)
	{
		world_transform = local_transform;
	}
	else 
	{ 
		world_transform = parent_pointer->world_transform * local_transform;
	}
}

void GameObject::Draw(Renderer2D* a_renderer)
{
	//m_2dRenderer->drawSprite(m_sun_texture, 256, 256, 0, 0, m_timer * 5, 1);
	a_renderer->drawSpriteTransformed3x3(texture_pointer, world_transform);
}