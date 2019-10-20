#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;

class LevelManager {
private:
	Vector2i m_LevelSize;//horizontal and vertical number of tiles of the current map
	Vector2f m_StartPosition;//where bob and thomas will be spawned
	float m_TimeModifier = 1;//will be used to multiply the time available in the current level
	float m_BaseTimeLimit = 0;//holds the original, unmodified time limit
	int m_CurrentLevel = 0;
	const int NUM_LEVELS = 4;//will be used to flag when it is appropriate to go back to level one again and reduce the value of m_TimeModifier.
public:
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	float getTimeLimit();
	Vector2f getStartPosition();
	int** nextLevel(VertexArray& rVaLevel);
	Vector2i getLevelSize();
	int getCurrentLevel();
};