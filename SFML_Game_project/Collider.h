#pragma once
#include <sfml\Graphics.hpp>
#include "bullet.h"
#include "hostile.h"
#include "HP.h"
class Collider
{
public:
	Collider();
	~Collider();
	
	void bulletAndBoss(std::vector<bullet> &bull,hostile &host,int &score,float &bossDamage, int checkHP);

	void bulletBossAndPlayer(hostile& host, sf::RectangleShape& playerPosition, float& playerDamage);
	
	//float returnDamage(float damage);
	
private:
	HP boss;
	float playerDamageToBoss;
};