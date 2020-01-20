#pragma once
#include <SFML/Graphics.hpp>

class Tile 
{
public: 
	Tile(float x, float y, int tiletype);
	//int getTileType;
	
	int tile_type;
	sf::Texture texture;
	sf::RectangleShape rect;
	sf::Sprite sprite;

};

