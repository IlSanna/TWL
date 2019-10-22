#include "Engine.h"
#include <sstream>


void Engine::update(float deltaTimeAsSeconds) {
	if (m_NewLevelRequired) {
		loadLevel();
	}
	if (m_Playing) {
		
		m_Thomas.update(deltaTimeAsSeconds);
		m_Bob.update(deltaTimeAsSeconds);
		
		// Detect collisions 
		if (detectCollisions(m_Thomas) && detectCollisions(m_Bob)) {//one of them reached the goal
			m_NewLevelRequired = true;
		}
		else {
			detectCollisions(m_Bob);//not so sure
		}
		// Let bob and thomas jump on each others heads
		if (m_Bob.getFeet().intersects(m_Thomas.getHead())) {
			m_Bob.stopFalling(m_Thomas.getHead().top);
		}
		else if (m_Thomas.getFeet().intersects(m_Bob.getHead())) {
			m_Thomas.stopFalling(m_Bob.getHead().top);
		}

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
	
	// Increment the number of frames since the last HUD calculation
	m_FramesSinceLastHUDUpdate++;
	if (m_FramesSinceLastHUDUpdate > m_TargetFramesPerHUDUpdate) {
		stringstream ssTime;
		stringstream ssLevel;
		// Update the time text
		ssTime << (int)m_TimeRemaining;
		m_HUD.setTime(ssTime.str());
		// Update the level text
		ssLevel << "Level:" << m_LM.getCurrentLevel();
		m_HUD.setLevel(ssLevel.str());
		m_FramesSinceLastHUDUpdate = 0;
	}
}