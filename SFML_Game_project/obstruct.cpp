#include "obstruct.h"

obstruct::obstruct(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position):animate(texture, imageCount, switchTime)
{ 
    this->body = body;
    body.setSize(sf::Vector2f(200.0f, 100.0f));
    body.setScale(1, 1);
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(position);
    body.setTexture(texture);
}
void obstruct::update(float deltaTime)
{
    velocity.x = 200.0f; //ความเร็วเคลื่อนเท่าเเมพ!!?
    body.move(velocity * deltaTime);
    animate.updatebullet(row, deltaTime);
    body.setTextureRect(animate.uvRect);
}
void  obstruct::draw(sf::RenderWindow& window)
{

    window.draw(body);

}