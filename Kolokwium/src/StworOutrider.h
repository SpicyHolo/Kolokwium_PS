#pragma once
#include "AvengerSprite.h"

class StworOutrider :
    public AvengerSprite
{
private:
public:
    StworOutrider(sf::RenderWindow* window, sf::Texture& texture, const float max_velocity, const sf::Vector2f position);
    virtual ~StworOutrider();

    void Animuj(float& dt, sf::RenderTarget& target);
};

