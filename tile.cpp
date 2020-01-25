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
	if (tile_type == 2)
	{
		rect.setSize(sf::Vector2f(128, 128));
		rect.setPosition(sf::Vector2f(x, y));
		
		rect.setFillColor(sf::Color::Red);
		rect.setOutlineColor(sf::Color::Black);
		rect.setOutlineThickness(2);




	}
	if (tile_type == 3)
	{
		rect.setSize(sf::Vector2f(128, 128));
		rect.setPosition(sf::Vector2f(x, y));

		rect.setFillColor(sf::Color::White);
		rect.setOutlineColor(sf::Color::Black);
		rect.setOutlineThickness(2);




	}

}
void Tile::center()
{
	center_x = rect.getPosition().x + 64;
	center_y = rect.getPosition().y + 64;		
}
void Tile::move_tile(player player)
{
	if(player.body.getGlobalBounds().intersects(rect.getGlobalBounds()) && player.mov == 1) // a
	{
		
		rect.setPosition(rect.getPosition().x - 2, rect.getPosition().y);
	}
	
	if(player.body.getGlobalBounds().intersects(rect.getGlobalBounds()) && player.mov == 2) //d
	{
		rect.setPosition(rect.getPosition().x + 2, rect.getPosition().y);
	}
	
	if(player.body.getGlobalBounds().intersects(rect.getGlobalBounds()) && player.mov == 3) //w
	{
		rect.setPosition(rect.getPosition().x, rect.getPosition().y-2);
	}
	if(player.body.getGlobalBounds().intersects(rect.getGlobalBounds()) && player.mov == 4) //s
	{
		rect.setPosition(rect.getPosition().x, rect.getPosition().y +2);
	}
}
void Tile::collision_player(player& player)
{

	if ( player.mov == 1) // a
	{
		player.body.move(1,0);
		
	}

	if ( player.mov == 2) //d
	{
		player.body.move(-1, 0);
	}

	if ( player.mov == 3) //w
	{
		player.body.move(0, 1);
	}
	if (player.mov == 4) //s
	{
		player.body.move(0, -1);
	}
	
}void Tile::collision_tile( player& player)
{

	if (player.mov == 1) // a
	{
		rect.setPosition(rect.getPosition().x + 2, rect.getPosition().y);
		player.body.move(1, 0);
	}

	if ( player.mov == 2) //d
	{
		rect.setPosition(rect.getPosition().x-2, rect.getPosition().y);
		player.body.move(-1, 0);
	}

	if ( player.mov == 3) //w
	{
		rect.setPosition(rect.getPosition().x, rect.getPosition().y+2);
		player.body.move(0, 1);
	}
	if ( player.mov == 4) //s
	{
		rect.setPosition(rect.getPosition().x, rect.getPosition().y - 2);
		player.body.move(0, -1);
	}
}