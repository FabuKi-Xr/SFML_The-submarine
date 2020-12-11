#pragma once
#include "game.h"
#include "animation.h"
class player
{
public:
	sf::Sprite playerSprite;
	sf::IntRect playerRect;
	sf::Texture playerTexture;
	sf::Vector2u currentImage;
	sf::Vector2u imageCount;
	
	float totalTime = 0;
	float switchTime = 0.1;
public:
	player();
	~player();
	
};

