#pragma once
#include<sfml\Graphics.hpp>
class HP
{
private:
	sf::Texture bar_frame;
	
public:
	HP(sf::Texture *pic,float width,float height,float x,float y );
	void HP_getLow(float damage);
	void update();
	void render();
};

