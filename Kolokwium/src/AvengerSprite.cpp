#include "AvengerSprite.h"

AvengerSprite::AvengerSprite(sf::RenderWindow* window, const float max_velocity)
	: window(window), max_velocity(max_velocity), exists(1)
{
	this->bounds = this->sprite.getGlobalBounds();
}

AvengerSprite::~AvengerSprite()
{
}

void AvengerSprite::setPosition(const sf::Vector2f& position)
{
	this->sprite.setPosition(position);
}

void AvengerSprite::Animuj(float& dt, sf::RenderTarget &target)
{
	this->bounds = this->sprite.getGlobalBounds();

	//Update
	this->Kolizja();

	this->velocity.x = this->max_velocity;
	this->velocity.y = this->max_velocity;

	this->sprite.move(velocity * dt);

	//Render
	target.draw(this->sprite);
}

void AvengerSprite::Kolizja()
{
	if ((this->sprite.getPosition().x + this->texture.getSize().x) >= this->window->getSize().x)
	{
		this->sprite.setPosition(sf::Vector2f(0.f, this->sprite.getPosition().y));
	}

	else if (this->sprite.getPosition().x <= 0)
	{
		this->sprite.setPosition(sf::Vector2f(this->window->getSize().x - this->texture.getSize().x, this->sprite.getPosition().y));
	}

	if ((this->sprite.getPosition().y + this->texture.getSize().y) > this->window->getSize().y)
	{
		this->sprite.setPosition(sf::Vector2f(this->sprite.getPosition().x, 0.f));
	}

	else if (this->sprite.getPosition().y <= 0)
	{
		this->sprite.setPosition(sf::Vector2f(this->sprite.getPosition().x,this->window->getSize().y - this->texture.getSize().y));
	}
}

sf::FloatRect AvengerSprite::getBounds()
{
	return this->bounds;
}

bool AvengerSprite::getExists()
{
	return this->exists;
}

void AvengerSprite::kill()
{
	this->exists = false;
}
