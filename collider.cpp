#include "collider.h"

collider::collider(sf::RectangleShape& body):
	body(body)
{
}

collider::~collider()
{
}



bool collider::CheckCollider(collider  other, float push)
{
	sf::Vector2f otherPosition = other.GetPostion();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPostion();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x; //obliczenia roznicy odlegosci x,y
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x); //obliczanie czy doszlo do kolizji w danej p³aszczyznie
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {

		push = std::min(std::max(push, 0.0f), 1.0f); //wartosc push od 0 do 1 powoduje czy obiekt jest przesuwalny czy nie

		if (intersectX > intersectY) { //sprawdzanie w której plaszczyznie doszlo do kolizji, jesli tak to obiekt jest zatrzymywany popychany o odpowiednia ilosc pikseli
			if (deltaX > 0.0f) {
				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);
			}
			else {
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);
			}
		}
		else {
			if (deltaY > 0.0f) {
				Move(0.0f, intersectY * (1.0f - push));
				other.Move(0.0f, -intersectY * push);
			}
			else {
				Move(0.0f, -intersectY * (1.0f - push));
				other.Move(0.0f, intersectY * push);
			}
		}


		return true;
	}


	return false;
}
