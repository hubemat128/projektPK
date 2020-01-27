#include "text.h"
text::text(int x, int y)
{
	tekst.setPosition(x, y);
	tekst.setCharacterSize(30);
	tekst.setStyle(sf::Text::Bold);
	tekst.setFillColor(sf::Color::White);
	tekst.setOutlineColor(sf::Color::Black);
	tekst.setOutlineThickness(1);
	
}
void text::loadFont()
{
	font.loadFromFile("arial.ttf");
	tekst.setFont(font);
}
void text::setString(std::string s) {
	tekst.setString(s);
}