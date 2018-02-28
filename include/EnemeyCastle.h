#ifndef ENEMEYCASTLE_H
#define ENEMEYCASTLE_H
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class EnemeyCastle
{
    private:
        Texture enemyCastle_texture;

    public:
        Sprite enemyCastle_sprite;
        RectangleShape lifeHealth_shape;
        Vector2f Castle_position;
        Vector2f Castle_Size;
        sf::Vector2f lifeHealth;


        EnemeyCastle(RenderWindow *window);
        void update();
        void Display(RenderWindow *window);
        ~EnemeyCastle();

};
#endif
