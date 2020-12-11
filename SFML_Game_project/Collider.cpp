#include "Collider.h"

Collider::Collider() 
    //body(body)
{

}
Collider::~Collider()
{
}

void Collider::bulletAndBoss(std::vector<bullet>& bull, hostile &host)
{
    for (int i = 0;i < bull.size();i++)
    {
  
            if (bull[i].getGlobalBounds().intersects(host.hitbox1.getGlobalBounds()))
            {
                std::cout << "crash into hitbox1" << std::endl;
                bull.erase(bull.begin()+i);
                break;
            }
            if (bull[i].getGlobalBounds().intersects(host.hitbox2.getGlobalBounds()))
            {
                std::cout << "crash into hitbox2" << std::endl;
                bull.erase(bull.begin() + i);
                break;
            }
            if (bull[i].getGlobalBounds().intersects(host.hitbox3.getGlobalBounds()))
            {
                std::cout << "crash into hitbox3" << std::endl;
                bull.erase(bull.begin() + i);
                break;
            }
            if (bull[i].getGlobalBounds().intersects(host.hitbox4.getGlobalBounds()))
            {
                std::cout << "crash into hitbox4" << std::endl;
                bull.erase(bull.begin() + i);
                break;
            }
    }
}
//void Collider::bulletBossAndPlayer(std::vector<bullet>& missile, sf::RectangleShape &playerRect)
//{
//    for (int i = 0;i < missile.size();i++)
//    {
//        if (missile[i].getGlobalBounds().intersects(playerRect.getGlobalBounds()))
//        {
//            std::cout << "crash into player!" << std::endl;
//            missile.erase(missile.begin() + i);
//            break;
//        }
//    }
//}



