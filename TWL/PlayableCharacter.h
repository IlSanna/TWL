#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class PlayableCharacter {
protected:
	Sprite m_Sprite;

	float m_JumpDuration;
	float m_ThisJumpDuration;// How long has this jump lasted so far

	bool m_IsJumping;
	bool m_IsFalling;
	bool m_JustJumped = false;// Has the player just initialted a jump
	bool m_LeftPressed;
	bool m_RightPressed;

private:
	float m_Gravity;//pixel momevement in the y axis
	float m_Speed = 400;//pixel momevement in the x axis
	Vector2f m_Position;

	//player boundaries
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;

	Texture m_Texture;
public:
	bool virtual handleInput() = 0;//pure virtual,This class is now abstract and cannot be instanciated

	void spawn(Vector2f startPosition, float gravity);
	void update(float elapsedTime);
	
	FloatRect getPosition();
	Vector2f getCenter();
	Sprite getSprite();

	// Boundaries getters
	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getRight();
	FloatRect getLeft();
	
	// Make the character stand firm
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();
};