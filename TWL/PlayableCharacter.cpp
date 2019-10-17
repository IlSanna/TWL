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

	//set bounding box for feet pos
	m_Feet.left = r.left + 3;
	m_Feet.top = r.top + r.height - 1;
	m_Feet.width = r.width - 6;
	m_Feet.height = 1;
	//set bounding box for Head pos
	m_Head.left = r.left;
	m_Head.top = r.top + (r.height * .3);
	m_Head.width = r.width;
	m_Head.height = 1;
	//set bounding box for Right
	m_Right.left = r.left + r.width - 2;
	m_Right.top = r.top + r.height * .35;
	m_Right.width = 1;
	m_Right.height = r.height * .3;
	//set bounding box for Left
	m_Left.left = r.left;
	m_Left.top = r.top + r.height * .5;
	m_Left.width = 1;
	m_Left.height = r.height * .3;

	m_Sprite.setPosition(m_Position);
}