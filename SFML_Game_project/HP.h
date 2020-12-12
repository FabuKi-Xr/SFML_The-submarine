#pragma once
#include<iostream>
#include<sfml\Graphics.hpp>
class HP
{
private:
	sf::Texture HPframeTexture;
	sf::Texture HPcolorTexture;
	sf::Texture heart;
	sf::RectangleShape heartBody;
	sf::RectangleShape HPbarFrame;
	sf::RectangleShape HPbarColor;
	float deltaTime;

public:
	HP();

	//HP(sf::Texture *HPbar,float width,float height,float x,float y );

	void update(float deltaTime,float damage);

	void draw(sf::RenderWindow& window);
};

