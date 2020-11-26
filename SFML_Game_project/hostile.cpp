#include "hostile.h"

hostile::hostile(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position) : animate(texture, imageCount, switchTime)
{
    this->row = 0;
    body.setSize(sf::Vector2f(300.0f, 150.0f));
    body.setScale(1.5,1.5);
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(position);
    body.setTexture(texture);
}
hostile::~hostile()
{

}
void  hostile::update(float deltaTime,float posPlayer)
{
    this->velocity ;
    velocity.x = 200.0f;

    if (body.getPosition().x >= 930)
    {
        body.move(-velocity * deltaTime);
    }
    //else body.setPosition(800, body.getPosition().y);
    std::cout << "\nhostile position(x) : " << body.getPosition().x << std::endl;
   // body.move(velocity * deltaTime);
   // animate.updatebullet(row, deltaTime);
    body.setTextureRect(animate.uvRect);

}
void hostile::draw(sf::RenderWindow& window)
{

    window.draw(body);

}