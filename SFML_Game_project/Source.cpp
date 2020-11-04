#include<stdio.h>
#include"game.h"
#include<conio.h>
#include<iostream>
#include<time.h>
#include <stdlib.h>
int main() {
	int oceanx=0;
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1080, 720), "The marine", sf::Style::Default );
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setPosition(250.0f,500.0f);
	
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
		printf("loading failure");
	}
	playerTexture.setSmooth(true);
	player.setTexture(&playerTexture);

	while (window.isOpen()) //animation use adobe??
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				printf("New window width: %d New window height: %d\n",event.size.width,event.size.height);
				break;
			case sf::Event::TextEntered:
				if (event.text.unicode < 128)
				{
					printf("%c",event.text.unicode);
				}
			}
			if (event.type == event.Closed)
			{
				window.close();
			}
		}
		//map motion
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
			player.move(-0.15f, 0.0f);
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
		/*window.setView(view_bg);*/
		window.clear();
		window.draw(ocean1);
		window.draw(ocean2);
		window.draw(player);
		window.display();
	}
	return 0;
}