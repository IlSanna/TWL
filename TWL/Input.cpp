#include "Engine.h"

void Engine::input() {

	Event event;

	while (m_Window.pollEvent(event)) {
		if (event.type == Event::KeyPressed) {
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				m_Window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Return)) {
				m_Playing = true;
			}
			if (Keyboard::isKeyPressed(Keyboard::Q)) { // Switch between Thomas and Bob
				m_Character1 = !m_Character1;
			}
			if (Keyboard::isKeyPressed(Keyboard::E)) { // Switch between full and split screen
				m_SplitScreen = !m_SplitScreen;
			}
		}
	}
}