// char_controls.cpp - Nolan Vance

#include "player.h"

PlayerClass::PlayerClass()
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

	if(playerTexture.loadFromFile("Images/man.png"))
		playerSprite.setTexture(playerTexture,0);
	playerSprite.setScale(4.0,4.0);
	playerSprite.setOrigin(0.0,-100.0);
}
//---------------------------------------------------------------------------------------
void PlayerClass::LoadControls(sf::RenderWindow & w)
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
		sourceX += playerTexture.getSize().x / 4;
	else
		sourceX = 0;

	if(sourceX == playerTexture.getSize().x)
		sourceX = 0;

	//w.clear()
	playerSprite.setTextureRect(sf::IntRect(sourceX, sourceY,playerTexture.getSize().x / 4, playerTexture.getSize().y /4 ));
	playerSprite.setPosition(x,y);
	w.draw(playerSprite);
}
//---------------------------------------------------------------------------------------
sf::Sprite PlayerClass::ReturnPosition()
{
	return playerSprite;
}