#include "obstruct.h"
obstruct::obstruct(sf::Texture *texture1, sf::Texture* texture2)
{

	for (int i = 0;i < 3;i++)
	{
		//rand() % 3 + 1;
		if (state == 1) //state เปลี่ยนรูป
		{
			coral.push_back(drawobstacle(texture1, sf::Vector2f(rand() % 100 + 1080, 400.0f)));
			std::cout << "x:%f y:%f" << coral[i].obstacleGetPosition().x << coral[i].obstacleGetPosition().y << std::endl;
			break;
		}
		else
		{
			coral.push_back(drawobstacle(texture2, sf::Vector2f(rand() % 100 + 1080, 400.0f)));
			std::cout << "x:%f y:%f" << coral[i].obstacleGetPosition().x << coral[i].obstacleGetPosition().y << std::endl;
			break;
		}
	}
}

void obstruct::update(float deltaTime,float mapSpeed)
{
	for (drawobstacle& drawobstacle : coral)
	{
		int i = 0;
		if (coral[i].obstacleGetPosition().x <= 5)
		{
			coral.erase(coral.begin() + i);
		}
		else
		{
			coral[i].update(deltaTime,mapSpeed);
		}
			i++;
	}
}

void obstruct::draw(sf::RenderWindow& window)
{
	for (drawobstacle& drawobstacle : coral)
	{
		drawobstacle.draw(window);
	}
}

//obstruct::obstruct()
//{ 
//    if (!coralTexture1.loadFromFile("img/coral1.png"))
//    {
//        std::cout << "cant open coral1" << std::endl;
//    }
//    if (!coralTexture2.loadFromFile("img/coral2.png"))
//    {
//        std::cout << "cant open coral2" << std::endl;
//    }
//
//    coralRect = obstructState;
//
//    if (coralRect == 1)
//    {
//        coralTexture1.setSmooth(true);
//        body.setTexture(&coralTexture1);
//        body.setSize(sf::Vector2f(200.0f, 200.0f));
//        body.setOutlineThickness(1.0f);
//        body.setOutlineColor(sf::Color::Red);
//        body.setPosition(700.0f, 280.0f);//เปลี่ยนไซส์ด้วย!!
//    }
//    else
//    {
//        coralTexture2.setSmooth(true);
//        body.setTexture(&coralTexture2);
//        body.setSize(sf::Vector2f(200.0f, 200.0f));
//        body.setOutlineThickness(1.0f);
//        body.setOutlineColor(sf::Color::Red);
//        body.setPosition(700.0f, 280.0f);//เปลี่ยนไซส์ด้วย!!
//    }
//
//    
//
//    /*this->body = body;
//    body.setSize(sf::Vector2f(200.0f, 100.0f));
//    body.setScale(1, 1);
//    body.setOrigin(body.getSize() / 2.0f);
//    body.setPosition(position);
//    body.setTexture(texture);*/
//}
//
//void obstruct::update(float deltaTime, float mapVelocity)
//{
//    
//    for (int i = 0;i < drawObstruct.size();i++)
//    {
//        if (drawObstruct[i].obstructPosition().x <= -100.0f) //สิ่งกีดขวางเกินขอบ
//        {
//            drawObstruct.erase(drawObstruct.begin() + i);
//        }
//        else  coralUpdate(deltaTime, mapVelocity);
//    }
//    
//}
//void  obstruct::coralUpdate(float deltaTime, float mapVelocity)
//{
//    velocity.x = mapVelocity;
//    coralBody1.move(velocity * deltaTime);
//
//}
//void  obstruct::draw(sf::RenderWindow& window)
//{
//    window.draw(body);
//}
//
//void obstruct::createObstrcut(std::vector<obstruct> drawObstruct)
//{
//    for (int i = 0;i < 3;i++)
//    {
//        coralState = rand() % 3 + 1;
//        drawObstruct.push_back(obstruct(coralState,sf::Vector2f(rand()%50+1,500)));
//    }
//}
//
//sf::Vector2f obstruct::obstructPosition()
//{
//    return sf::Vector2f(body.getPosition());
//}


