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
	facing=0;
	slowAnim = 0;
	//image information
	down = 0;
	left = 48;
	right = 96;
	up = 144;
	//stats
	health = 100;

	if(playerTexture.loadFromFile("Images/wizardwalk_3.png"))
		playerSprite.setTexture(playerTexture,0);
	else
		std::cout<<"bad"<<endl;
	//playerSprite.setScale(4.0,4.0);

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
		//sourceY = right;
		facing = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//sourceY = left;
		velx = -speed;
		facing = 250;
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


	if(velx != 0 || vely != 0){
		slowAnim++;
		if(slowAnim > 3){
			sourceX += playerTexture.getSize().x / 11;
			slowAnim = 0;
		}
	}else{
		if(facing == 0){
			sourceX = 0;
		}else{
			sourceX = playerTexture.getSize().x - 250;
		}
	}

	if(sourceX == playerTexture.getSize().x)
		sourceX = 0;

	playerSprite.setTextureRect(sf::IntRect(sourceX, facing,playerTexture.getSize().x / 11,  250));
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