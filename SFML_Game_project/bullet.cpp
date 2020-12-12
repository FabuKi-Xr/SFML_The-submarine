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

sf::FloatRect bullet::getGlobalBounds()
{
    return sf::FloatRect(body.getGlobalBounds());
}

sf::Vector2f bullet::bulletGetPosition()
{
    return sf::Vector2f(body.getPosition());
}


void bullet::initHitbox()
{
}

void  bullet::update_bullet_hostile(float deltaTime)
{
    velocity.x = -200.0f;
    body.move(velocity * deltaTime);
    animate.updatebullet(row, deltaTime);
    body.setTextureRect(animate.uvRect);
}
