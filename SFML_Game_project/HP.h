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
	
	float HPpercent=100;
	float HPplayerPercent=100;
	float damage=0 ;
	float bossDamage;
	sf::Vector2f scale;
public:
	HP();
	void HPboss();
	//HP(sf::Texture *HPbar,float width,float height,float x,float y );

	//void playerHitBossDamage(float& bossDamage);

	void HPbossUpdate(float deltaTime, float &damage,bool &checkHP,int& gameState);
	void HPplayerUpdate(float deltaTime, float& damage, bool& checkPlayerHP, int& gameState);
	float currentHP = 100;
	float currentPlayerHP = 100;
	void draw(sf::RenderWindow& window);
};

