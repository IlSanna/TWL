#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"

using namespace sf;

class Engine {
private:
	TextureHolder th;

	Thomas m_Thomas;
	Bob m_Bob;

	const int TILE_SIZE = 50;//each tile in the sprite sheet is fifty pixels wide and fifty pixels high.
	const int VERTEX_IN_QUAD = 4;

	// The force pushing the characters down
	const int GRAVITY = 300;

	// A regular RenderWindow
	RenderWindow m_Window;
	// The main Views
	View m_MainView;
	View m_LeftView;
	View m_RightView;
	// Three views for the background
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;

	View m_HudView;
	
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	
	bool m_Playing = false;// Is the game currently playing?
	bool m_Character1 = true;// Is character 1 or 2 the current focus of the camera
	bool m_SplitScreen = false;//or fullscreen
	
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;
	
	bool m_NewLevelRequired = true;// Is it time for a new/first level?
	
	void input();
	void update(float deltaTimeAsSeconds);
	void draw();
public:
	Engine();
	
	void run();// Run will call all the private functions
};
