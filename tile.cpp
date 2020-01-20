#include "tile.h"


Tile::Tile(float x, float y, int tiletype)
{
	
	tile_type = tiletype;
	if (tile_type == 0)
	{
		rect.setSize(sf::Vector2f(128, 128));
		rect.setPosition(sf::Vector2f(x, y));
		//sprite.setPosition(rect.getPosition());

		rect.setFillColor(sf::Color::Yellow);
		rect.setOutlineColor(sf::Color::Black);
		rect.setOutlineThickness(2);

	}
	if (tile_type == 1)
	{
		rect.setSize(sf::Vector2f(128, 128));
		rect.setPosition(sf::Vector2f(x, y));
		//sprite.setPosition(rect.getPosition());

		rect.setFillColor(sf::Color::Blue);
		rect.setOutlineColor(sf::Color::Black);
		rect.setOutlineThickness(2);

	}
	
}
