#include <SFML\Graphics.hpp>
#include <iostream>
#include "player.h"
#include "platform.h"
#include "tile.h"
#include <iomanip>
int main()
{
	
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Sokoban",sf::Style::Close | sf::Style::Titlebar); //stworzenie okna gry
	//sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f)); //konstruktor gracza (X/Y)
	//player.setFillColor(sf::Color::Yellow); //wype³nienie kolorem
	
	sf::Texture playerTexture;
	playerTexture.loadFromFile("duzotuxow2.png");
	
	sf::Font font;
	font.loadFromFile("arial.ttf");
	
	
	player player(&playerTexture, sf::Vector2u(3, 2), 0.3f, 200.0f);
	float deltaTime = 0.0f;
	sf::Clock clock;
	float totalTime = 0;
	Tile tile_movement(256, 256, 1);
	
	std::vector<Tile> tiles;
	int array[8][6] = { 
	{0,0,0,3,3,3},
	{0,0,0,0,0,3},
	{0,0,0,0,0,3},
	{0,0,0,0,0,3},
	{0,0,0,0,0,3},
	{0,0,0,2,0,3},
	{0,0,0,0,0,3},
	{0,0,3,3,3,3} };
	for (auto i = 0; i < 8; i++)
	{
		for (auto j = 0; j < 6; j++)
		{
			tiles.emplace_back(i * 128, j * 128, array[i][j]);
		}
	}
	
	
	
	//platform platform3(nullptr, sf::Vector2f(150.0f, 150.0f), sf::Vector2f(800.0f, 200.0f));


	/*sf::Vector2u textureSize =playerTexture.getSize();
	textureSize.x /= 3;
	textureSize.y /= 9;
	
	player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 8, textureSize.x, textureSize.y)); */

	while (window.isOpen()) //gameloop
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type) //zamkniêcie okna
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		
		player.Update(deltaTime);
		totalTime += deltaTime;
		std::string totalTimeS = std::to_string(totalTime);
		sf::Text text(totalTimeS, font);
		text.setPosition(870, 100);
		text.setCharacterSize(30);
		text.setStyle(sf::Text::Bold);
		text.setFillColor(sf::Color::White);
		text.setOutlineColor(sf::Color::Black);
		text.setOutlineThickness(1);
		
		window.clear(sf::Color(150,150,150)); //czyszczenie bufora
		/*for (auto tile : tiles) {
			if (platform2.body.getGlobalBounds().intersects(tile.rect.getGlobalBounds()) && tile.tile_type==1){
				std::cout << "dziala";
				
			}
			window.draw(tile.rect);
		}*/
		
		if(tile_movement.tile_type == 1)
			{
			tile_movement.move_tile(player);
			}
		
		//window.draw(tile_movement.rect);
		for(auto tile : tiles)
				{
			window.draw(tile.rect);
		}
		
		for (auto& tile : tiles) {
					
				if(tile.tile_type == 3 && player.body.getGlobalBounds().intersects(tile.rect.getGlobalBounds()))
				{
					tile.collision_player(player);
					std::cout << "dziala" << std::endl;
				}
			if(tile.tile_type == 3 && tile_movement.rect.getGlobalBounds().intersects(tile.rect.getGlobalBounds()))
				{
				tile_movement.collision_tile(player);
				
				std::cout << "kolzija tile-tile dziala" << std::endl;
				}

				tile.center();
				tile_movement.center();
			 if(tile.tile_type == 2 && tile.center_x == tile_movement.center_x && tile.center_y == tile_movement.center_y)
			 	{
				std::cout << " Runda zaje³a Ci : "<< totalTime << std::endl;
			 	std::cout << "Koniec gry spierdalaj dziadzie" << std::endl;
			 	std::cout << "Press enter to exit!\n";
			 	
			 	std::cin.ignore();
			 	window.close();
		 	}
			
		}
		
		
		
		window.draw(tile_movement.rect);
		window.draw(text);
		player.Draw(window);
		
	
		window.display();

	}

	
	return 0;
}