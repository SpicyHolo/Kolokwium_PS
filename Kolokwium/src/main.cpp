#include <iostream>

#include "AvengerSprite.h"
#include "Thor.h"

int main()
{
    //Ignore joystick error
    sf::err().rdbuf(NULL); 
    srand(time(NULL));
    sf::Clock dtClock;
    float dt = 0;

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "Janek jest super.");
    Thor* thor = new Thor(window, 150.f);


    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

            switch (event.key.code)
            {
                case sf::Keyboard::Escape:
                    window->close();
                    break;
                case sf::Keyboard::W:
                    thor->changeDirection(UP);
                    break;
                case sf::Keyboard::S:
                    thor->changeDirection(DOWN);
                    break;
                case sf::Keyboard::A:
                    thor->changeDirection(LEFT);
                    break;
                case sf::Keyboard::D:
                    thor->changeDirection(RIGHT);
                    break;
                default:
                    break;
            }
        }
        dt = dtClock.restart().asSeconds();
        window->clear();
        thor->Animuj(dt, *window);
        window->display();
    }

    return 0;
}