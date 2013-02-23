// char_controls.cpp - Nolan Vance

#include "utility.h"
#include "player.h"

PlayerClass::PlayerClass(Utility *t)
{
	tools = t;
	stop = false;
	//moving information
	velx = 0; 
	vely = 0;
	x = 10;
	y = 10; 
	speed = 30;
	sourceX = 0; 
	sourceY = 0;
	//image information
	down = 0;
	left = 48;
	right = 96;
	up = 144;
	//stats
	hp = 100;

	if(playerTexture.loadFromFile("Images/man.png"))
		playerSprite.setTexture(playerTexture,0);
	else
		std::cout<<"bad"<<endl;
	playerSprite.setScale(4.0,4.0);
	playerSprite.setOrigin(-300,-200);
}
//---------------------------------------------------------------------------------------
void PlayerClass::LoadControls(sf::RenderWindow & w)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		velx = speed;
		sourceY = right;
		if(stop)
		{
			velx = -speed;
			stop = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		sourceY = left;
		velx = -speed;
		if(stop)
		{
			velx = speed;
			stop = false;
		}
	}
	else
		velx = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		sourceY = up;
		vely = -speed;
		if(stop)
		{
			vely = speed;
			stop = false;
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		sourceY = down;
		vely = speed;
		if(stop)
		{
			vely = -speed;
			stop = false;
		}
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
sf::Sprite PlayerClass::ReturnSprite()
{
	return playerSprite;
}
//---------------------------------------------------------------------------------------
int PlayerClass::ReturnHp()
{
	return hp;
}
//---------------------------------------------------------------------------------------
void PlayerClass::TakeDamage(int x)
{
	hp = hp - x;
}
void PlayerClass::StopMovement(bool s)
{
	stop = s;
}