#pragma once
#include <sfml\Graphics.hpp>
#include "bullet.h"
#include "hostile.h"
class Collider
{
public:
	Collider();
	~Collider();

	void bulletAndBoss(std::vector<bullet> &bull,hostile &host);

	//void bulletBossAndPlayer(std::vector<bullet>& missile, sf::RectangleShape& playerPosition);

private:
	
};