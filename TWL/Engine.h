#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "LevelManager.h"
#include "HUD.h"

using namespace sf;

class Engine {
private:
	TextureHolder th;

	Thomas m_Thomas;
	Bob m_Bob;

	LevelManager m_LM;

	HUD m_HUD;
	int m_FramesSinceLastHUDUpdate = 0;
	int m_TargetFramesPerHUDUpdate = 500;

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
	bool m_Character1 = false;// Is character 1 or 2 the current focus of the camera
	bool m_SplitScreen = false;//or fullscreen
	
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;
	
	bool m_NewLevelRequired = true;// Is it time for a new/first level?
	
	// The vertex array for the level tiles
	VertexArray m_VALevel;
	// The 2d array with the map for the level
	int** m_ArrayLevel = NULL;
	// Texture for the level tiles
	Texture m_TextureTiles;

	void loadLevel();
	bool detectCollisions(PlayableCharacter& character);//polymorphic argument

	void input();
	void update(float deltaTimeAsSeconds);
	void draw();
public:
	Engine();
	
	void run();// Run will call all the private functions
};
