#include "platform.h"

platform::platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(size); //stworzenie cia�a platformy
	body.setOrigin(size/2.0f);
	body.setTexture(texture);
	body.setPosition(position);
}

platform::~platform()
{
}

void platform::Draw(sf::RenderWindow& window)
{
	window.draw(body); //rysowanie
}
