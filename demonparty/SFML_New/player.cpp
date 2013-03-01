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
	x = 0;
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
	health = 100;

	if(playerTexture.loadFromFile("Images/man.png"))
		playerSprite.setTexture(playerTexture,0);
	else
		std::cout<<"bad"<<endl;
	playerSprite.setScale(4.0,4.0);

	AttackT *fireball;
	fireball = new AttackT;
	fireball->tex.loadFromFile("Images/fireball.png");
	fireball->sp.setTexture(fireball->tex);
	fireball->damage = -10;
	fireball->parent = 0;
	fireball->name = "fireball";
	Pattacks.push_back(*fireball);
}
//---------------------------------------------------------------------------------------
void PlayerClass::LoadControls(sf::RenderWindow & w)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
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
		//sourceY = up;
		vely = -speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		//sourceY = down;
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
float PlayerClass::ReturnHealth()
{
	return health;
}
//---------------------------------------------------------------------------------------
void PlayerClass::TakeDamage(float x)
{
	health = health - x;
}
void PlayerClass::StopMovement(bool s)
{
	stop = s;
}
AttackT* PlayerClass::Attack()
{
	return &Pattacks[0];
}
bool PlayerClass::HasAttacked()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
		return true;
	else
		return false;
}