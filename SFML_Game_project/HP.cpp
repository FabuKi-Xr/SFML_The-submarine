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

void HP::HPbossUpdate(float deltaTime,float &damage,bool &checkHP,int &gameState)
{
	if (checkHP == 1)
	{
		//currentHP = 100;
		currentHP -= damage;
		//std::cout << "damage: " << damage << std::endl;
		HPpercent = currentHP / 100;
		//std::cout << "percent: " << HPpercent << std::endl;
		scale.x = 200.0f;
		HPbarColorBoss.setSize(sf::Vector2f(scale.x * HPpercent, HPbarColorBoss.getSize().y));
		
		if (HPpercent <= 0)
		{
			HPpercent = 0;
			HPbarColorBoss.setSize(sf::Vector2f(0.0f, 0.0f));
		}
		if (HPbarColorBoss.getSize().x < 10)
		{
			HPbarColorBoss.setPosition(HPbarColorBoss.getPosition().x + 0.3 , 45.0f);
		}
		else if (HPbarColorBoss.getSize().x < 0)
		{
			HPbarColorBoss.setSize(sf::Vector2f(0.0f, HPbarColorBoss.getSize().x));
		}
		else 
		{
			HPbarColorBoss.setPosition(HPbarColorBoss.getPosition().x - 0.1 , 45.0f);
		}
		
		checkHP = 0;
	}
	damage = 0;
	//std::cout << "percent: " << HPpercent << std::endl;
	//std::cout << "size x : " << HPbarColorBoss.getSize().x << std::endl;
	
}

void HP::HPplayerUpdate(float deltaTime, float& damage, bool& checkPlayerHP, int& gameState)
{
	//checkPlayerHP เช็คว่า กระสุนยิงเเล้วหรือยัง
	if (checkPlayerHP == 1)
	{
		//currentHP = 100;
		currentPlayerHP -= damage;
		//std::cout << "damage: " << damage << std::endl;
		HPplayerPercent = currentPlayerHP / 100;

		
		//std::cout << "percent: " << HPplayerPercent << std::endl;
		scale.x = 200.0f;
		HPbarColor.setSize(sf::Vector2f(scale.x * HPplayerPercent, HPbarColor.getSize().y));
		HPbarColor.setOutlineColor(sf::Color::Transparent);
		HPbarColor.setOutlineThickness(2.0f);
		//std::cout << "size x : " << HPbarColor.getSize().x << std::endl;
		if (HPplayerPercent <= 0)
		{
			HPplayerPercent = 0;
			HPbarColor.setSize(sf::Vector2f(0.0f, 0.0f));
		}

		if (HPbarColor.getSize().x < 10)
		{
			HPbarColorBoss.setPosition(HPbarColorBoss.getPosition().x-0.75, 45.0f);
		}
		else if(HPbarColorBoss.getSize().x < 0)
		{
			HPbarColorBoss.setSize(sf::Vector2f(0.0f, HPbarColor.getSize().x));
		}
		else { HPbarColor.setPosition(HPbarColor.getPosition().x + 0.25, 30.0f); }
		
		checkPlayerHP = 0;
	}
	damage = 0;
}


void HP::draw(sf::RenderWindow& window)
{
	window.draw(HPbarColor);
	window.draw(HPbarFrame);
	window.draw(heartBody);
	window.draw(HPbarColorBoss);
	window.draw(HPbarFrameBoss);
	window.draw(heartBodyBoss);
}
