#pragma once
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<SFML\Graphics.hpp>
#include <vector>
#include "drawobstacle.h"
class obstruct
{
public:
	obstruct(sf::Texture* texture1, sf::Texture* texture2);
	void create(sf::Vector2f previousCoral);
	void update(float deltaTime, float mapSpeed); // ตำเเหน่ง??
	void draw(sf::RenderWindow &window);
private:
	sf::RectangleShape body;
	int state;
	int coralCount=0;
	std::vector<drawobstacle> coral;
	float randX = 0;
	float randY = 0;
};

//
//	void coralUpdate(float deltaTime , float mapVelocity);
//
//	obstruct(int obstructState, sf::Vector2f pos);
//	void draw(sf::RenderWindow& window);
//	void createObstrcut(std::vector<obstruct> drawObstrcut);
//	sf::Vector2f obstructPosition();
//
//private: 
//	int obstructState;
//	unsigned short int coralRect;
//	unsigned short int coralState;
//		sf::Texture coralTexture1;
//		sf::Texture coralTexture2;
//		sf::RectangleShape body;
//		sf::RectangleShape coralBody1;
//		sf::RectangleShape coralBody2;
//		int randX = 0, randY = 0;
//		sf::Texture obstacle;
//		int state = 0; //สุ่มรูปเเบบอุปสรรค
//		sf::Vector2f velocity;
//		int row;
//		float mapVelocity;
//		//animation animate;
//		std::vector<obstruct> drawObstruct;
//};
//
