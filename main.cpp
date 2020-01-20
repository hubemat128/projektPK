#include <SFML\Graphics.hpp>
#include <iostream>
#include "player.h"
#include "platform.h"
#include "tile.h"

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Sokoban",sf::Style::Close | sf::Style::Titlebar); //stworzenie okna gry
	//sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f)); //konstruktor gracza (X/Y)
	//player.setFillColor(sf::Color::Yellow); //wype³nienie kolorem
	
	sf::Texture playerTexture;
	playerTexture.loadFromFile("duzotuxow.png");
	


	player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 200.0f);
	float deltaTime = 0.0f;
	sf::Clock clock;
	Tile tile(50, 50, 0);
	
	std::vector<Tile> tiles;
	int array[8][6] = { 
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,1,0,0,0,0},
	{0,0,0,0,1,0},
	{0,0,0,0,0,0} };
	for (auto i = 0; i < 8; i++)
	{
		for (auto j = 0; j < 6; j++)
		{
			tiles.emplace_back(i * 128, j * 128, array[i][j]);
		}
	}
	
	
	//platform platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
	
	platform platform2(nullptr, sf::Vector2f(150.0f, 150.0f), sf::Vector2f(400.0f, 200.0f));
	
	platform platform3(nullptr, sf::Vector2f(150.0f, 150.0f), sf::Vector2f(800.0f, 200.0f));


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

		//platform1.GetCollider().CheckCollider(player.GetCollider(), 0.0f);
		platform2.GetCollider().CheckCollider(player.GetCollider(), 0.0f);
		platform3.GetCollider().CheckCollider(player.GetCollider(), 1.0f);
		platform3.GetCollider().CheckCollider(platform2.GetCollider(), 1.0f);
		window.clear(sf::Color(150,150,150)); //czyszczenie bufora
		for (auto tile : tiles) {
			if (platform2.body.getGlobalBounds().intersects(tile.rect.getGlobalBounds()) && tile.tile_type==1){
				std::cout << "dziala";
				
			}
			window.draw(tile.rect);
		}
		player.Draw(window); 
		

		//rysowanie gracza
		//platform1.Draw(window);
		platform2.Draw(window);
		platform3.Draw(window);

		window.display();

	}

	return 0;
}