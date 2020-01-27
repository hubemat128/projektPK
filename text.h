#pragma once
#include <SFML/Graphics.hpp>
class text
{
public:
	text(int x, int y);
	sf::Text tekst;
	sf::Font font;
	void loadFont();
	void setString(std::string s); 
};
