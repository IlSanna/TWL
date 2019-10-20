#include "Engine.h"

Engine::Engine() {
	// Get the screen resolution and create an SFML window and View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width/2;
	resolution.y = VideoMode::getDesktopMode().height/2;
	m_Window.create(VideoMode(resolution.x, resolution.y),"Thomas was late", Style::None);
	
	m_MainView.setSize(resolution);
	m_HudView.reset(FloatRect(0, 0, resolution.x, resolution.y));
	// Inititialize the split screen Views
	/*The setViewport function assigns a portion of 
	  the screen to an SFML View object It works using a ratio. 
	  Where “1” is the entire screen (width or height)

	*/
	m_LeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_BGLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

	m_RightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	m_BGRightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	m_BackgroundTexture = TextureHolder::GetTexture("src/graphics/background.png");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	m_TextureTiles = TextureHolder::GetTexture("src/graphics/tiles_sheet.png");
}

void Engine::run() {

	Clock clock;

	while (m_Window.isOpen()) {

		Time deltaTime = clock.restart();
		m_GameTimeTotal += deltaTime;// Update the total game time
		float deltaTimeAsSeconds = deltaTime.asSeconds();

		// Call each part of the game loop in turn
		input();
		update(deltaTimeAsSeconds);
		draw();
	}
}
