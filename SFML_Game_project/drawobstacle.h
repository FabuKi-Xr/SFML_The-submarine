#pragma once
#include<SFML/Graphics.hpp>
class drawobstacle
{
public:

	drawobstacle(sf::Texture* texture,sf::Vector2f position);

	~drawobstacle();

	void draw(sf::RenderWindow& window);

	void update(float deltaTime, float mapSpeed);

	sf::FloatRect getGlobalBounds();

	sf::Vector2f obstacleGetPosition();

private:
	sf::RectangleShape body;
	sf::Vector2f velocity;
};

