#include "Collider.h"

Collider::Collider() 
    //body(body)
{

}
Collider::~Collider()
{
}

void Collider::bulletAndBoss(std::vector<bullet>& bull, hostile &host, int& score)
{
    for (int i = 0;i < bull.size();i++)
    {
            //คะเเนนที่ยิงได้เป็นเเบบสุ่ม เเต่ถ้าโดน หน้าเรือหรือคอนโซนเรือบริเวณด้านล่างจะ fix ที่ 3500
            if (bull[i].getGlobalBounds().intersects(host.hitbox1.getGlobalBounds()))
            {
                std::cout << "crash into hitbox1" << std::endl;
                bull.erase(bull.begin()+i);
                score += 3500;
                break;
            }
            if (bull[i].getGlobalBounds().intersects(host.hitbox2.getGlobalBounds()))
            {
                std::cout << "crash into hitbox2" << std::endl;
                bull.erase(bull.begin() + i);
                score += rand()%2001+1900;
                break;
            }
            if (bull[i].getGlobalBounds().intersects(host.hitbox3.getGlobalBounds()))
            {
                std::cout << "crash into hitbox3" << std::endl;
                bull.erase(bull.begin() + i);
                score += rand()%1850+1700;
                break;
            }
            if (bull[i].getGlobalBounds().intersects(host.hitbox4.getGlobalBounds()))
            {
                std::cout << "crash into hitbox4" << std::endl;
                bull.erase(bull.begin() + i);
                score += rand()%1700+1499;
                break;
            }
    }
}
void Collider::bulletBossAndPlayer(hostile &host, sf::RectangleShape& player)
{
    for (int i = 0;i < host.missile.size();i++)
    {
        //int i = 0;
        if (host.missile[i].getGlobalBounds().intersects(player.getGlobalBounds()))
        {
            std::cout << "crash into player!" << std::endl;
            host.missile.erase(host.missile.begin() + i);
            break;
        }
       // i++;
    }
}



