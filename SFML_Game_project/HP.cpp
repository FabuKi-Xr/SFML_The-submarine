#include "HP.h"

HP::HP()
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

void HP::update(float deltaTime,float damage)
{

}

void HP::draw(sf::RenderWindow& window)
{
	window.draw(HPbarColor);
	window.draw(HPbarFrame);
	window.draw(heartBody);
}
