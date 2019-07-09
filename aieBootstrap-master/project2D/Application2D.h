#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "GameObject.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	aie::Texture*		m_sun_texture;
	GameObject			m_sun;
	aie::Texture*		m_earth_texture;
	GameObject			m_earth;
	aie::Texture*		m_moon_texture;
	GameObject			m_moon;

	float m_timer;
};