#pragma once
#include <sfml\Graphics.hpp>
#include <sfml\Audio.hpp>
#include "bullet.h"
#include "hostile.h"
#include "HP.h"
#include <vector>
#include "item.h"
class Collider
{
public:
	Collider();
	~Collider();
	
	void bulletAndBoss(std::vector<bullet> &bull,hostile &host,int &score,float &bossDamage, bool &checkHP, sf::Texture* sulfilizerTexture);

	void bulletBossAndPlayer(hostile& host, sf::RectangleShape& player, float& playerDamage, bool& checkPlayerHP);
	
	void sulfilizerAndPlayer(hostile& host,std::vector<item>& item, sf::RectangleShape& player,int &score);

	void update(float deltaTime,hostile & host);

	
private:
	HP boss;
	int critical;
	
	float bossDamageToPlayer;
	float playerDamageToBoss;
	bool isHitPlayer = false; // are player hit by boss's missile?
	int combo = 0;

	sf::Texture sulfilizerTexture;
	int scoreItemState = 0;
	int j = 0;
	//std::vector<item> sulfilizer;
};