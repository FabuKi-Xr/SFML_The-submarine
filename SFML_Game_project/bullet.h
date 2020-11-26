#pragma once
#include "animation.h"
#include<SFML\Graphics.hpp>
class bullet
{
private:

	sf::RectangleShape body;
	sf::Texture texture;
    float switchTime;
    animation animate;
    unsigned int row;
    sf::Vector2f velocity;
    /*animation updatebullet;
	animation Animation;
	animation UpdateBullet;
    int faceD;
    float speed;
    sf::RectangleShape body;
    unsigned int row;
    sf::Vector2f velocity;*/

public: 

    void update_bullet_hostile(float deltaTime);
    bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position);
    void bullet_hostile(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position);
    ~bullet();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    /*void updateUP(float deltaTime);
    void updateDOWN(float deltaTime);
    void updateRIGHT(float deltaTime);
    void updateLEFT(float deltaTime);
    void attackL(sf::Vector2f pos);
    void attackR(sf::Vector2f pos);
    void attackU(sf::Vector2f pos);
    void attackD(sf::Vector2f pos);
    void draw(sf::RenderWindow& window);
    void deletepoke();*/
	
   /* sf::Vector2f GetPosition() { return body.getPosition(); }
    Collision GetCollider() { return Collision(body); }*/
};

