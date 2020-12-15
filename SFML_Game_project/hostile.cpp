#include "hostile.h"

hostile::hostile(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position) : animate(texture, imageCount, switchTime)
{
    this->row = 0;
    body.setSize(sf::Vector2f(300.0f, 150.0f));
    body.setScale(1.5,1.5);
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(position);
    body.setOutlineColor(sf::Color::Transparent);
    body.setTexture(texture);
    body.setOutlineThickness(1.0f);
    direction = rand() % 2;
    initHitbox();

    hitbox1.setPosition(sf::Vector2f(body.getPosition().x - 30.0f, body.getPosition().y + 40));

    hitbox2.setPosition(sf::Vector2f(body.getPosition().x+50 , body.getPosition().y+15));

    hitbox3.setPosition(sf::Vector2f(body.getPosition().x + 95, body.getPosition().y -12));

    hitbox4.setPosition(sf::Vector2f(body.getPosition().x + 130, body.getPosition().y - 30));
}
void hostile::initHitbox()
{

    hitbox1.setSize(sf::Vector2f(body.getSize().x+65 , body.getSize().y-90));
    hitbox1.setFillColor(sf::Color::Transparent);
    hitbox1.setOutlineColor(sf::Color::Transparent);
    hitbox1.setOutlineThickness(1.0f);
    hitbox1.setOrigin(hitbox1.getGlobalBounds().width / 2, hitbox1.getGlobalBounds().height / 2);

    hitbox2.setSize(sf::Vector2f(200.0f,25.0f));
    hitbox2.setFillColor(sf::Color::Transparent);
    hitbox2.setOutlineColor(sf::Color::Transparent);
    hitbox2.setOutlineThickness(1.0f);
    hitbox2.setOrigin(hitbox1.getGlobalBounds().width / 2, hitbox1.getGlobalBounds().height / 2);

    hitbox3.setSize(sf::Vector2f(100.0f, 25.0f));
    hitbox3.setFillColor(sf::Color::Transparent);
    hitbox3.setOutlineColor(sf::Color::Transparent);
    hitbox3.setOutlineThickness(1.0f);
    hitbox3.setOrigin(hitbox1.getGlobalBounds().width / 2, hitbox1.getGlobalBounds().height / 2);

    hitbox4.setSize(sf::Vector2f(50.0f, 25.0f));
    hitbox4.setFillColor(sf::Color::Transparent);
    hitbox4.setOutlineColor(sf::Color::Transparent);
    hitbox4.setOutlineThickness(1.0f);
    hitbox4.setOrigin(hitbox1.getGlobalBounds().width / 2, hitbox1.getGlobalBounds().height / 2);
}
void hostile::canMissileShoot(float deltaTime, float missileCooldown, sf::Texture *missile_texture)
{

    this->missileCooldown;
    this->missileCooldown = bull_boss.getElapsedTime().asMilliseconds();

    if (body.getPosition().x <= 930)
    {
        isShootting = rand() % 3 + 1;
        if (this->missileCooldown >= missileCooldown)
        {
            //this->missileCooldown -= missileCooldown;
            if (isShootting < 3)
            {
                missile.push_back(bullet(missile_texture, sf::Vector2u(3, 1), 0.1f, sf::Vector2f(body.getPosition().x - 20, body.getPosition().y + 70)));
            }
            bull_boss.restart();
            //std::cout << "[boss]missile has been released" << std::endl;
        }
    }  

}

hostile::~hostile()
{

}
void  hostile::update(float deltaTime,float posPlayer, sf::RectangleShape& player)
{
    this->velocity ;

    //ให้ยานเลื่อนเข้ามา
    velocity.x = 200.0f;
    if (body.getPosition().x >= 930)
    {
        body.move(-velocity * deltaTime);
    }

    //std::cout << "\nhostile position(x) : " << body.getPosition().x << std::endl;

    //ด่าน 1 40 ด่าน 2 75 ด่าน 3 100
    if (direction == 0) 
    {
        body.move(0,-40.0f*deltaTime);
        if (body.getPosition().y <= 300)
        {
            direction = 1;
        }
    }
    else
    {
        body.move(0, 40.0f * deltaTime);
        if (body.getPosition().y >= 600)
        {
            direction = 0;
        }
    }

    body.setTextureRect(animate.uvRect);
    //------ Hitbox ------//
    hitbox1.setPosition(sf::Vector2f(body.getPosition().x - 30.0f, body.getPosition().y + 40));

    hitbox2.setPosition(sf::Vector2f(body.getPosition().x + 50, body.getPosition().y + 15));

    hitbox3.setPosition(sf::Vector2f(body.getPosition().x + 95, body.getPosition().y - 12));

    hitbox4.setPosition(sf::Vector2f(body.getPosition().x + 130, body.getPosition().y - 40));
   
    for (bullet& bullet : missile)
    {
        int i = 0;
        if (missile[i].bulletGetPosition().x <= 5 )
        {
            missile.erase(missile.begin() + i);
        }
        else bullet.update_bullet_hostile(deltaTime);
        //std::cout << "missile size: " << missile.size() << std::endl;
        i++;
        
    }
    //std::cout << "missile size: " << missile.size()<<std::endl;
}
void hostile::draw(sf::RenderWindow& window)
{
    
    window.draw(body);
    window.draw(hitbox1);
    window.draw(hitbox2);
    window.draw(hitbox3);
    window.draw(hitbox4);
    for (bullet& bullet : missile)
        bullet.draw(window);
}

sf::FloatRect hostile::getGlobalBounds()
{
    return sf::FloatRect(body.getGlobalBounds());
}
