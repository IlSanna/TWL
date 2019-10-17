#include "PlayableCharacter.h"

void PlayableCharacter::spawn(Vector2f startPosition, float gravity) {
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	m_Gravity = gravity;

	m_Sprite.setPosition(m_Position);
	m_Sprite.setScale(0.5, 0.5);
}

void PlayableCharacter::update(float elapsedTime) {
	if (m_RightPressed) { m_Position.x += m_Speed * elapsedTime; }
	if (m_LeftPressed) { m_Position.x -= m_Speed * elapsedTime; }

	// Handle Jumping
	if (m_IsJumping) {
		m_ThisJumpDuration += elapsedTime;//how long the jump has been going
		
		if (m_ThisJumpDuration < m_JumpDuration) { //is going up and didnt reach the max jump duration
			m_Position.y -= m_Gravity * 2 * elapsedTime;// Move up at twice gravity
		}
		else {
			m_IsJumping = false;
			m_IsFalling = true;
		}
	}
	if (m_IsFalling) { m_Position.y += m_Gravity * elapsedTime; }//fall

	FloatRect r = getPosition();//update boundaries
	//set bounding box
	m_Feet.left = r.left + 3;
	m_Feet.top = r.top + r.height - 1;
	m_Feet.width = r.width - 6;
	m_Feet.height = 1;
}