#pragma once
#include "AvengerSprite.h"

enum direction { UP = 0, DOWN, LEFT, RIGHT };

class Thor :
    public AvengerSprite
{
private:
    short direction;
    int hp;
    int points;
public:
    Thor(sf::RenderWindow* window, const float max_velocity);
    virtual ~Thor();

    void changeDirection(short dir);

    void Animuj(float& dt, sf::RenderTarget& target);

    void removeHp();
    bool checkHp();

    void addPoints();
    bool checkPoints();
};

