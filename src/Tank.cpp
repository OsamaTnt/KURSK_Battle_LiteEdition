#include "Tank.h"

Tank::Tank(sf::RenderWindow *window,sf::Vector2f Castle_position,sf::Vector2f Castle_Size)
{
    windowX=window->getSize().x; windowY=window->getSize().y;

    //initiate the current tank index to (-1) which means there's no tank selected!
    CurrentSelectedTank = -1;bTankSelected=false;
    velocity=0.35;
    numOfDestroyedEnemys=0;

    for(int i=0;i<numOfTanks;i++)
    {
        Hitler_militaryTank[i].texture.loadFromFile("GameData/Tank02.png");
        Stalin_militaryTank[i].texture.loadFromFile("GameData/Tank03.png");

        Hitler_militaryTank[i].sprite.setTexture(Hitler_militaryTank[i].texture);
        Stalin_militaryTank[i].sprite.setTexture(Stalin_militaryTank[i].texture);

        Hitler_militaryTank[i].bMoveForward=Hitler_militaryTank[i].bMoveBackward=Hitler_militaryTank[i].bMoveRight=Hitler_militaryTank[i].bMoveLeft=false;

        //LifeHealth
        Hitler_militaryTank_LifeHealth[i].setSize(sf::Vector2f(Hitler_militaryTank[i].texture.getSize().x,4));
        Hitler_militaryTank_LifeHealth[i].setFillColor(sf::Color(25,215,50));


        Stalin_militaryTank[i].LifeHealth = {Stalin_militaryTank[i].texture.getSize().x,4};
        Stalin_militaryTank_LifeHealth[i].setSize(Stalin_militaryTank[i].LifeHealth);
        Stalin_militaryTank_LifeHealth[i].setFillColor(sf::Color(25,215,50));
        Stalin_militaryTank[i].sprite.setRotation(180);


        switch(i)
        {
            case 0 :
                    Hitler_militaryTank[i].sprite.setPosition(windowX/2-Hitler_militaryTank[i].texture.getSize().x-100,windowY-Hitler_militaryTank[i].texture.getSize().y-50);
                    Stalin_militaryTank[i].sprite.setPosition(Castle_position.x-Stalin_militaryTank[i].texture.getSize().x/2,Castle_position.y+Castle_Size.y-10);
                     break;

            case 1 :
                    Hitler_militaryTank[i].sprite.setPosition(Hitler_militaryTank[i-1].sprite.getPosition().x+Hitler_militaryTank[i].texture.getSize().x+20,windowY-Hitler_militaryTank[i].texture.getSize().y-70);
                    Stalin_militaryTank[i].sprite.setPosition(Stalin_militaryTank[0].sprite.getPosition().x-Stalin_militaryTank[i].texture.getSize().x-20,Stalin_militaryTank[0].sprite.getPosition().y);
                    break;

            case 2 :
                    Hitler_militaryTank[i].sprite.setPosition(Hitler_militaryTank[i-2].sprite.getPosition().x-Hitler_militaryTank[i].texture.getSize().x-20,windowY-Hitler_militaryTank[i].texture.getSize().y-30);
                    Stalin_militaryTank[i].sprite.setPosition(Castle_position.x+Castle_Size.x+Stalin_militaryTank[i].texture.getSize().x*1.5,Castle_position.y+Castle_Size.y-10);
                    break;

            case 3 :
                    Hitler_militaryTank[i].sprite.setPosition(Hitler_militaryTank[i-2].sprite.getPosition().x+Hitler_militaryTank[i].texture.getSize().x+20,windowY-Hitler_militaryTank[i].texture.getSize().y-70);
                    Stalin_militaryTank[i].sprite.setPosition(Stalin_militaryTank[2].sprite.getPosition().x+Stalin_militaryTank[i].texture.getSize().x+20,Stalin_militaryTank[2].sprite.getPosition().y);
                    break;

            case 4 :
                    Hitler_militaryTank[i].sprite.setPosition(Hitler_militaryTank[i-1].sprite.getPosition().x+Hitler_militaryTank[i].texture.getSize().x+20,windowY-Hitler_militaryTank[i].texture.getSize().y-50);
                    Stalin_militaryTank[i].sprite.setPosition(Castle_position.x+Castle_Size.x/2.5,Castle_position.y+Castle_Size.y+Stalin_militaryTank[i].texture.getSize().y+10);
                    break;

            case 5 :
                    Hitler_militaryTank[i].sprite.setPosition(Hitler_militaryTank[i-1].sprite.getPosition().x+Hitler_militaryTank[i].texture.getSize().x+20,windowY-Hitler_militaryTank[i].texture.getSize().y-30);
                    Stalin_militaryTank[i].sprite.setPosition(Stalin_militaryTank[4].sprite.getPosition().x+Stalin_militaryTank[i].texture.getSize().x*1.5,Stalin_militaryTank[4].sprite.getPosition().y);
                    break;

            default :
                    break;

        }

            Hitler_militaryTank_LifeHealth[i].setPosition(Hitler_militaryTank[i].sprite.getPosition().x,Hitler_militaryTank[i].sprite.getPosition().y+Hitler_militaryTank[i].texture.getSize().y);
            Stalin_militaryTank_LifeHealth[i].setPosition(Stalin_militaryTank[i].sprite.getPosition().x-Stalin_militaryTank[i].texture.getSize().x,Stalin_militaryTank[i].sprite.getPosition().y-Stalin_militaryTank[i].texture.getSize().y-5);


            //Tank Bullet
            Hitler_militaryTank[i].Bullet_texture.loadFromFile("GameData/Bullet.png");
            Hitler_militaryTank[i].Bullet_sprite.setTexture(Hitler_militaryTank[i].Bullet_texture);
            Hitler_militaryTank[i].Bullet_sprite.setPosition(Hitler_militaryTank[i].sprite.getPosition().x+(Hitler_militaryTank[i].texture.getSize().x/2)-Hitler_militaryTank[i].Bullet_texture.getSize().x/2,Hitler_militaryTank[i].sprite.getPosition().y);
            Hitler_militaryTank[i].bActiveFire=false;

    }
}

void Tank::manageEvents(sf::Event *event,sf::RenderWindow *window,sf::Mouse *mouse)
{
    for(int i=0;i<numOfTanks;i++)
    {

        if(mouse->getPosition(*window).x > Hitler_militaryTank[i].sprite.getPosition().x && mouse->getPosition(*window).x <= Hitler_militaryTank[i].sprite.getPosition().x+Hitler_militaryTank[i].texture.getSize().x
        && mouse->getPosition(*window).y > Hitler_militaryTank[i].sprite.getPosition().y && mouse->getPosition(*window).y <= Hitler_militaryTank[i].sprite.getPosition().y+Hitler_militaryTank[i].texture.getSize().y )
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {CurrentSelectedTank = i;}
        }
    }

    //Check if up button is pressed
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    { Hitler_militaryTank[CurrentSelectedTank].bMoveForward=true; }
    else { Hitler_militaryTank[CurrentSelectedTank].bMoveForward=false; }

    //Check if Down button is pressed
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    { Hitler_militaryTank[CurrentSelectedTank].bMoveBackward=true; }
    else { Hitler_militaryTank[CurrentSelectedTank].bMoveBackward=false; }

    //check if right button is pressed
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    { Hitler_militaryTank[CurrentSelectedTank].bMoveRight=true;Hitler_militaryTank[CurrentSelectedTank].bMoveForward=false;Hitler_militaryTank[CurrentSelectedTank].bMoveBackward=false; }
    else { Hitler_militaryTank[CurrentSelectedTank].bMoveRight=false; }

    //check if left button is pressed
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    { Hitler_militaryTank[CurrentSelectedTank].bMoveLeft=true;Hitler_militaryTank[CurrentSelectedTank].bMoveForward=false;Hitler_militaryTank[CurrentSelectedTank].bMoveBackward=false; }
    else { Hitler_militaryTank[CurrentSelectedTank].bMoveLeft=false; }


    //check if the space is pressed
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if(CurrentSelectedTank>-1)
        {
            Hitler_militaryTank[CurrentSelectedTank].bActiveFire=true;
        }
    }

}

void Tank::update(sf::RenderWindow *window,sf::Mouse *mouse,EnemeyCastle *enemeyCastle)
{
    if(CurrentSelectedTank > -1)
    {
        if(mouse->getPosition(*window).x > Hitler_militaryTank[CurrentSelectedTank].sprite.getPosition().x && mouse->getPosition(*window).x <= Hitler_militaryTank[CurrentSelectedTank].sprite.getPosition().x+Hitler_militaryTank[CurrentSelectedTank].texture.getSize().x
        && mouse->getPosition(*window).y > Hitler_militaryTank[CurrentSelectedTank].sprite.getPosition().y && mouse->getPosition(*window).y <= Hitler_militaryTank[CurrentSelectedTank].sprite.getPosition().y+Hitler_militaryTank[CurrentSelectedTank].texture.getSize().y)
        {
            Hitler_militaryTank[CurrentSelectedTank].texture.loadFromFile("GameData/Tank022.png");
        }

        for(int i=0;i<numOfTanks;i++)
        {
            if(i!=CurrentSelectedTank) {Hitler_militaryTank[i].texture.loadFromFile("GameData/Tank02.png");}
        }

        //move the selected tank when the (up or down) key is pressed (check for bMoveForward and bMoveBackward)
        if(Hitler_militaryTank[CurrentSelectedTank].bMoveForward==true)
        {
            Hitler_militaryTank[CurrentSelectedTank].sprite.move(0,-velocity);
            Hitler_militaryTank_LifeHealth[CurrentSelectedTank].move(0,-velocity);
            if(Hitler_militaryTank[CurrentSelectedTank].bActiveFire==false)
            {Hitler_militaryTank[CurrentSelectedTank].Bullet_sprite.move(0,-velocity);}

        }

        //move the selected tank when the (up or down) key is pressed (check for bMoveForward and bMoveBackward)
        if(Hitler_militaryTank[CurrentSelectedTank].bMoveBackward==true)
        {
            Hitler_militaryTank[CurrentSelectedTank].sprite.move(0,velocity);
            Hitler_militaryTank_LifeHealth[CurrentSelectedTank].move(0,velocity);
            if(Hitler_militaryTank[CurrentSelectedTank].bActiveFire==false)
            {Hitler_militaryTank[CurrentSelectedTank].Bullet_sprite.move(0,velocity);}
        }

        //Rotate the selected tank when the (right or left) key is pressed (check for bRotateRight and bRotateLeft)
        if(Hitler_militaryTank[CurrentSelectedTank].bMoveRight==true)
        {
            Hitler_militaryTank[CurrentSelectedTank].sprite.move(velocity,0);
            Hitler_militaryTank_LifeHealth[CurrentSelectedTank].move(velocity,0);
            if(Hitler_militaryTank[CurrentSelectedTank].bActiveFire==false)
            {Hitler_militaryTank[CurrentSelectedTank].Bullet_sprite.move(velocity,0);}
        }

        //Rotate the selected tank when the (right or left) key is pressed (check for bRotateRight and bRotateLeft)
        if(Hitler_militaryTank[CurrentSelectedTank].bMoveLeft==true)
        {
            Hitler_militaryTank[CurrentSelectedTank].sprite.move(-velocity,0);
            Hitler_militaryTank_LifeHealth[CurrentSelectedTank].move(-velocity,0);
            if(Hitler_militaryTank[CurrentSelectedTank].bActiveFire==false)
            {Hitler_militaryTank[CurrentSelectedTank].Bullet_sprite.move(-velocity,0);}
        }

        for(int i=0;i<numOfTanks;i++)
        {
            //check the collision
            if(i != CurrentSelectedTank)
            {
                if(Hitler_militaryTank[CurrentSelectedTank].sprite.getGlobalBounds().intersects(Hitler_militaryTank[i].sprite.getGlobalBounds()))
                {
                    if(Hitler_militaryTank[CurrentSelectedTank].bMoveForward==true)
                    {
                        Hitler_militaryTank[CurrentSelectedTank].sprite.move(0,velocity);
                        Hitler_militaryTank_LifeHealth[CurrentSelectedTank].move(0,velocity);
                    }
                    if(Hitler_militaryTank[CurrentSelectedTank].bMoveBackward==true)
                    {
                        Hitler_militaryTank[CurrentSelectedTank].sprite.move(0,-velocity);
                        Hitler_militaryTank_LifeHealth[CurrentSelectedTank].move(0,-velocity);
                    }
                    if(Hitler_militaryTank[CurrentSelectedTank].bMoveRight==true)
                    {
                        Hitler_militaryTank[CurrentSelectedTank].sprite.move(-velocity,0);
                        Hitler_militaryTank_LifeHealth[CurrentSelectedTank].move(-velocity,0);
                    }
                    if(Hitler_militaryTank[CurrentSelectedTank].bMoveLeft==true)
                    {
                        Hitler_militaryTank[CurrentSelectedTank].sprite.move(velocity,0);
                        Hitler_militaryTank_LifeHealth[CurrentSelectedTank].move(velocity,0);
                    }
                }
            }

            //Move the bullet when space is pressed
            if(Hitler_militaryTank[i].bActiveFire==true)
            {
                Hitler_militaryTank[i].Bullet_sprite.move(0,-5);
            }

            ///Tank Bullet Collision
            //if it goes out the screen
            if(Hitler_militaryTank[i].Bullet_sprite.getPosition().y < 0)
            {
                Hitler_militaryTank[i].bActiveFire=false;
                Hitler_militaryTank[i].Bullet_sprite.setPosition(Hitler_militaryTank[i].sprite.getPosition().x+(Hitler_militaryTank[i].texture.getSize().x/2)-Hitler_militaryTank[i].Bullet_texture.getSize().x/2,Hitler_militaryTank[i].sprite.getPosition().y);
            }

            //if the bullet intersects with enemy tank or enemyCastle
            for(int j=0;j<numOfTanks;j++)
            {
                //check for enemy tank
                if(Hitler_militaryTank[i].Bullet_sprite.getGlobalBounds().intersects(Stalin_militaryTank[j].sprite.getGlobalBounds()))
                {
                    Hitler_militaryTank[i].bActiveFire=false;
                    Hitler_militaryTank[i].Bullet_sprite.setPosition(Hitler_militaryTank[i].sprite.getPosition().x+(Hitler_militaryTank[i].texture.getSize().x/2)-Hitler_militaryTank[i].Bullet_texture.getSize().x/2,Hitler_militaryTank[i].sprite.getPosition().y);
                    //decrease the life health for stalin tank
                    if(Stalin_militaryTank[j].LifeHealth.x > 10)
                    {
                        Stalin_militaryTank[j].LifeHealth.x-=10;
                        Stalin_militaryTank_LifeHealth[j].setSize(Stalin_militaryTank[j].LifeHealth);
                    }
                    else
                    {
                        Stalin_militaryTank[j].sprite.setScale(0,0);
                        numOfDestroyedEnemys++;     //To check the end of game
                    }
                }
            }

                //check for enemyCastle
                if(Hitler_militaryTank[i].Bullet_sprite.getGlobalBounds().intersects(enemeyCastle->enemyCastle_sprite.getGlobalBounds()))
                {
                        Hitler_militaryTank[i].bActiveFire=false;
                        Hitler_militaryTank[i].Bullet_sprite.setPosition(Hitler_militaryTank[i].sprite.getPosition().x+(Hitler_militaryTank[i].texture.getSize().x/2)-Hitler_militaryTank[i].Bullet_texture.getSize().x/2,Hitler_militaryTank[i].sprite.getPosition().y);
                        if(enemeyCastle->lifeHealth.x>15)
                        {
                            enemeyCastle->lifeHealth.x-=15;
                            enemeyCastle->lifeHealth_shape.setSize(enemeyCastle->lifeHealth);
                        }
                        else
                        {
                            enemeyCastle->enemyCastle_sprite.setScale(0,0);
                            numOfDestroyedEnemys++;
                        }
                }

        }

    }
}

int Tank::getNumOfDestroyedEnemys()
{
    return numOfDestroyedEnemys;
}

void Tank::Display(sf::RenderWindow *window)
{
    for(int i=0;i<numOfTanks;i++)
    {
        window->draw(Hitler_militaryTank[i].sprite);
        window->draw(Stalin_militaryTank[i].sprite);
        if(CurrentSelectedTank >-1)
        {
            window->draw(Hitler_militaryTank_LifeHealth[CurrentSelectedTank]);
        }
        window->draw(Stalin_militaryTank_LifeHealth[i]);
        if(Hitler_militaryTank[i].bActiveFire==true)
        {
            window->draw(Hitler_militaryTank[i].Bullet_sprite);
        }
    }
}

Tank::~Tank() {}
