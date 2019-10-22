#include "HUD.h"

HUD::HUD() {
	Vector2u resolution;
	resolution.x = VideoMode::getDesktopMode().width/2;
	resolution.y = VideoMode::getDesktopMode().height/2;
	
	m_Font.loadFromFile("src/fonts/Roboto-Light.ttf");
	// when Paused
	m_StartText.setFont(m_Font);
	m_StartText.setCharacterSize(60);
	m_StartText.setFillColor(Color::White);
	m_StartText.setString("Press Enter when ready!");
	FloatRect textRect = m_StartText.getLocalBounds();
	m_StartText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_StartText.setPosition(resolution.x / 2.0f, resolution.y / 2.0f);
	
	// Time
	m_TimeText.setFont(m_Font);
	m_TimeText.setCharacterSize(40);
	m_TimeText.setFillColor(Color::White);
	m_TimeText.setPosition(resolution.x - 150, 0);
	m_TimeText.setString("------");
	
	// Level
	m_LevelText.setFont(m_Font);
	m_LevelText.setCharacterSize(40);
	m_LevelText.setFillColor(Color::White);
	m_LevelText.setPosition(25, 0);
	m_LevelText.setString("1");
}
Text HUD::getMessage() {
	return m_StartText;
}
Text HUD::getLevel() {
	return m_LevelText;
}
Text HUD::getTime() {
	return m_TimeText;
}
void HUD::setLevel(String text) {
	m_LevelText.setString(text);
}
void HUD::setTime(String text) {
	m_TimeText.setString(text);
}