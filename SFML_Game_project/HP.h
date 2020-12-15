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

	sf::RectangleShape HPbarFrameBoss;
	sf::RectangleShape HPbarColorBoss;
	sf::RectangleShape heartBodyBoss;
	float deltaTime;
	
	float currentHP = 100;
	float HPpercent;
	float damage=0 ;
	float bossDamage;
public:
	HP();
	void HPboss();
	//HP(sf::Texture *HPbar,float width,float height,float x,float y );

	//void playerHitBossDamage(float& bossDamage);

	void update(float deltaTime, float &damage);

	

	void draw(sf::RenderWindow& window);
};

