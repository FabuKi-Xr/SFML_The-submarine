#include "Menugame.h"

Menugame::Menugame(float width, float height)
{
	//loading resource
	if (!MENU_BG.loadFromFile(MAIN_MENU_BACKGROUND_FILEPATH)) {
		printf("loading failure BG");
	}
	if (!BUTTON[0][0].loadFromFile(MAIN_MENU_PLAY_BUTTON_DEFAULT)) {
		printf("cant open play_default");
	}
	if (!BUTTON[0][1].loadFromFile(MAIN_MENU_PLAY_BUTTON_ONCLICK)) {
		printf("cant open play_onclick");
	}
	if (!BUTTON[0][2].loadFromFile(MAIN_MENU_PLAY_BUTTON_CLICKED)) {
		printf("cant open play_clicked");
	}
	if (!BUTTON[1][0].loadFromFile(MAIN_MENU_OPTION_BUTTON_DEFAULT)) {
		printf("cant open option_default");
	}
	if (!BUTTON[1][1].loadFromFile(MAIN_MENU_OPTION_BUTTON_ONCLICK)) {
		printf("cant open MAIN_MENU_OPTION_BUTTON_ONCLICK");
	}
	if (!BUTTON[1][2].loadFromFile(MAIN_MENU_OPTION_BUTTON_CLICKED)) {
		printf("cant open MAIN_MENU_OPTION_BUTTON_CLICKED");
	}
	if (!BUTTON[2][0].loadFromFile(MAIN_MENU_EXIT_BUTTON_DEFAULT)) {
		printf("cant open MAIN_MENU_EXIT_BUTTON_DEFAULT");
	}
	if (!BUTTON[2][1].loadFromFile(MAIN_MENU_EXIT_BUTTON_ONCLICK)) {
		printf("cant open MAIN_MENU_EXIT_BUTTON_ONCLICK");
	}
	if (!BUTTON[2][2].loadFromFile(MAIN_MENU_EXIT_BUTTON_CLICKED)) {
		printf("cant open MAIN_MENU_EXIT_BUTTON_CLICKED");
	}
	BG.setTexture(MENU_BG);
	
	//submarine sprite
	if (!OBJECT.loadFromFile("img/submarine.png")) {
		printf("loading failure object \"marine\"");
	}
	MENU_BG.setSmooth(true);
	OBJECT.setSmooth(true);
	BUTTON[0][0].setSmooth(true);
	BUTTON[0][1].setSmooth(true);
	BUTTON[0][2].setSmooth(true);
	BUTTON[1][0].setSmooth(true);
	BUTTON[2][0].setSmooth(true);

}
Menugame::~Menugame()
{
}
void Menugame::draw(sf::RenderWindow& window)
{
	//sf::RenderWindow window(sf::VideoMode(1080, 720), "The marine", sf::Style::Default);
	//PART SET RECTANGLESHAPE OBJECT 
	sf::RectangleShape PLACE_OBJECT(sf::Vector2f(OBJECT_SCALE, OBJECT_SCALE));
	sf::RectangleShape shape(sf::Vector2f(BUTTON_SCALE, BUTTON_SCALE));
	/*sf::RectangleShape PLACE_PLAY_BUTTON2(sf::Vector2f(BUTTON_SCALE, BUTTON_SCALE));
	sf::RectangleShape PLACE_PLAY_BUTTON3(sf::Vector2f(BUTTON_SCALE, BUTTON_SCALE));*/

	sf::RectangleShape PLACE_OPTION_BUTTON1(sf::Vector2f(BUTTON_SCALE, BUTTON_SCALE));
	/*sf::RectangleShape PLACE_OPTION_BUTTON2(sf::Vector2f(BUTTON_SCALE, BUTTON_SCALE));
	sf::RectangleShape PLACE_OPTION_BUTTON3(sf::Vector2f(BUTTON_SCALE, BUTTON_SCALE));*/

	sf::RectangleShape PLACE_EXIT_BUTTON1(sf::Vector2f(BUTTON_SCALE, BUTTON_SCALE));
	PLACE_OBJECT.setTexture(&OBJECT);
	PLACE_OBJECT.setPosition(.0f, 75.0f);//!!

	//button
	shape.setTexture(&BUTTON[0][1]);
	shape.setPosition(BUTTON_POSITION_X,150.0f);
	/*PLACE_PLAY_BUTTON2.setTexture(&BUTTON[0][2]);
	PLACE_PLAY_BUTTON2.setPosition(BUTTON_POSITION_X, 150.0f);*/
	PLACE_OPTION_BUTTON1.setTexture(&BUTTON[1][0]);
	PLACE_OPTION_BUTTON1.setPosition(BUTTON_POSITION_X,300.0f);
	PLACE_EXIT_BUTTON1.setTexture(&BUTTON[2][0]);
	PLACE_EXIT_BUTTON1.setPosition(BUTTON_POSITION_X, 450.0f);
	
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	
	//ปัญหาตอนนี้คือไม่ผ่านupdate กับ render
	//PART BUTTON OBJECT 
		//window.clear();
		//window.display();
	
		window.draw(BG);
		window.draw(PLACE_OBJECT);
		window.draw(shape);
		window.draw(PLACE_OPTION_BUTTON1);
		window.draw(PLACE_EXIT_BUTTON1);
		
}

