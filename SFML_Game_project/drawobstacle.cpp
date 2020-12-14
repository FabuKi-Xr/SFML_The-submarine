#include "drawobstacle.h"

drawobstacle::drawobstacle(sf::Texture* texture, sf::Vector2f position)
{
    body.setSize(sf::Vector2f(300.0f, 400.0f));
    body.setScale(1, 1);
    body.setOrigin(body.getSize() / 2.0f);
    body.setOutlineColor(sf::Color::Red);
    body.setOutlineThickness(1.0f);
    body.setPosition(position);
    body.setTexture(texture);
}
drawobstacle::~drawobstacle()
{
}
void  drawobstacle::update(float deltaTime,float mapSpeed)
{
    velocity.x = mapSpeed;
    body.move(velocity * deltaTime);

}

void drawobstacle::draw(sf::RenderWindow& window)
{
    window.draw(body);
}

sf::FloatRect drawobstacle::getGlobalBounds()
{
    return sf::FloatRect(body.getGlobalBounds());
}

sf::Vector2f drawobstacle::obstacleGetPosition()
{
    return sf::Vector2f(body.getPosition());
}
