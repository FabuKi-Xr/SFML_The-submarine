#pragma once
#include<SFML\Graphics.hpp>
class bullet
{
private:
	float speed;
	float row;
	sf::RectangleShape body;
public: 
	bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f pos);
	void update(float deltaTime);
};

