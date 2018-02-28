#include "EnemeyCastle.h"

EnemeyCastle::EnemeyCastle(sf::RenderWindow *window)
{
    enemyCastle_texture.loadFromFile("GameData/Enemy_Castle.png");
    enemyCastle_sprite.setTexture(enemyCastle_texture);
    Castle_position = {(window->getSize().x/2)-enemyCastle_texture.getSize().x/2,30};
    Castle_Size = { enemyCastle_texture.getSize().x,enemyCastle_texture.getSize().y };
    enemyCastle_sprite.setPosition(Castle_position);

    lifeHealth= {enemyCastle_texture.getSize().x,10};
    lifeHealth_shape.setSize(lifeHealth);
    lifeHealth_shape.setPosition(enemyCastle_sprite.getPosition().x,enemyCastle_sprite.getPosition().y-lifeHealth_shape.getSize().y*1.25);
    lifeHealth_shape.setFillColor(sf::Color(25,215,50));

}

void EnemeyCastle::update()
{
    //lifeHealth_shape.setSize(sf::Vector2f(lifeHealth,lifeHealth_shape.getSize().y));
}

void EnemeyCastle::Display(sf::RenderWindow *window)
{
    window->draw(enemyCastle_sprite);
    window->draw(lifeHealth_shape);
}

EnemeyCastle::~EnemeyCastle()
{

}
