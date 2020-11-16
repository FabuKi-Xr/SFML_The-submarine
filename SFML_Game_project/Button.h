#pragma once
#include<SFML/Graphics.hpp>

#define BUTTON_SCALE 350.0
#define BUTTON_POSITION_X 675.0
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

class Button
{
	enum buttonStates {Default=0,onclick,clicked};
	enum buttonType {play=0,option=1,exit=2};
private:

	short unsigned buttonState;//collecting buttonstate from default onclick clicked
	short unsigned type;//เช็คว่าปุ่มอะไร
	sf::RectangleShape shape;
	sf::Texture BUTTON;

public:
	
	Button(float x,float y,float width,float height,sf::RectangleShape shape,sf::Texture BUTTON, short unsigned state, short unsigned type);

	//function
	void update(const sf::Vector2i);
	void render(sf::RenderTarget& target);

	
};

