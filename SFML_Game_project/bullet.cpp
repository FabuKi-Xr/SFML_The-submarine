#include "bullet.h"
#include<iostream>

bullet::bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f pos) :
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
}
void bullet::update(float deltaTime)
{

    if (body.getPosition().x != NULL - 100 && body.getPosition().y != NULL - 100)
    {
        body.move(0, * deltaTime);
        animation.UpdateBullet(row, deltaTime);
        body.setTextureRect(animation.uvRect);
    }
}

void Bulletpoke::updateDOWN(float deltaTime)
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

void Bulletpoke::updateRIGHT(float deltaTime)
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

void Bulletpoke::updateLEFT(float deltaTime)
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


void Bulletpoke::attackL(sf::Vector2f pos)
{
    body.setPosition(pos.x - 53.0f, pos.y + 10.0f);

}
void Bulletpoke::attackR(sf::Vector2f pos) {
    body.setPosition(pos.x + 53.0f, pos.y + 10.0f);

}
void Bulletpoke::attackU(sf::Vector2f pos) {
    body.setPosition(pos.x, pos.y - 53.0f);
}
void Bulletpoke::attackD(sf::Vector2f pos) {
    body.setPosition(pos.x, pos.y + 53.0f);
}

void Bulletpoke::deletepoke()
{
    body.setPosition(NULL - 100, NULL - 100);
}

void Bulletpoke::draw(sf::RenderWindow& window)
{
    window.draw(body);
}