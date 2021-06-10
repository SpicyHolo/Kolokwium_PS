#include <iostream>
#include <vector>

#include "AvengerSprite.h"
#include "Thor.h"
#include "KamienNieskonczonosci.h"
#include "StworOutrider.h"


void spawnKamienie(std::vector<KamienNieskonczonosci*>& vec, sf::Texture &texture, sf::RenderWindow &window, Thor &thor)
{
    //Spawning while avoiding Thor's position
    for (size_t i = 0; i < 6; i++)
    {
        float pos_x = 0;
        float pos_y = 0;
        sf::FloatRect* hitbox;
        do
        {
            pos_x = rand() % (window.getSize().x - texture.getSize().x) + 1;
            pos_y = rand() % (window.getSize().y - texture.getSize().y) + 1;
            hitbox = new sf::FloatRect(pos_x, pos_y, static_cast<float>(texture.getSize().x), static_cast<float>(texture.getSize().y));
        } while (hitbox->intersects(thor.getBounds()));

        delete hitbox;
        KamienNieskonczonosci* kamien = new KamienNieskonczonosci(&window, texture, 50.f, sf::Vector2f(pos_x, pos_y));
        vec.push_back(kamien);
    }
}

void spawnOutriders(std::vector<StworOutrider*>& vec, sf::Texture& texture, sf::RenderWindow& window, Thor& thor)
{
    //Spawning while avoiding Thor's position
    for (size_t i = 0; i < 10; i++)
    {
        float pos_x = 0;
        float pos_y = 0;
        sf::FloatRect* hitbox;
        float max_velocity = 100.f;
        bool direction = rand() % 2;
        if (direction)
            max_velocity *= -1;

        do
        {
            pos_x = rand() % (window.getSize().x - texture.getSize().x) + 1;
            pos_y = rand() % (window.getSize().y - texture.getSize().y) + 1;
            hitbox = new sf::FloatRect(pos_x - 50.f, pos_y - 50.f, static_cast<float>(texture.getSize().x) + 100.f, static_cast<float>(texture.getSize().y) + 100.f);
        } while (hitbox->intersects(thor.getBounds()));

        delete hitbox;
        StworOutrider* stwor = new StworOutrider(&window, texture, max_velocity, sf::Vector2f(pos_x, pos_y));
        vec.push_back(stwor);
    }
}

int main()
{
    //setting time for random numbers
    srand(time(NULL));

    //Ignore joystick error
    sf::err().rdbuf(NULL);
    sf::Clock dtClock;
    float dt = 0;

    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "Janek jest super.");

    //Inicjalzacja Thora
    Thor* thor = new Thor(window, 150.f);

    //Kamien nieskonczonosci
    sf::Texture kamien_texture;
    kamien_texture.loadFromFile("resources/ruby.png");
    std::vector<KamienNieskonczonosci*> kamienie;
    spawnKamienie(kamienie, kamien_texture, *window, *thor);

    //Outriders
    sf::Texture outrider_texture;
    outrider_texture.loadFromFile("resources/monster.png");
    std::vector<StworOutrider*> outriders;
    spawnOutriders(outriders, outrider_texture, *window, *thor);



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

        //Check for colission with thor

         //Update and Render
        thor->Animuj(dt, *window);
        for (auto it = kamienie.begin(); it != kamienie.end(); ++it)
        {
            if ((*it)->getExists())
            {
                (*it)->Animuj(dt, *window);
                if (thor->getBounds().intersects((*it)->getBounds()))
                {
                    (*it)->kill();
                    thor->addPoints();
                    if (thor->checkPoints())
                    {
                        system("CLS");
                        std::cout << "WYGRANA :) ";
                        window->close();
                    }
                }
            }
        }

        for (auto it = outriders.begin(); it != outriders.end(); ++it)
        {
            if ((*it)->getExists())
            {
                (*it)->Animuj(dt, *window);
                if (thor->getBounds().intersects((*it)->getBounds()))
                {
                    (*it)->kill();
                    thor->removeHp();
                    if (thor->checkHp())
                    {
                        system("CLS");
                        std::cout << "PRZEGRANA :( ";
                        window->close();
                    }
                }
            }
        }
        window->display();
    }
    return 0;
}

