#ifndef TANK_H
#define TANK_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "EnemeyCastle.h"

const int numOfTanks = 6;   //size of tank array

struct MilitaryTank
{
    sf::Sprite sprite;
    sf::Texture texture;

    bool bMoveForward,bMoveBackward,bMoveRight,bMoveLeft;

    sf::Sprite Bullet_sprite;
    sf::Texture Bullet_texture;
    bool bActiveFire;
    sf::Vector2f LifeHealth;

};

class Tank
{
    private:
        float windowX,windowY;
        sf::RectangleShape Hitler_militaryTank_LifeHealth[numOfTanks], Stalin_militaryTank_LifeHealth[numOfTanks];
        float velocity;

        int CurrentSelectedTank;
        //buttonCounter;
        bool bMouseOnTank,bTankSelected;
        int numOfDestroyedEnemys;    //to determine the end of the game ex : if the 6 tanks are dead and the castle You Win else You Lost

    public:
        MilitaryTank Hitler_militaryTank[numOfTanks],Stalin_militaryTank[numOfTanks];

        Tank(sf::RenderWindow *window,sf::Vector2f Castle_position,sf::Vector2f Castle_Size);
        void manageEvents(sf::Event *event,sf::RenderWindow *window,sf::Mouse *mouse);
        void update(sf::RenderWindow *window,sf::Mouse *mouse,EnemeyCastle *enemeyCastle);
        int getNumOfDestroyedEnemys();
        void Display(sf::RenderWindow *window);
        ~Tank();
};
#endif
