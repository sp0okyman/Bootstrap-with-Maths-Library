#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "vector_2.h"
#include "matrix_3x3.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	

	m_2dRenderer = new aie::Renderer2D();
	m_sun_texture = new aie::Texture("../bin/textures/ShitSun.png");
	m_earth_texture = new aie::Texture("../bin/textures/Earth.png");
	m_moon_texture = new aie::Texture("../bin/textures/Moon.png");

	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_timer = 0;
	m_sun.texture_pointer = m_sun_texture;
	m_earth.texture_pointer = m_earth_texture;
	m_moon.texture_pointer = m_moon_texture;

	m_earth.parent_pointer = &m_sun;
	m_moon.parent_pointer = &m_earth;

	m_sun.local_transform.axes[2] = { 640, 360, 1 };
	
	m_earth.local_transform.axes[2] = { 350, 0, 1 }; 
	// setting scale of earth
	m_earth.obj_scale._2d[0][0] = 0.5f;
	m_earth.obj_scale._2d[1][1] = 0.5f;

	m_moon.local_transform.axes[2] = { 300, 0, 1 };
	// setting scale of moon
	m_moon.obj_scale._2d[0][0] = 0.5f;
	m_moon.obj_scale._2d[1][1] = 0.5f;

	return true;
}

void Application2D::shutdown()
{
	delete m_sun_texture;
	delete m_earth_texture;
	delete m_font;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	m_sun.Update();
	m_earth.Update();
	m_moon.Update();

	m_sun.local_transform.setRotateZ(m_timer * 0.5);

	m_earth.local_transform.setRotateZ(m_timer * 2);
	// setting scale for the earth

	m_moon.local_transform.setRotateZ(m_timer * 10);
	// setting scale for the moon

	// input example
	aie::Input* input = aie::Input::getInstance();

	// Update the camera position using the arrow keys
	float camPosX;
	float camPosY;
	m_2dRenderer->getCameraPos(camPosX, camPosY);

	if (input->isKeyDown(aie::INPUT_KEY_UP))
		camPosY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		camPosY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		camPosX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		camPosX += 500.0f * deltaTime;

	m_2dRenderer->setCameraPos(camPosX, camPosY);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// demonstrate spinning sprite
	//m_2dRenderer->drawSprite(m_sun_texture, 256, 256, 0, 0, m_timer * 5, 1);
	m_sun.Draw(m_2dRenderer);
	m_earth.Draw(m_2dRenderer);
	m_moon.Draw(m_2dRenderer);
	
	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}