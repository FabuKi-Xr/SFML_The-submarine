#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::RectangleShape shape, sf::Texture BUTTON,short unsigned state,short unsigned type) 
{

	this->buttonState = Default;
	this->type = type;
	this->shape.setTexture(&BUTTON); //เอารูปภาพinputใส่ลงไปในshape
	this->shape.setPosition(x,y); //Button scale //draw shape
	this->shape.setSize(sf::Vector2f(width, height));//ค่อย input มาทีหลังจาก object_scale
	
	
}
void Button::update(const sf::Vector2i mousePosWindow)
{
	//ปรากฎมาปกติ
	this->buttonState = Default;

	//hover
	if (sf::Mouse::getPosition().x > 800 && sf::Mouse::getPosition().y < 700)
	{
		this->buttonState = onclick;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{

			this->buttonState = clicked;

		}

	}

	switch (this->buttonState)
	{
	case Default:
		this->shape.setTexture(&BUTTON);
		break;
	case onclick:
		this->shape.setTexture(&BUTTON);
		break;
	case clicked:
		this->shape.setTexture(&BUTTON);
		break;
	}

}
void Button::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}