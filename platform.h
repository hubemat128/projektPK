#pragma once
#include <SFML/Graphics.hpp>
#include "collider.h"
class platform : public sf::Sprite
{
public:
	platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~platform();

	void Draw(sf::RenderWindow& window); //rysowanie platformy
	collider GetCollider() { return collider(body); } //zwrocenie ciala
	sf::RectangleShape body;


};

