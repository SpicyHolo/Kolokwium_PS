#include "Thor.h"

Thor::Thor(sf::RenderWindow* window, const float max_velocity)
	: AvengerSprite(window, max_velocity), direction(RIGHT)
{
	this->texture.loadFromFile("resources/Thor.png");
	this->sprite.setTexture(this->texture);

	//Sets Thor's position to center
	this->setPosition(sf::Vector2f
		(
			(static_cast<float>(this->window->getSize().x) - static_cast<float>(this->texture.getSize().x)) / 2.f, 
			(static_cast<float>(this->window->getSize().y) - static_cast<float>(this->texture.getSize().y)) / 2.f
		)
	);
}

Thor::~Thor()
{

}

void Thor::changeDirection(short dir)
{
	this->direction = dir;
}

void Thor::Animuj(float& dt, sf::RenderTarget& target)
{
	//Update
	this->Kolizja();

	switch (direction) {
		case UP:
			this->velocity.x = 0.f;
			this->velocity.y = -max_velocity;
			break;
		case DOWN:
			this->velocity.x = 0.f;
			this->velocity.y = max_velocity;
			break;
		case LEFT:
			this->velocity.x = -max_velocity;
			this->velocity.y = 0.f;
			break;
		case RIGHT:
			this->velocity.x = max_velocity;
			this->velocity.y = 0.f;
			break;
	}
	this->sprite.move(velocity * dt);

	//Render
	target.draw(this->sprite);
}