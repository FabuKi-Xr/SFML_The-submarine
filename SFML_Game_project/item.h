#pragma once
#include "game.h"
#include "animation.h"
class item
{
public:

	item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position);
	~item();
	
	void update(float deltaTime , sf::RectangleShape& player);
	void draw(sf::RenderWindow& window);

private:
	//animation animate;
	sf::RectangleShape body;
	unsigned int row;
	animation animate;
};

