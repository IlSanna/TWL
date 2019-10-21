#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter& character) {
	bool reachedGoal = false;
	
	// Make a rect for all his parts
	FloatRect detectionZone = character.getPosition();
	
	FloatRect block;//each tile
	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	// Build a zone around thomas to detect collisions
	int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;
	// Thomas is quite tall so check a few tiles vertically
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3;
	
	// Make sure we don't test positions lower than zero
	// Or higher than the end of the array
	if (startX < 0) { startX = 0; }
	if (startY < 0) { startY = 0; }
	if (endX >= m_LM.getLevelSize().x) { endX = m_LM.getLevelSize().x; }
	if (endY >= m_LM.getLevelSize().y) { endY = m_LM.getLevelSize().y; }

	FloatRect level(0, 0,m_LM.getLevelSize().x * TILE_SIZE, m_LM.getLevelSize().y * TILE_SIZE);//map size rectangle
	if (!character.getPosition().intersects(level)) { //fall out
		character.spawn(m_LM.getStartPosition(), GRAVITY);
	}

	//all tiles near player
	for (int x = startX; x < endX; x++) {
		for (int y = startY; y < endY; y++) {
			// Initialize the starting position of the current block
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;
			if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 3) {//fire or water tiles
				if (character.getHead().intersects(block)) {
					character.spawn(m_LM.getStartPosition(), GRAVITY);
					//// fire
					//if (m_ArrayLevel[y][x] == 2) {}// Play a sound 
					//// Water
					//else {}// Play a sound
				}
			}
			// Is character colliding with a regular block
			if (m_ArrayLevel[y][x] == 1) {
				if (character.getRight().intersects(block)) {
					character.stopRight(block.left);
				}
				else if (character.getLeft().intersects(block)) {
					character.stopLeft(block.left);
				}
				if (character.getFeet().intersects(block)) {
					character.stopFalling(block.top);
				}
				else if (character.getHead().intersects(block)) {
					character.stopJump();
				}
			}
			// Has the character reached the goal?
			if (m_ArrayLevel[y][x] == 4) {
				reachedGoal = true;
			}
		}//inner loop
	}//outer loop
	return reachedGoal;
}