#include "Engine.h"

void Engine::loadLevel() {
	m_Playing = false;

	// Delete the previously allocated memory
	for (int i = 0; i < m_LM.getLevelSize().y; ++i) { delete[] m_ArrayLevel[i]; }
	delete[] m_ArrayLevel;
	
	// Load the next 2d array with the map for the level
	m_ArrayLevel = m_LM.nextLevel(m_VALevel);//m_VALevel è una ref

	m_TimeRemaining = m_LM.getTimeLimit();
	m_Thomas.spawn(m_LM.getStartPosition(), GRAVITY);
	m_Bob.spawn(m_LM.getStartPosition(), GRAVITY);
	m_NewLevelRequired = false;
}