#ifndef MAINMENU_H
#define MAINMENU_H
#include <iostream>
#include <SFML/Graphics.hpp>

const int NumOfMenuItems = 5;

struct Image
{
    sf::Vector2f position,Size;
    sf::Texture texture;
    sf::RectangleShape shape;
};

struct MenuItem
{
    sf::Vector2f position,Size;
    sf::Text text;
};

class MainMenu
{
    private:
        float windowX,windowY;
        sf::Font font;

        Image *BG,Story_BG,StoryInterface,Credits_BG;
        MenuItem *menuItem;


        int menuCurrentIndex;
        bool bStart,bSoundOn,bExit,bShowOptions,bShowStory,bShowCredits;
        bool bStartMouseHovering,bMouseOnItem;
        int buttonCounter;

    public:
        MainMenu(sf::RenderWindow *window);
        void manageEvents(sf::Event *event,sf::RenderWindow *window,sf::Mouse *mouse);
        void update(sf::RenderWindow *window,sf::Mouse *mouse);
        bool isGameStarts();
        void Display(sf::RenderWindow *window);

        ~MainMenu();
};
#endif // MAINMENU_H
