#include<stdio.h>
#include"game.h"
#include<conio.h>
#include<iostream>
#include<time.h>
#include <stdlib.h>
#include"Menu.h"
#include"Menugame.h"
#include "HP.h"
/*void Resize(const sf::RenderWindow& window) 
{
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	
}*/ 

int main() {
	int oceanx = 0;
	//render window game
	sf::RenderWindow window(sf::VideoMode(1080, 720), "The marine", sf::Style::Default );
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setPosition(0.0f,500.0f);
	//Menugame menu(window.getSize().x,window.getSize().y);
	
	//scrolling bg
	sf::Texture oceanTexture;
	if (!oceanTexture.loadFromFile("img/ocean_new.jpg")) {
		printf("loading failure");
	}
	sf::Sprite ocean1;
	sf::Sprite ocean2;
	ocean1.setTexture(oceanTexture);
	ocean1.setTextureRect(sf::IntRect(0, 0, 3000, 720));
	ocean1.setPosition(0.0f, 0.0f);
	ocean2.setTexture(oceanTexture);
	ocean2.setTextureRect(sf::IntRect(0, 0, 3000, 720));
	ocean2.setPosition(2999.0f, 0.0f);

	//texture submarine
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("img/submarine1.png")) {
		printf("\nloading failure\n");
	}
	playerTexture.setSmooth(true);
	player.setTexture(&playerTexture);
	 
	//HP
	sf::Texture blood;
	sf::Texture heart;
	heart.setSmooth(true);
	blood.setSmooth(true);
	sf::RectangleShape heartbox(sf::Vector2f(70.0f,70.0f));
	sf::RectangleShape bloodbar(sf::Vector2f(400.0f, 30.0f));
	if(!heart.loadFromFile("img/heart-icon.png"))
	{
		printf("\ncant open heart_icon\n");
	}
	if (!blood.loadFromFile("img/HP_bar.png")) {
		printf("\ncant open HP_bar\n");
	}
	//heart icon
	bloodbar.setOutlineThickness(5.0f);
	bloodbar.setOutlineColor(sf::Color::Black);
	heartbox.setTexture(&heart);
	heartbox.setPosition(.0f, 20.0f);

	bloodbar.setPosition(100.0f,40.0f);
	printf("x:%f y:%f",bloodbar.getPosition().x, bloodbar.getPosition().y);
	bloodbar.setTexture(&blood);
	float MyHP = 78000;
	
	/*sf::RectangleShape HP(sf::Vector2f(MyHP / 250.0f, 30));
	HP.setPosition(sf::Vector2f(450, 46));
	HP.setFillColor(sf::Color::Magenta);
	HP.setSize(sf::Vector2f(MyHP / 320.f, 15));*/
	
	/*if (!bloodframe.loadFromFile("img/bloodframe.png")) 
	{
		printf("\ncant open HP_bar\n");
	}*/

	
	//obstacle
	sf::Texture obstacle[3];
	sf::RectangleShape Obstacle[3];
	if (!obstacle[0].loadFromFile("img/obstacle.png")) {
		printf("loading failure");
	}
	if (!obstacle[1].loadFromFile("img/obstacle.png")) {
		printf("loading failure");
	}
	if (!obstacle[2].loadFromFile("img/obstacle.png")) {
		printf("loading failure");
	}
	obstacle[0].setSmooth(true);
	Obstacle[0].setTexture(&obstacle[0]);
	
	obstacle[1].setSmooth(true);
	Obstacle[1].setTexture(&obstacle[1]);
	
	obstacle[2].setSmooth(true);
	Obstacle[2].setTexture(&obstacle[2]);
	
	while (window.isOpen()) //animation use adobe??
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased: break;//!!!!

				case sf::Event::Closed:
						window.close();
						break;
				case sf::Event::Resized:
					//Resize(window);
						printf("New window width: %d New window height: %d\n",event.size.width,event.size.height);
						break;
			//	case sf::Event::TextEntered:
			}
			if (event.type == event.Closed)
			{
				window.close();
			}
		}
		
		//map motion
		/*Obstacle[0].setPosition(500.0f, 650.0f);
		Obstacle[1].setPosition(700.0f, 650.0f);
		Obstacle[2].setPosition(750.0f, 650.0f);*/
		ocean1.move(-0.1f, 0.0f);
		ocean2.move(-0.1f, 0.0f);
		oceanx++;
		if (oceanx == 6000) {
			ocean1.setPosition(0.0f, 0.0f);
			ocean2.setPosition(2999.0f, 0.0f);
			oceanx = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			if(player.getPosition().x >= 0) player.move(-0.15f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.15f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.0f, -0.15f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f, 0.15f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			window.close();
		}
		
		window.clear();
		//menu.draw(window);
		/*window.draw(Obstacle[0]);
		window.draw(Obstacle[1]);
		window.draw(Obstacle[2]);*/
		window.draw(ocean1);
		window.draw(ocean2);
		window.draw(player);
		window.draw(heartbox);
		window.draw(bloodbar);
		//window.draw(HP);
		window.display();
	}
	return 0;
}