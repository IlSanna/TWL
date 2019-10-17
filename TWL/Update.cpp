#include "Engine.h"
#include <sstream>


void Engine::update(float deltaTimeAsSeconds) {
	if (m_Playing) {
		
		m_TimeRemaining -= deltaTimeAsSeconds;// Count down the time the player has left
		
		if (m_TimeRemaining <= 0) {
			m_NewLevelRequired = true;
		}
	}//endPlaying
}