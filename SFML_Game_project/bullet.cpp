#include "bullet.h"
#include<iostream>

bullet::bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position):animate(texture, imageCount, switchTime)
{
    this->row = 0;
    body.setSize(sf::Vector2f(100.0f, 100.0f));
    body.setScale(0.5,0.5);
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(position);
    body.setTexture(texture);
}
bullet::~bullet()
{
}
void  bullet::update(float deltaTime)
{
    velocity.x = 200.0f;
    body.move(velocity * deltaTime);
    animate.updatebullet(row, deltaTime);
    body.setTextureRect(animate.uvRect);
}
void bullet::draw(sf::RenderWindow& window)
{

    window.draw(body);

}

void  bullet::update_bullet_hostile(float deltaTime)
{
    velocity.x = 200.0f;
    body.move(velocity * deltaTime);
    animate.updatebullet(row, deltaTime);
    body.setTextureRect(animate.uvRect);
}
/*bullet::bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f pos) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
    body.setSize(sf::Vector2f(50.0f, 50.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(pos);
    body.setTexture(texture);

}
bullet::~bullet()
{
}*/

/*
void bullet::update(float deltaTime)
{

    if (body.getPosition().x != NULL - 100 && body.getPosition().y != NULL - 100)
    {
        body.move(0, deltaTime);
        Animation.UpdateBullet(row, deltaTime);
        body.setTextureRect(Animation.uvRect);
    }
}

void bullet::updateDOWN(float deltaTime)
{
    velocity.x = 0;
    velocity.y = speed * 2;
    if (body.getPosition().x != NULL - 100 && body.getPosition().y != NULL - 100)
    {
        body.move(0, velocity.y * deltaTime);
        animation.UpdateBullet(row, deltaTime);
        body.setTextureRect(animation.uvRect);
    }
}

void bullet::updateRIGHT(float deltaTime)
{
    velocity.x = speed * 2;
    velocity.y = speed * 2;
    if (body.getPosition().x != NULL - 100 && body.getPosition().y != NULL - 100)
    {
        body.move(velocity.x * deltaTime, 0);
        animation.UpdateBullet(row, deltaTime);
        body.setTextureRect(animation.uvRect);
    }
}

void bullet::updateLEFT(float deltaTime)
{
    velocity.x = speed * 2;
    velocity.y = speed * 2;
    if (body.getPosition().x != NULL - 100 && body.getPosition().y != NULL - 100)
    {
        body.move(-velocity.x * deltaTime, 0);
        animation.UpdateBullet(row, deltaTime);
        body.setTextureRect(animation.uvRect);
    }
}


void bullet::attackL(sf::Vector2f pos)
{
    body.setPosition(pos.x - 53.0f, pos.y + 10.0f);

}
void bullet::attackR(sf::Vector2f pos) {
    body.setPosition(pos.x + 53.0f, pos.y + 10.0f);

}
void bullet::attackU(sf::Vector2f pos) {
    body.setPosition(pos.x, pos.y - 53.0f);
}
void bullet::attackD(sf::Vector2f pos) {
    body.setPosition(pos.x, pos.y + 53.0f);
}

void bullet::deletepoke()
{
    body.setPosition(NULL - 100, NULL - 100);
}

void bullet::draw(sf::RenderWindow& window)
{
    window.draw(body);
*/