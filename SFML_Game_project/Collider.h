#pragma once
#include <sfml\Graphics.hpp>
#include "bullet.h"
#include "hostile.h"
class Collider
{
public:
	Collider();
	~Collider();
	
	void bulletAndBoss(std::vector<bullet> &bull,hostile &host,int &score);

	void bulletBossAndPlayer(hostile& host, sf::RectangleShape& playerPosition);
private:
	
};