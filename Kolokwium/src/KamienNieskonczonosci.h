#pragma once
#include "AvengerSprite.h"

class KamienNieskonczonosci :
    public AvengerSprite
{
private:
public:
    KamienNieskonczonosci(sf::RenderWindow* window, sf::Texture& texture, const float max_velocity, const sf::Vector2f position);
    virtual ~KamienNieskonczonosci();

    void Animuj(float& dt, sf::RenderTarget& target);
};