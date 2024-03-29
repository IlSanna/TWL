#include "LevelManager.h"
#include "TextureHolder.h"
#include <sstream>
#include <fstream>

int** LevelManager::nextLevel(VertexArray& rVaLevel) {
	m_LevelSize.x = 0;
	m_LevelSize.y = 0;
	// Get the next level
	m_CurrentLevel++;
	if (m_CurrentLevel > NUM_LEVELS) {//if we have already finish the game, restart and decrease the timer
		m_CurrentLevel = 1;
		m_TimeModifier -= .1f;
	}
	string levelToLoad;
	switch (m_CurrentLevel) {
	case 1:
		levelToLoad = "src/levels/level1.txt";
		m_StartPosition.x = 50;
		m_StartPosition.y = 50;
		m_BaseTimeLimit = 70.0f;
		break;
	case 2:
		levelToLoad = "src/levels/level2.txt";
		m_StartPosition.x = 100;
		m_StartPosition.y = 3600;
		m_BaseTimeLimit = 100.0f;
		break;
	case 3:
		levelToLoad = "src/levels/level3.txt";
		m_StartPosition.x = 1250;
		m_StartPosition.y = 0;
		m_BaseTimeLimit = 30.0f;
		break;
	case 4:
		levelToLoad = "src/levels/level4.txt";
		m_StartPosition.x = 50;
		m_StartPosition.y = 200;
		m_BaseTimeLimit = 50.0f;
		break;
	}// End switch

	ifstream inputFile(levelToLoad);
	string s;
	// Count the number of rows in the file
	while (getline(inputFile, s)) { ++m_LevelSize.y; }
	m_LevelSize.x = s.length();// Store the length of the rows
	
	inputFile.clear();// Go back to the start of the file
	/*The seekg function called with the 0,ios::beg parameters
	resets the stream back to before the first character.*/
	inputFile.seekg(0, ios::beg);
	// Prepare the 2d array to hold the int values from the file
	int** arrayLevel = new int* [m_LevelSize.y];
	for (int i = 0; i < m_LevelSize.y; ++i) {
		// init each array with the levelwidth as dimension
		arrayLevel[i] = new int[m_LevelSize.x];
	}
	// Loop through the file and store all the values in the 2d array
	string row;
	int y = 0;
	while (inputFile >> row) {//until EOF
		for (int x = 0; x < row.length(); x++) {
			const char val = row[x];
			arrayLevel[y][x] = atoi(&val);//converts char to int
		}
		y++;
	}
	// close the file
	inputFile.close();
	// What type of primitive are we using?
	rVaLevel.setPrimitiveType(Quads);
	// Set the size of the vertex array
	rVaLevel.resize(m_LevelSize.x * m_LevelSize.y * VERTS_IN_QUAD);
	// Start at the beginning of the vertex array
	int currentVertex = 0;
	for (int x = 0; x < m_LevelSize.x; x++) {
		for (int y = 0; y < m_LevelSize.y; y++) {
			// Position each vertex in the current quad
			rVaLevel[currentVertex + 0].position = Vector2f(x * TILE_SIZE, y * TILE_SIZE);
			rVaLevel[currentVertex + 1].position = Vector2f((x * TILE_SIZE) + TILE_SIZE,y * TILE_SIZE);
			rVaLevel[currentVertex + 2].position = Vector2f((x * TILE_SIZE) + TILE_SIZE, (y * TILE_SIZE) + TILE_SIZE);
			rVaLevel[currentVertex + 3].position = Vector2f(x * TILE_SIZE, (y * TILE_SIZE) + TILE_SIZE);
			// Which tile from the sprite sheet should we use
			int verticalOffset = arrayLevel[y][x] * TILE_SIZE;
			rVaLevel[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
			rVaLevel[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
			rVaLevel[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
			rVaLevel[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);
			
			// Position ready for the next four vertices
			currentVertex = currentVertex + VERTS_IN_QUAD;
		}
	}
	return arrayLevel;
} // End of nextLevel function
		
Vector2i LevelManager::getLevelSize() {
	return m_LevelSize;
}
int LevelManager::getCurrentLevel() {
	return m_CurrentLevel;
}
float LevelManager::getTimeLimit() {
	return m_BaseTimeLimit * m_TimeModifier;
}
Vector2f LevelManager::getStartPosition() {
	return m_StartPosition;
}
