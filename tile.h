#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"

class Tile 
{
public: 
	Tile(float x, float y, int tiletype);
	//int getTileType;
	void center();
	void move_tile(player player);
	void collision_player(player &player);
	void collision_tile(player &player);
	int tile_type;
	int center_x;
	int center_y;
	sf::Texture texture;
	sf::RectangleShape rect;
	sf::Sprite sprite;
	

};

