#include<stdio.h>
#include"game.h"
#include<conio.h>
#include<iostream>
int x;
int main() {
	int oceanx=0;
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

	//scrolling background
	/*sf::View view_bg(window.getDefaultView());
	sf::FloatRect fBounds(0.0f, 0.0f, 2500.0f, 1000.0f);//size view
	sf::Texture background;
	background.loadFromFile("img/ocean_new.jpg");
	sf::IntRect iBounds(fBounds);
	background.setRepeated(true);
	sf::Sprite sprite_bg(background,iBounds);
	const sf::Vector2f viewStart(fBounds.left + (fBounds.width / 2), fBounds.top + (fBounds.height / 2));
	const sf::Vector2f spriteStart(fBounds.left,fBounds.top);*/

	//texture submarine
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("img/submarine1.png")) {
		printf("loading failure");
	}
	playerTexture.setSmooth(true);
	player.setTexture(&playerTexture);
	////////*font*/////////////

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
				//std::cout << "New window width: " << event.size.width << "New window height: " << event.size.height << std::endl;
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
		ocean1.move(-0.5f, 0.0f);
		ocean2.move(-0.5f, 0.0f);
		oceanx++;
		if (oceanx == 6000) {
			ocean1.setPosition(0.0f, 0.0f);
			ocean2.setPosition(2999.0f, 0.0f);
			oceanx = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-0.3f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.3f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.0f, -0.3f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f, 0.3f);
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