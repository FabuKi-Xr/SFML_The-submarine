#include<stdio.h>
#include"game.h"
#include<conio.h>
#include<iostream>
#include<vector>
#include<time.h>
#include <stdlib.h>
#include"Menu.h"
#include"Menugame.h"
#include "HP.h"
#include"bullet.h"
//--------------------------------------------------->>> initial <<<---------------------------------------------------------------------------------//
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int main() {
	int oceanx = 0;
	sf::Clock cl;
	float bull = 0.0f;
	sf::Clock bullet_time;
	float deltaTime = 0.0f;
	//////////////////////////////////////////////////////  render window game  ///////////////////////////////////////////////////////////////////////////

	sf::RenderWindow window(sf::VideoMode(1080, 720), "The marine", sf::Style::Default );
	
	
	////////////////////////////////////////////////////////////  background  ////////////////////////////////////////////////////////////////////////////
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

	//////////////////////////////////////////////////////////  texture submarine  ////////////////////////////////////////////////////////////////////////
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setPosition(0.0f, 500.0f);
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("img/submarine1.png")) {
		printf("\nloading failure\n");
	}
	playerTexture.setSmooth(true);
	player.setTexture(&playerTexture);
	 
	//////////////////////////////////////////////////////////  bullet texture  ////////////////////////////////////////////////////
	
	std::vector<bullet> bullet_vec;
	sf::Texture bullet_texture;
	if (!bullet_texture.loadFromFile("img/missile_sprite.png"))
	{
		printf("\ncant open bullet sprite\n");
	}
	
	/////////////////////////////////////////////////////  HP bar  //////////////////////////////////////////////////////////////////////////////////
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
	////////////////////////////////////////////////// heart icon /////////////////////////////////////////////////////////////////////////////////////
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

	
	///////////////////////////////////////////////////////////  obstacle  /////////////////////////////////////////////////////////////////////////////////////////////
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
	
	////////////////////--------------------------------------------->>>  Game  <<<--------------------------------------------------/////////////////////////////////////////////// 
	while (window.isOpen()) 
	{
		deltaTime = cl.restart().asSeconds();
		if (deltaTime > 1.0f / 60.0f) { deltaTime = 1.0f / 60.0f; }
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{

				case sf::Event::KeyReleased: 
						break;

				case sf::Event::Closed:
						window.close();
						printf("\nWindow have closed\n");
						break;

				case sf::Event::Resized:
						printf("\nNew window width: %d New window height: %d\n",event.size.width,event.size.height);
						break;

			}
			if (event.type == event.Closed)
			{
				window.close();
			}
		}
		
		////////////////////////////////////////// create bullet ////////////////////////////////////////////////////////////////////////////////
		bull = bullet_time.getElapsedTime().asMilliseconds();
		if (bull > 700) // it will be have item which increse time reloaded // 7 secs.
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				printf("\nMissile was released!\n");
				bullet_vec.push_back(bullet(&bullet_texture, sf::Vector2u(2,1), .5f/*!?*/, sf::Vector2f(player.getPosition().x+50, player.getPosition().y + 80)));
				bullet_time.restart();
			}
		}
		
		for (bullet& bullet : bullet_vec)
			bullet.update(deltaTime); 
		//////////////////////////////////////////////////
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
		for (bullet& bullet : bullet_vec)
			bullet.draw(window);
		window.display();
	}
	return 0;
}