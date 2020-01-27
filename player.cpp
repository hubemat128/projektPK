#include "player.h"

player::player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	
	faceRight = true; //sprawdzenie w ktora strone gracz jest obrocony 
	body.setSize(sf::Vector2f(53.0f, 75.0f)); //wielkoœæ gracza gracza (X/Y)
	
	body.setPosition(200.0f, 200.0f);
	
	
	body.setTexture(texture); //ustawianie tekstury
	
}

player::~player()
{
}

void player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //poruszanie siê
	{
		mov = 1;
		movement.x -= speed * deltaTime; //poruszanie siê wzglêdem czasu
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{	
		mov = 2;
		movement.x += speed * deltaTime;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		mov = 3;
		movement.y -= speed * deltaTime;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		mov = 4;
		movement.y += speed * deltaTime;
	}

	if (movement.x == 0.0f) {
		row = 0;
	}
	else {
		row = 1;
		if (movement.x > 0.0f) 
			faceRight = true;
		
		else 
			faceRight = false;
		
	
	}
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
