#include "Engine.h"

void Engine::draw() {

	m_Window.clear(Color::White);

	if (!m_SplitScreen) {//fullscreen
		// Switch to background view
		m_Window.setView(m_BGMainView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_MainView);// Switch to m_MainView
	}
	else { // Split screen view is active
		
		// Draw left side
		m_Window.setView(m_BGLeftView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_LeftView);

		// Draw right side
		m_Window.setView(m_BGRightView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_RightView);
	}
	
	m_Window.setView(m_HudView);// Draw the HUD

	m_Window.display();
}