#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
/* */
class game
{
private:
	//private function
	void initVariables()
	{

	}
	void initWindow() 
	{

	}
public:
	//Construcors
	game();
	virtual ~game();

	//Function
	void update();
	void render();
};

