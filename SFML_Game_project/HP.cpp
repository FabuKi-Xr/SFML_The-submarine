#include "HP.h"

HP::HP()
{
	//this->damage=bossDamage;
	if (!HPframeTexture.loadFromFile("img/HPbarFrame.png"))
	{
		std::cout << "cant open HPbarFrame" << std::endl;
	}
	if (!HPcolorTexture.loadFromFile("img/HPbarColor.png"))
	{
		std::cout << "cant open HPbarFrame" << std::endl;
	}
	if (!heart.loadFromFile("img/heart-icon.png"))
	{
		printf("\ncant open heart_icon\n");
	}
		HPframeTexture.setSmooth(true);
		HPbarFrame.setTexture(&HPframeTexture);
		HPbarFrame.setSize(sf::Vector2f(200.0f, 30.0f));
		HPbarFrame.setPosition(80.0f, 30.0f);

		HPcolorTexture.setSmooth(true);
		HPbarColor.setTexture(&HPcolorTexture);
		HPbarColor.setSize(sf::Vector2f(200.0f, 30.0f));
		HPbarColor.setPosition(80.0f, 30.0f);

		heart.setSmooth(true);
		heartBody.setTexture(&heart);
		heartBody.setSize(sf::Vector2f(50.0f,50.0f));
		heartBody.setPosition(20.0f, 20.0f);
		
}

void HP::HPboss()
{
	if (!HPframeTexture.loadFromFile("img/HPbarFrame.png"))
	{
		std::cout << "cant open HPbarFrame" << std::endl;
	}
	if (!HPcolorTexture.loadFromFile("img/HPbarColor.png"))
	{
		std::cout << "cant open HPbarFrame" << std::endl;
	}
	if (!heart.loadFromFile("img/heart-icon.png"))
	{
		printf("\ncant open heart_icon\n");
	}
	HPframeTexture.setSmooth(true);
	HPbarFrameBoss.setTexture(&HPframeTexture);
	HPbarFrameBoss.setSize(sf::Vector2f(200.0f, 30.0f));
	HPbarFrameBoss.setOrigin(HPbarFrameBoss.getGlobalBounds().width/2.0, HPbarFrameBoss.getGlobalBounds().height / 2);
	HPbarFrameBoss.setPosition(900.0f, 45.0f);

	HPcolorTexture.setSmooth(true);
	HPbarColorBoss.rotate(180);
	HPbarColorBoss.setTexture(&HPcolorTexture);
	HPbarColorBoss.setSize(sf::Vector2f(200.0f, 30.0f));
	HPbarColorBoss.setOrigin(HPbarFrameBoss.getGlobalBounds().width / 2.0, HPbarFrameBoss.getGlobalBounds().height / 2);
	HPbarColorBoss.setPosition(900.0f, 45.0f);

	heart.setSmooth(true);
	heartBodyBoss.setTexture(&heart);
	heartBodyBoss.setSize(sf::Vector2f(50.0f, 50.0f));
	heartBodyBoss.setPosition(1010.0f, 20.0f);
	//std::cout << "x: %f" << heartBodyBoss.getPosition().x << std::endl;
}

void HP::update(float deltaTime,float &damage)
{
	//currentHP = 100;
	currentHP -= damage;
	//std::cout << "damage: " << damage << std::endl;
	HPpercent = currentHP /100;
	//std::cout << "percent: " << HPpercent << std::endl;

	HPbarColorBoss.setSize(sf::Vector2f((HPbarColorBoss.getSize().x) * HPpercent,HPbarColorBoss.getSize().y));

	if (HPbarColorBoss.getSize().x < 0) 
	{
		HPbarColorBoss.setSize(sf::Vector2f(0.0f, HPbarColorBoss.getSize().x));
	}
	std::cout << "position x: " << HPbarColorBoss.getSize().x << std::endl;
	damage = 0;
}

//void HP::playerHitBossDamage(float &bossDamage)
//{
//	damage = bossDamage;
//}

void HP::draw(sf::RenderWindow& window)
{
	window.draw(HPbarColor);
	window.draw(HPbarFrame);
	window.draw(heartBody);
	window.draw(HPbarColorBoss);
	window.draw(HPbarFrameBoss);
	window.draw(heartBodyBoss);
}
