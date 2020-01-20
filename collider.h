#pragma once
#include <SFML/Graphics.hpp>
class collider
{
public:
	collider(sf::RectangleShape& body);
	~collider();

	void Move(float dx, float dy) { body.move(dx, dy); }

	bool CheckCollider(collider other, float push);
	sf::Vector2f GetPostion() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }
private:
	sf::RectangleShape& body;

};

