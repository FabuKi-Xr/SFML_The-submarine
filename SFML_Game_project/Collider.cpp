#include "Collider.h"

Collider::Collider()
{

}
Collider::~Collider()
{
}

void Collider::bulletAndBoss(std::vector<bullet>& bull, hostile &host, int& score, float& bossDamage,bool &checkHP)
{
    for (int i = 0;i < bull.size();i++)
    {
            //คะเเนนที่ยิงได้เป็นเเบบสุ่ม เเต่ถ้าโดน หน้าเรือหรือคอนโซนเรือบริเวณด้านล่างจะ fix ที่ 3500
            if (bull[i].getGlobalBounds().intersects(host.hitbox1.getGlobalBounds()))
            {
                checkHP = 1;
                std::cout << "crash into hitbox1" << std::endl;
                bull.erase(bull.begin()+i);
                score += 3500;
                playerDamageToBoss = 12.5;
                bossDamage = playerDamageToBoss;
                //boss.playerHitBossDamage(playerDamageToBoss);
                //boss.damage = playerDamageToBoss;
                break;
            }
            if (bull[i].getGlobalBounds().intersects(host.hitbox2.getGlobalBounds()))
            {
                checkHP = 1;
                std::cout << "crash into hitbox2" << std::endl;
                bull.erase(bull.begin() + i);
                score += rand()%2001+1900;
                playerDamageToBoss = 10.0;
                bossDamage = playerDamageToBoss;
                //boss.playerHitBossDamage(playerDamageToBoss);
                //boss.damage = playerDamageToBoss;
                break;
            }
            if (bull[i].getGlobalBounds().intersects(host.hitbox3.getGlobalBounds()))
            {
                checkHP = 1;
                std::cout << "crash into hitbox3" << std::endl;
                bull.erase(bull.begin() + i);
                score += rand()%1850+1700;
                playerDamageToBoss = 10.0;
                bossDamage = playerDamageToBoss;
                //boss.playerHitBossDamage(playerDamageToBoss);
                //boss.damage = playerDamageToBoss;
                break;
            }
            if (bull[i].getGlobalBounds().intersects(host.hitbox4.getGlobalBounds()))
            {
                checkHP = 1;
                std::cout << "crash into hitbox4" << std::endl;
                bull.erase(bull.begin() + i);
                score += rand()%1700+1499;
                playerDamageToBoss= 10.0;
                bossDamage = playerDamageToBoss;
                //boss.playerHitBossDamage(playerDamageToBoss);
                //boss.damage = playerDamageToBoss;
                break;
            }
    }
}
void Collider::bulletBossAndPlayer(hostile &host, sf::RectangleShape& player, float& playerDamage, bool& checkplayerHP)
{
    for (int i = 0;i < host.missile.size();i++)
    {
        critical = rand() % 15 + 1;
        if (host.missile[i].getGlobalBounds().intersects(player.getGlobalBounds()))
        {
            checkplayerHP = 1;
            std::cout << "crash into player!" << std::endl;
            host.missile.erase(host.missile.begin() + i);
            if (critical == 7)
            {
                bossDamageToPlayer = rand() % 15 + 7;
            }
            else { bossDamageToPlayer = rand()% 10 + 5; }
            playerDamage = bossDamageToPlayer;
            critical = 0;
            break;
        }
    }
}

//float Collider::returnDamage(float damage)
//{
//    return damage;
//}




