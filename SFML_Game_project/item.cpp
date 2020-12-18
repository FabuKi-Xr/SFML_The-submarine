#include "item.h"

item::item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position):
	animate(texture,imageCount,switchTime)
{ 
    body.setSize(sf::Vector2f(40.0f, 40.0f));
    body.setScale(1, 1);
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(position);
    body.setOutlineColor(sf::Color::Transparent);
    body.setTexture(texture);
    body.setOutlineThickness(1.0f);
}

item::~item()
{
}

void item::update(float deltaTime)
{
    animate.update(row, deltaTime);
    body.setTextureRect(animate.uvRect);
}

void item::draw(sf::RenderWindow& window)
{
    window.draw(body);
}

sf::Vector2f item::sulfilizerGetPosition()
{
    return sf::Vector2f (body.getPosition());
}

sf::FloatRect item::getGlobalBounds()
{
    return sf::FloatRect(body.getGlobalBounds());
}

void item::updateSulfilizer(float deltaTime)
{
    deltaTime *= 0.5;
    state = rand() % 2;
    if (state = 0) 
    {
        velocity.y = rand() % 30 + 10;
    }
    else { velocity.y = rand()%40 +15 ; }
    velocity.x = rand() % 120 + 100;
    velocity.x *= -1.0f;
    body.move(velocity * deltaTime);
    animate.updatebullet(row, deltaTime);
    body.setTextureRect(animate.uvRect);
}

