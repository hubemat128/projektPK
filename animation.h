#pragma once
#include <SFML\Graphics.hpp>

class animation
{
public:
	animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime); //wielkosc tekstury, ilosc obrazkow, czas animacji
	~animation();
	void Update(int row, float deltaTime, bool faceRight); //aktualizacja animacji, rzad, czas poprzedniej i obecnej animacji, czy obraca sie w prawo

	sf::IntRect uvRect; // przechowanie
	

private:
	sf::Vector2u imageCount; //ilosc obrazkow
	sf::Vector2u currentImage; //

	float totalTime; //czas kiedy ostatni raz zmienilismy animacje
	float switchTime; //zmiana na nastepny obrazek


};

