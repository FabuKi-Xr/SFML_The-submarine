#pragma once
#include "game.h"
#include "animation.h"
class hostile
{

public:

	hostile(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position);
	~hostile();
	void update(float deltaTime,float posPlayer);
	void draw(sf::RenderWindow& window);
	
private:
	sf::RectangleShape body;
	sf::Texture texture;
	float switchTime;
	animation animate;
	unsigned int row;
	sf::Vector2f velocity;
};

