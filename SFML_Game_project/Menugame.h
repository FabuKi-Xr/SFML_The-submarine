#pragma once
#include<SFML/Graphics.hpp>

#define OBJECT_SCALE 600.0
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

class Menugame
{

	enum buttonStates { Default = 0, onclick, clicked };

public:

	Menugame(float width, float height);
	~Menugame();
	
	//button
	void update(const sf::Vector2i mousePosWindow);
	void render(sf::RenderTarget& target);

	//draw object in menu display!!
	void draw(sf::RenderWindow &window);


private:

	short unsigned buttonState;
	sf::Texture MENU_BG,OBJECT;
	sf::Texture BUTTON[3][3];
	sf::Sprite BG;
	sf::RectangleShape shape;
	
};
