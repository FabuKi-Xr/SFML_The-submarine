#pragma once
#include"game.h"
#include<stdio.h>
#include<iostream>
class Obstruction
{
public: 
		void obs_rand(sf::Texture obstruct);
		
private:
	sf::Texture obstruct;
	int randX=0, randY=0;
}; //random type of obstruction ??
void Obstruction::obs_rand(sf::Texture obstruct) {
	if (!obstruct.loadFromFile("img/.....")) {
		printf("loading failure");
	}
	sf::Sprite obs;
	obs.setTexture(obstruct);
	for (int round = 0; round < 3; round++)
	{
		randY = rand() % 4 + 2;
		randX = rand() % 60 + 10;
		obs.setTextureRect(sf::IntRect(randX, randY, 300, 300));
		randX = 0;
		randY = 0;
	}
	
}


