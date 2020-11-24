#pragma once
#include<SFML\Graphics.hpp>
class animation
{

public:
	animation(sf::Texture* texture, sf::Vector2u imageCount, float switchtime);
	~animation();

	void update(int row, float deltatime);
	void updatebullet(int row, float deltatime);
	void render();

public:
	sf::IntRect uvRect;

private:
	float switchtime;
	float totaltime;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
};



