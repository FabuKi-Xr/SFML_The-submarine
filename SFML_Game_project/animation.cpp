#include "animation.h"

animation::animation(sf::Texture* texture, sf::Vector2u imageCount, float switchtime)
{
	this->imageCount = imageCount;
	this->switchtime = switchtime;
	totaltime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);

};

animation::~animation()
{
	//delete?

};

void animation::update(int row,float deltatime)
{
	currentImage.y = row;
	totaltime += deltatime;

	if (totaltime >= switchtime)
	{
		totaltime -= switchtime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}
	uvRect.top = currentImage.y * uvRect.height;
	
}

void animation::updatebullet(int row, float deltatime)
{
	currentImage.y = row;
	totaltime += deltatime;

	if (totaltime >= switchtime)
	{
		totaltime -= switchtime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}
	uvRect.top = currentImage.y * uvRect.height;
}
void animation::render()
{

};
