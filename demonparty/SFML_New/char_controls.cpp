// char_controls.cpp - Nolan Vance

#include "char_controls.h"

Char_controls::Char_controls()
{
	velx = 0; 
	vely = 0;
	x = 10;
	y = 10; 
	speed =  1.5;
	sourceX = 0; 
	sourceY = 0;

	down = 0;
	left = 48;
	right = 96;
	up = 144;

	if(man.loadFromFile("Images/man.png"))
		manSprite.setTexture(man,0);
	manSprite.setScale(4.0,4.0);
	manSprite.setOrigin(0.0,-100.0);
}
//---------------------------------------------------------------------------------------
void Char_controls::LoadControls(sf::RenderWindow & w)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Joystick::isButtonPressed(0,0))
	{
		velx = speed;
		sourceY = right;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		sourceY = left;
		velx = -speed;
	}
	else
		velx = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		sourceY = up;
		vely = -speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		sourceY = down;
		vely = speed;
	}
	else
		vely=0;

	x += velx;
	y += vely;

	if(velx != 0 || vely != 0)
		sourceX += man.getSize().x / 4;
	else
		sourceX = 0;

	if(sourceX == man.getSize().x)
		sourceX = 0;

	//w.clear()
	manSprite.setTextureRect(sf::IntRect(sourceX, sourceY,man.getSize().x / 4, man.getSize().y /4 ));
	manSprite.setPosition(x,y);
	w.draw(manSprite);
}
//---------------------------------------------------------------------------------------
sf::Sprite Char_controls::ReturnPosition()
{
	return manSprite;
}