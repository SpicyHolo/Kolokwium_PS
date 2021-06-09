#pragma once
#include "AvengerSprite.h"

enum direction { UP = 0, DOWN, LEFT, RIGHT };

class Thor :
    public AvengerSprite
{
private:
    short direction;
public:
    Thor(sf::RenderWindow* window, const float max_velocity);
    virtual ~Thor();

    void changeDirection(short dir);

    void Animuj(float& dt, sf::RenderTarget& target);
};

