#pragma once
#include"game.h"
#include<stdio.h>
#include<iostream>
class obstruct
{
public:

	void obs_rand(sf::Texture obstruct);

private: sf::Texture obstruct;

		int randX = 0, randY = 0;
		sf::Texture obstacle;
		
};

