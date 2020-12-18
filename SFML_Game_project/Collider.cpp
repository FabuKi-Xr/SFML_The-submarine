#include "Collider.h"

Collider::Collider()
{
}
Collider::~Collider()
{
}

void Collider::bulletAndBoss(std::vector<bullet>& bull, hostile &host, int& score, float& bossDamage,bool &checkHP,sf::Texture *sulfilizerTexture,int &combo)
{
    //std::cout << "combo: " << combo << std::endl;
    for (int i = 0;i < bull.size();i++)
    {
            //คะเเนนที่ยิงได้เป็นเเบบสุ่ม เเต่ถ้าโดน หน้าเรือหรือคอนโซนเรือบริเวณด้านล่างจะ fix ที่ 3500
            if (bull[i].getGlobalBounds().intersects(host.hitbox1.getGlobalBounds()))
            {
                checkHP = 1;
                combo++;
                bull.erase(bull.begin()+i);
                score += 3500;
                playerDamageToBoss = 5;
                bossDamage = playerDamageToBoss;
                if (isHitPlayer == false)
                    {
                        score += (80 * combo);
                    }

                scoreItemState = rand() % 10 + 1;
                if (scoreItemState >= 4 && scoreItemState <= 6)
                    { 
                        j = 1; 
                    }

                else 
                    { 
                        j = 0; 
                    }

                for(int k = 0;k<j;k++)
                    {
                        host.sulfilizer.push_back(item(sulfilizerTexture, sf::Vector2u(3, 1), 0.1f, sf::Vector2f(host.body.getPosition().x + (rand() % 20), host.body.getPosition().y - (rand() % 20 + 15))));
                    }
                break;
            }
            if (bull[i].getGlobalBounds().intersects(host.hitbox2.getGlobalBounds()))
            {
                checkHP = 1;
                combo++;
                bull.erase(bull.begin() + i);
                score += rand()%2001+1900;
                playerDamageToBoss = rand() % 4 + 2;
                bossDamage = playerDamageToBoss;
                if (isHitPlayer == false)
                {
                    score += (70 * combo);
                }
                if (scoreItemState >= 4 && scoreItemState <= 6)
                {
                    j = 1;
                }
                else
                {
                    j = 0;
                }

                for (int k = 0;k < j;k++)
                {
                    host.sulfilizer.push_back(item(sulfilizerTexture, sf::Vector2u(3, 1), 0.1f, sf::Vector2f(host.body.getPosition().x + (rand() % 20), host.body.getPosition().y - (rand() % 20 + 15))));
                }
                break;
            }
            if (bull[i].getGlobalBounds().intersects(host.hitbox3.getGlobalBounds()))
            {
                checkHP = 1;
                combo++;
                bull.erase(bull.begin() + i);
                score += rand()%1850+1700;
                playerDamageToBoss = rand()%3 +2;
                bossDamage = playerDamageToBoss;
                if (isHitPlayer == false)
                {
                    score += (60 * combo);
                }
                if (scoreItemState >= 4 && scoreItemState <= 6)
                {
                    j = 1;
                }
                else
                {
                    j = 0;
                }

                for (int k = 0;k < j;k++)
                {
                    host.sulfilizer.push_back(item(sulfilizerTexture, sf::Vector2u(3, 1), 0.1f, sf::Vector2f(host.body.getPosition().x + (rand() % 20), host.body.getPosition().y - (rand() % 20 + 15))));
                }
                break;
            }
            if (bull[i].getGlobalBounds().intersects(host.hitbox4.getGlobalBounds()))
            {
                checkHP = 1;
                combo++;
                bull.erase(bull.begin() + i);
                playerDamageToBoss= 1.0;
                bossDamage = playerDamageToBoss;
                score += rand() % 1700 + 1499;
                if (isHitPlayer == false)
                {
                    score += (50 * combo);
                }
                if (scoreItemState >= 4 && scoreItemState <= 6)
                {
                    j = 1;
                }
                else
                {
                    j = 0;
                }

                for (int k = 0;k < j;k++)
                {
                    host.sulfilizer.push_back(item(sulfilizerTexture, sf::Vector2u(3, 1), 0.1f, sf::Vector2f(host.body.getPosition().x + (rand() % 20), host.body.getPosition().y - (rand() % 20 + 15))));
                }
                break;
            }
    }
}
void Collider::bulletBossAndPlayer(hostile &host, sf::RectangleShape& player, float& playerDamage, bool& checkplayerHP, int& combo)
{
    if (host.body.getGlobalBounds().intersects(player.getGlobalBounds()))
    {
        playerDamage = 10;
    }
    for (int i = 0;i < host.missile.size();i++)
    {
        critical = rand() % 15 + 1;
        if (host.missile[i].getGlobalBounds().intersects(player.getGlobalBounds()))
        {
            checkplayerHP = 1;
            isHitPlayer = true;
            combo = 0;
            host.missile.erase(host.missile.begin() + i);
            if (critical == 7 || critical == 11)
            {
                bossDamageToPlayer = rand() % 9 + 5;
            }
            else { bossDamageToPlayer = rand()% 7 + 3; }
            playerDamage = bossDamageToPlayer;
            critical = 0;
            break;
        }
    }
}

void Collider::sulfilizerAndPlayer(hostile& host, std::vector<item>& item, sf::RectangleShape& player,int &score)
{
    for (int i = 0;i < host.sulfilizer.size();i++)
    {
        if (host.sulfilizer[i].getGlobalBounds().intersects(player.getGlobalBounds()))
        {
            host.sulfilizer.erase(host.sulfilizer.begin() + i);
            score += rand() % 4001 + 1000;
            break;
        }
    }
}


void Collider::update(float deltaTime,hostile &host)
{
    for (item& item : host.sulfilizer)
    {
        int i = 0;
        if (host.sulfilizer[i].sulfilizerGetPosition().y >= 5)
        {
            host.sulfilizer.erase(host.sulfilizer.begin() + i);
        }
        else item.updateSulfilizer(deltaTime);
        //std::cout << "missile size: " << missile.size() << std::endl;
        i++;

    }
}




