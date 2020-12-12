#pragma once
#include<SFML/Graphics.hpp>
#include "animation.h"

#define BUTTON_SCALEX 300.0
#define BUTTON_SCALEY 100.0
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

class Menugame
{

	enum buttonStates { Default = 0, onclick, clicked };

public:

	Menugame(float width, float height);
	~Menugame();
	
	//button

	void update(float deltaTime,bool mouseState, sf::CircleShape& MousePosition);

	//void render(sf::RenderTarget& target);

	//draw object in menu display!!
	void draw(sf::RenderWindow &window);
	//sf::FloatRect getGlobalBounds();
	

private:

	sf::Vector2f velocity;
	//short unsigned buttonState;
	sf::Texture MENU_BG,OBJECT;
	sf::Texture ButtonTexture[3][3];
	sf::Texture marine;
	sf::Sprite BG;//background
	sf::RectangleShape playButtonBody;
	sf::RectangleShape optionButtonBody;
	sf::RectangleShape exitButtonBody;
	sf::RectangleShape submarine;
	sf::Texture bubble;

	unsigned short playButtonState = Default; // start = 0
	unsigned short optionButtonState = Default;
	unsigned short exitButtonState = Default;
};

