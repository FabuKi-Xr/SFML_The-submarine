#pragma once
#include "animation.h"
#include<SFML\Graphics.hpp>
#include "item.h"
class bullet
{
private:

	sf::RectangleShape body;
	sf::Texture texture;
    float switchTime;
    animation animate;
    unsigned int row;
    sf::Vector2f velocity;
    
public: 
    void update_bullet_hostile(float deltaTime);
    bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position);
    void bullet_hostile(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position);
    ~bullet();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getGlobalBounds();

    sf::Vector2f bulletGetPosition();
};

