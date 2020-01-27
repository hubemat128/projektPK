#include <SFML\Graphics.hpp>
#include <iostream>
#include <fstream>
#include "player.h"
#include "platform.h"
#include "tile.h"
#include "text.h"

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Sokoban",sf::Style::Close | sf::Style::Titlebar); //stworzenie okna gry
	//sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f)); //konstruktor gracza (X/Y)
	//player.setFillColor(sf::Color::Yellow); //wype³nienie kolorem
	
	sf::Texture playerTexture; // tekstura gracza
	playerTexture.loadFromFile("sprites/duzotuxow2.png");
	
	sf::Texture crateTexture; //tekstura pudelka-popychadelka
	crateTexture.loadFromFile("sprites/crate.png");
	//sf::Font font;
	//font.loadFromFile("arial.ttf");
	std::fstream wynik; 
	
	wynik.open("wynik/wynik.txt", std::ios::out | std::ios::app);//zapis do pliku


	
	player player(&playerTexture, sf::Vector2u(3, 2), 0.3f, 100.0f); //gracz
	float deltaTime = 0.0f;
	sf::Clock clock;
	float totalTime = 0; //odmierzanie czasu 
	Tile tile_movement(256, 256, 1); //stworzenia pudelka

	tile_movement.sprite.setTexture(crateTexture); //ustawienie tekstury pudelka
	
	bool endgame = false;
	
	std::vector<Tile> tiles; //plansza
	int array[16][12] = { 
	{3,3,3,3,3,3,3,3,3,3,3,3},
	{3,0,0,0,0,0,0,0,0,0,0,3},
	{3,0,0,0,0,0,0,0,0,3,0,3},
	{3,0,0,0,0,0,0,0,0,0,0,3},
	{3,0,0,0,0,0,0,0,0,0,0,3},
	{3,0,0,0,0,0,0,0,0,0,0,3},
	{3,0,0,3,0,0,0,3,0,0,0,3},
	{3,0,0,0,0,0,0,0,0,0,0,3},
	{3,0,0,0,0,0,0,0,0,0,0,3},
	{3,0,0,0,0,0,0,0,0,0,0,3},
	{3,0,3,0,0,0,0,0,0,3,0,3},
	{3,0,0,0,0,3,0,0,0,0,0,3},
	{3,0,0,0,0,0,0,0,2,0,0,3},
	{3,0,0,0,0,0,0,0,0,0,0,3},
	{3,0,0,0,0,0,0,0,0,0,0,3},
	{3,3,3,3,3,3,3,3,3,3,3,3} };
	for (auto i = 0; i < 16; i++)
	{
		for (auto j = 0; j < 12; j++)
		{
			tiles.emplace_back(i * 64, j * 64, array[i][j]);
		}
	}
	
	
	
	//platform platform3(nullptr, sf::Vector2f(150.0f, 150.0f), sf::Vector2f(800.0f, 200.0f));


	/*sf::Vector2u textureSize =playerTexture.getSize();
	textureSize.x /= 3;
	textureSize.y /= 9;
	
	player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 8, textureSize.x, textureSize.y)); */
	
	text timer(870, 50);
	timer.loadFont();
	text endText(128, 768/4);
	endText.tekst.setCharacterSize(60);
	endText.loadFont();			//tworzenie tekstow

	sf::Texture backtexture;
	sf::Texture endtexture;
	sf::Texture walltexture; //ladowanie tekstur do nieruszajacych sie obiekt
	
	for(auto& tile:tiles)
	{
		if(tile.tile_type == 0)
		{	
			
			backtexture.loadFromFile("sprites/background.png");
			tile.sprite.setTexture(backtexture);
			tile.sprite.setPosition(tile.rect.getPosition());
		}
		else if(tile.tile_type == 2)
		{
			endtexture.loadFromFile("sprites/end.png");
			tile.sprite.setTexture(endtexture);
			tile.sprite.setPosition(tile.rect.getPosition());
		}
		else if(tile.tile_type == 3)
		{
			walltexture.loadFromFile("sprites/wall.png");
			tile.sprite.setTexture(walltexture);
			tile.sprite.setPosition(tile.rect.getPosition());
		}
	}
	while (window.isOpen()) //gameloop
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) //zamkniêcie okna
			{
			case sf::Event::Closed:
				window.close();

				break;

			}

		}

		player.Update(deltaTime);
		totalTime += deltaTime;
		tile_movement.sprite.setPosition(tile_movement.rect.getPosition());

		std::string totalTimeS = std::to_string(totalTime);
		if (endgame != true)
		{
			timer.setString(totalTimeS);
		}

		//sf::Text text(totalTimeS, font);


		window.clear(sf::Color(150, 150, 150)); //czyszczenie bufora
		/*for (auto tile : tiles) {
			if (platform2.body.getGlobalBounds().intersects(tile.rect.getGlobalBounds()) && tile.tile_type==1){
				std::cout << "dziala";

			}
			window.draw(tile.rect);
		}*/

		if (tile_movement.tile_type == 1)
		{
			tile_movement.move_tile(player);
		}

		//window.draw(tile_movement.rect);
		//for(auto tile : tiles)
			//	{
			//window.draw(tile.rect);
		//}


		for (auto& tile : tiles) {

			if (tile.tile_type == 3 && player.body.getGlobalBounds().intersects(tile.rect.getGlobalBounds()))
			{
				tile.collision_player(player);
				//std::cout << "dziala" << std::endl;
			}
			if (tile.tile_type == 3 && tile_movement.rect.getGlobalBounds().intersects(tile.rect.getGlobalBounds()))
			{
				tile_movement.collision_tile(player);

				//std::cout << "kolzija tile-tile dziala" << std::endl;
			}

			tile.center();
			tile_movement.center();
			if (tile.tile_type == 2 && tile.center_x == tile_movement.center_x && tile.center_y == tile_movement.center_y)
			{
				endText.setString(" Runda zajela Ci : " + totalTimeS + "\n" + " Nacisnij Enter aby wyjsc!");
				tile.rect.setPosition(tile.rect.getPosition().x - 1, tile.rect.getPosition().y - 1);
				//std::cout << " Runda zajela Ci : "<< totalTime << std::endl;
				//std::cout << "Press enter to exit!\n";
			
				wynik << " Twoj czas : " + totalTimeS + "\n" ;
				wynik.close();
				
				
				endgame = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				window.draw(endText.tekst);
				window.close();


			}
			
			window.draw(tile.sprite);
		}


		
		//window.draw(tile_movement.rect);
		window.draw(tile_movement.sprite);
		window.draw(timer.tekst);
		window.draw(endText.tekst);
		player.Draw(window);
		if (endgame == true)
		{
			window.clear(sf::Color::Blue);
			window.draw(endText.tekst);
		}


		window.display();


	}
		

	
	return 0;
}