#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "animation.h"
#include <iostream>
#define BUTTON_SCALEX 300.0
#define BUTTON_SCALEY 100.0
#define MAIN_MENU_BACKGROUND_FILEPATH "img/MENU_BG1.png"
#define MAIN_MENU_PLAY_BUTTON_DEFAULT "img/play_default.png"
#define MAIN_MENU_PLAY_BUTTON_ONCLICK "img/play_onclick.png"
#define MAIN_MENU_PLAY_BUTTON_CLICKED "img/play_clicked.png"
#define MAIN_MENU_OPTION_BUTTON_DEFAULT "img/HowToPlay_default.png"
#define MAIN_MENU_OPTION_BUTTON_ONCLICK "img/HowToPlay_onclick.png"
#define MAIN_MENU_OPTION_BUTTON_CLICKED "img/HowToPlay_clicked.png"
#define MAIN_MENU_EXIT_BUTTON_DEFAULT "img/exit_default.png"
#define MAIN_MENU_EXIT_BUTTON_ONCLICK "img/exit_onclick.png"
#define MAIN_MENU_EXIT_BUTTON_CLICKED "img/exit_clicked.png"
#define MAIN_HOW_TO_PLAY_BUTTON "img/howToPlayPage1.png"
#define MAIN_HOW_TO_PLAY_INTRO "img/howToPlayPage2.png"
#define MAIN_NEXT_BUTTTON "img/NextButton.png"
#define MAIN_CLOSE_HOW_TO_PLAY "img/closeHowToPlay.png"
class Menugame
{

	enum buttonStates { Default = 0, onclick, clicked };

public:

	Menugame(float width, float height,int gamestate);
	~Menugame();
	
	//button

	void update(float deltaTime,bool mouseState, sf::CircleShape& MousePosition,int &gameState);

	//void render(sf::RenderTarget& target);

	//draw object in menu display!!
	void draw(sf::RenderWindow &window);
	//sf::FloatRect getGlobalBounds();
	sf::Music menutheme;

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

	sf::Texture howToPlay[2];
	sf::Texture nextButtonTexture;
	sf::Texture closeTexture;
	sf::RectangleShape howToplaypage;
	sf::RectangleShape nextButton;
	sf::RectangleShape close;
	bool isHowToPlayOn = false;
	bool state = false;
	bool isNextButtonOn = false;
	unsigned short playButtonState = Default; // start = 0
	unsigned short optionButtonState = Default;
	unsigned short exitButtonState = Default;
};

