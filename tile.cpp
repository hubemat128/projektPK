#include "tile.h"


Tile::Tile(float x, float y, int tiletype)
{
	
	tile_type = tiletype; //typy odpowiednich blokow
	if (tile_type == 0)
	{
		rect.setSize(sf::Vector2f(64, 64)); // wielkosc
		rect.setPosition(sf::Vector2f(x, y)); //pozycja
		//sprite.setPosition(rect.getPosition());
		rect.setFillColor(sf::Color(130,130,130)); //kolor, obecnie jest juz tekstura
		
		//rect.setOutlineColor(sf::Color::Black);
		//rect.setOutlineThickness(2);
		
		
	}
	if (tile_type == 1)
	{
		rect.setSize(sf::Vector2f(64, 64));
		rect.setPosition(sf::Vector2f(x, y));
		//sprite.setPosition(rect.getPosition());
		rect.setFillColor(sf::Color::Blue);
		rect.setOutlineColor(sf::Color::Black);
		rect.setOutlineThickness(2);

		//texture.loadFromFile("sprites/crate.png");
		//sprite.setTexture(texture);

	}
	if (tile_type == 2)
	{
		rect.setSize(sf::Vector2f(64, 64));
		rect.setPosition(sf::Vector2f(x, y));
		
		rect.setFillColor(sf::Color::Red);
		rect.setOutlineColor(sf::Color::Black);
		rect.setOutlineThickness(2);

		
		

	}
	if (tile_type == 3)
	{
		rect.setSize(sf::Vector2f(64, 64));
		rect.setPosition(sf::Vector2f(x, y));

		rect.setFillColor(sf::Color::Black);
		//rect.setOutlineColor(sf::Color::Black);
		//rect.setOutlineThickness(2);
		
		


	}

}
void Tile::center() //wyznaczanie srodka
{
	center_x = rect.getPosition().x + 32;
	center_y = rect.getPosition().y + 32;		
}
void Tile::move_tile(player player) //poruszanie sie obiektu
{
	if(player.body.getGlobalBounds().intersects(rect.getGlobalBounds()) && player.mov == 1) // a
	{
		
		rect.setPosition(rect.getPosition().x - 8, rect.getPosition().y);  //popchniecie w wybranej plaszczyznie +/- odpowiednia ilosc pikseli
	}
	
	if(player.body.getGlobalBounds().intersects(rect.getGlobalBounds()) && player.mov == 2) //d
	{
		rect.setPosition(rect.getPosition().x + 8, rect.getPosition().y);
	}
	
	if(player.body.getGlobalBounds().intersects(rect.getGlobalBounds()) && player.mov == 3) //w
	{
		rect.setPosition(rect.getPosition().x, rect.getPosition().y-8);
	}
	if(player.body.getGlobalBounds().intersects(rect.getGlobalBounds()) && player.mov == 4) //s
	{
		rect.setPosition(rect.getPosition().x, rect.getPosition().y +8);
	}
}
void Tile::collision_player(player& player) //kolizja gracza wzgledem sciany
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
	
}void Tile::collision_tile( player& player) //kolizja gracza z obiektem ruszajacym sie wzgledem sciany
{

	if (player.mov == 1) // a
	{
		rect.setPosition(rect.getPosition().x + 8, rect.getPosition().y);
		player.body.move(1, 0);
	}

	if ( player.mov == 2) //d
	{
		rect.setPosition(rect.getPosition().x-8, rect.getPosition().y);
		player.body.move(-1, 0);
	}

	if ( player.mov == 3) //w
	{
		rect.setPosition(rect.getPosition().x, rect.getPosition().y+8);
		player.body.move(0, 1);
	}
	if ( player.mov == 4) //s
	{
		rect.setPosition(rect.getPosition().x, rect.getPosition().y - 8);
		player.body.move(0, -1);
	}
}