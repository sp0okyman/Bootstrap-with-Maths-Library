#pragma once
#include "matrix_3x3.h"
#include "Texture.h"
#include "Renderer2D.h"
using namespace aie;

class GameObject
{

public:

	GameObject* parent_pointer = nullptr;
	matrix_3x3 world_transform;
	matrix_3x3 local_transform;
	Texture* texture_pointer;

	void Update();
	void Draw(Renderer2D* a_renderer);

	GameObject();

	~GameObject();
};