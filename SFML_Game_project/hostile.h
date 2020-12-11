#pragma once
#include "game.h"
#include "animation.h"
#include "bullet.h"
#include <vector>
class hostile
{

public:

	hostile(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position);
	~hostile();
	void update(float deltaTime,float posPlayer);
	void draw(sf::RenderWindow& window);
	sf::FloatRect getGlobalBounds();
	sf::RectangleShape body;
	sf::RectangleShape hitbox1;
	sf::RectangleShape hitbox2;
	sf::RectangleShape hitbox3;
	sf::RectangleShape hitbox4;
	sf::RectangleShape missileBody;
	void initHitbox();
	void canMissileShoot(float deltaTime,float missileCooldown, sf::Texture *missile_texture);

	//void missilePosition(std::vector<bullet>& missile);
	//void ReceivePlayerRect(sf::RectangleShape& playerRect);

private:
	sf::Texture texture;
	float switchTime;
	animation animate;
	unsigned int row;
	sf::Vector2f velocity;
	bool direction;
	std::vector<bullet> missile;

	float missileCooldown;
	sf::Clock bull_boss;
	//Collider playerAttacked;
};

