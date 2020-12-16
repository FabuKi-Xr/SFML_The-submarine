#pragma once
#include <sfml\Graphics.hpp>
#include <sfml\Audio.hpp>
#include "bullet.h"
#include "hostile.h"
#include "HP.h"
#include <vector>
class Collider
{
public:
	Collider();
	~Collider();
	
	void bulletAndBoss(std::vector<bullet> &bull,hostile &host,int &score,float &bossDamage, bool &checkHP);

	void bulletBossAndPlayer(hostile& host, sf::RectangleShape& player, float& playerDamage, bool& checkPlayerHP);
	
	//float returnDamage(float damage);
	
private:
	sf::Music menu;
	HP boss;
	int critical;
	float bossDamageToPlayer;
	float playerDamageToBoss;
	//std::vector<item> sulfilizer;
};