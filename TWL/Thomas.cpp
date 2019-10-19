#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas() {
	m_Sprite = Sprite(TextureHolder::GetTexture("src/graphics/thomas.png"));
	m_JumpDuration = .45;
}

bool Thomas::handleInput() {
	if (Keyboard::isKeyPressed(Keyboard::W)) {
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
	Keyboard::isKeyPressed(Keyboard::A) ? m_LeftPressed = true : m_LeftPressed = false;
	Keyboard::isKeyPressed(Keyboard::D) ? m_RightPressed = true : m_RightPressed = false;

	return m_JustJumped;//for sound only
}