#include "KamienNieskonczonosci.h"

KamienNieskonczonosci::KamienNieskonczonosci(sf::RenderWindow* window, sf::Texture& texture, const float max_velocity, const sf::Vector2f position)
	: AvengerSprite(window, max_velocity)
{
	this->sprite.setScale(0.5, 0.5);
	this->texture = texture;
	this->sprite.setTexture(this->texture);
	this->setPosition(position);
}
KamienNieskonczonosci::~KamienNieskonczonosci()
{

}

void KamienNieskonczonosci::Animuj(float& dt, sf::RenderTarget& target)
{
	//Update
	this->bounds = this->sprite.getGlobalBounds();
	this->Kolizja();
	this->velocity.x = 0.f;
	this->velocity.y = max_velocity;
	this->sprite.move(velocity * dt);

	//Render
	target.draw(this->sprite);
}