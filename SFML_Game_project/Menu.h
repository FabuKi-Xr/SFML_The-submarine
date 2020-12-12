#pragma once
#include<SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3 //
#define MAIN_MENU_BACKGROUND_FILEPATH "img/MENU_BG.jpg"
#define MAIN_MENU_PLAY_BUTTON_DEFAULT "img/play_default.png"
#define MAIN_MENU_PLAY_BUTTON_ONCLICK "img/play_onclick.png"
#define MAIN_MENU_PLAY_BUTTON_CLICKED "img/play_clicked.png"
#define MAIN_MENU_OPTION_BUTTON_DEFAULT "img/option_default.png"
#define MAIN_MENU_OPTION_BUTTON_ONCLICK "img/option_onclick.png"
#define MAIN_MENU_OPTION_BUTTON_CLICKED "img/option_clicked.png"
#define MAIN_MENU_EXIT_BUTTON_DEFAULT "img/exit_default.png"
#define MAIN_MENU_EXIT_BUTTON_ONCLICK "img/exit_onclick.png"
#define MAIN_MENU_EXIT_BUTTON_CLICKED "img/exit_clicked.png"
class Menu
{
public:
	Menu(float width,float height);
	~Menu();
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	void button();

private:
	int selectedItemIndex;
	sf::Texture ButtonTexture[3][3];
	sf::Texture MenuBG;
	sf::RectangleShape body;
	sf::RectangleShape BG;
};

