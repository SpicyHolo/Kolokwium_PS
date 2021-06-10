#include "StworOutrider.h"

StworOutrider::StworOutrider(sf::RenderWindow* window, sf::Texture& texture, const float max_velocity, const sf::Vector2f position)
	: AvengerSprite(window, max_velocity)
{
	this->texture = texture;
	this->sprite.setTexture(this->texture);
	this->setPosition(position);
}
StworOutrider::~StworOutrider()
{

}

void StworOutrider::Animuj(float& dt, sf::RenderTarget& target)
{
	//Update
	this->bounds = this->sprite.getGlobalBounds();

	this->Kolizja();
	this->velocity.x = max_velocity;
	this->velocity.y = 0.f;
	this->sprite.move(velocity * dt);

	//Render
	target.draw(this->sprite);
}