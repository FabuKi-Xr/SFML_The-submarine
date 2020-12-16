#include "item.h"

item::item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position):
	animate(texture,imageCount,switchTime)
{
    body.setSize(sf::Vector2f(300.0f, 150.0f));
    body.setScale(1.5, 1.5);
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(position);
    body.setOutlineColor(sf::Color::Transparent);
    body.setTexture(texture);
    body.setOutlineThickness(1.0f);
}

item::~item()
{
}

void item::update(float deltaTime, sf::RectangleShape &player)
{
    animate.update(row, deltaTime);
    body.setTextureRect(animate.uvRect);
}

void item::draw(sf::RenderWindow& window)
{
    window.draw(body);
}
