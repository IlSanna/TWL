#include "Bob.h"
#include "TextureHolder.h"

Bob::Bob() {
	m_Sprite = Sprite(TextureHolder::GetTexture("src/graphics/bob.png"));
	m_JumpDuration = .25;
}
bool Bob::handleInput() {
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		// Start a jump if not already jumping but only if standing on a block (not falling)
		if (!m_IsJumping && !m_IsFalling) {
			m_IsJumping = true;
			m_ThisJumpDuration = 0;
			m_JustJumped = true;
		}
	}
	else {//if i dont press w i will always be at falling state
		m_IsJumping = false;
		m_IsFalling = true;
	}
	Keyboard::isKeyPressed(Keyboard::Left) ? m_LeftPressed = true : m_LeftPressed = false;
	Keyboard::isKeyPressed(Keyboard::Right) ? m_RightPressed = true : m_RightPressed = false;

	return m_JustJumped;
}