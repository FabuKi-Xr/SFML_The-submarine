#pragma once
#include "game.h"
#include "animation.h"
class item
{
public:

	item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position);
	~item();
	
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);

	sf::Vector2f sulfilizerGetPosition();
	sf::FloatRect getGlobalBounds();
	void updateSulfilizer(float deltaTime);

private:
	//animation animate;
	sf::RectangleShape body;
	unsigned int row = 0;
	animation animate;
	sf::Vector2f velocity;
	int state = 0;
};

