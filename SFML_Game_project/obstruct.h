#pragma once
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<SFML\Graphics.hpp>
#include "animation.h"
class obstruct
{
public:

	void object_rand(sf::Texture obstruct);
	void update(float deltaTime); // ตำเเหน่ง??
	obstruct(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f pos);
	void draw(sf::RenderWindow& window);

private: 
		sf::RectangleShape body;
		int randX = 0, randY = 0;
		sf::Texture obstacle;
		int state = 0; //สุ่มรูปเเบบอุปสรรค
		sf::Vector2f velocity;
		int row;
		animation animate;
};

