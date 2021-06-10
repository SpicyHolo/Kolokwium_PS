#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class AvengerSprite

{
protected:
	sf::RenderWindow* window;
	sf::Sprite sprite;
	sf::Texture texture;
	float max_velocity;
	sf::Vector2f velocity;

	sf::FloatRect bounds;

	bool exists;
public:
	AvengerSprite(sf::RenderWindow* window, const float max_velocity);
	virtual ~AvengerSprite();

	void setPosition(const sf::Vector2f &position);
	virtual void Animuj(float& dt, sf::RenderTarget& target);
	void Kolizja();
	//Accessors
	sf::FloatRect getBounds();
	bool getExists();
	void kill();
};

