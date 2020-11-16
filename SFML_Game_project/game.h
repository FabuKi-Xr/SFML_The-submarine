#pragma once
#include<iostream>
#include<ctime>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
/* */
class game
{
public:

	//Construcors
	game();
	virtual ~game();

	//Function
	void updateSFMLevents();
	void update();
	void render();
	void run();

private:
	sf::RenderWindow *window;
	sf::Event event;
	//private function
	void initVariables();
	//เริ่มต้น
	void initWindow();

};


