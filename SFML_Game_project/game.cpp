#include"game.h"

//Static function

//initializer function
void game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1080, 720), "The marine", sf::Style::Default);
}

game::game()
{
	this->initWindow();
}

game::~game()
{
	delete this->window;
}
void game::updateSFMLevents()
{
		while (this->window->pollEvent(this->event))
		{
			
			if (this->event.type == sf::Event::Closed)
			{
				this->window->close();
			}
		}
}
//functions
void game::update()
{
	this->updateSFMLevents();
}

void game::render()
{
	this->window->clear();

	//render items
	this->window->display();
}

void game::run()
{
	while (this->window->isOpen()) //animation use adobe??
	{
		this->update();
	}
}


