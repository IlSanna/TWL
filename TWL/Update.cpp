#include "Engine.h"
#include <sstream>


void Engine::update(float deltaTimeAsSeconds) {
	if (m_NewLevelRequired) {
		// These calls to spawn will be moved to a new
		// loadLevel() function soon
		// Spawn Thomas and Bob
		m_Thomas.spawn(Vector2f(0, 0), GRAVITY);
		m_Bob.spawn(Vector2f(100, 0), GRAVITY);
		// Make sure spawn is called only once
		m_TimeRemaining = 10;
		m_NewLevelRequired = false;
	}
	if (m_Playing) {
		
		m_Thomas.update(deltaTimeAsSeconds);
		m_Bob.update(deltaTimeAsSeconds);

		m_TimeRemaining -= deltaTimeAsSeconds;// Count down the time the player has left
		
		if (m_TimeRemaining <= 0) {
			m_NewLevelRequired = true;
		}
	}//endPlaying
	// Set the appropriate view around the appropriate character
	if (m_SplitScreen) {
		m_LeftView.setCenter(m_Thomas.getCenter());
		m_RightView.setCenter(m_Bob.getCenter());
	}
	else {
		// Centre full screen around appropriate character
		if (m_Character1) {
			m_MainView.setCenter(m_Thomas.getCenter());
		}
		else {
			m_MainView.setCenter(m_Bob.getCenter());
		}
	}
}