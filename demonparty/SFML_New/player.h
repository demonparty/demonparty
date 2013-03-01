

#ifndef demon_player
#define demon_player

#include "utility.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

class PlayerClass {
  public:
	void Controls();
	AttackT Attacks();
	vector<AttackT>PossibleAttacks();
	int GetLuck(){return luck;}
	int GetAgility(){return agility;}
	int GetTech(){return tech;}
	int GetDamage(){return damage;}
	void SetLuck(int tmp){luck = tmp;}
	void SetAgility(int tmp){agility = tmp;}
	void SetTech(int tmp){tech = tmp;}
	void SetDamage(int tmp){tech = tmp;}

	PlayerClass(Utility *tools);
		//constructor to set default values
	
	void LoadControls(sf::RenderWindow & w);
	void StopMovement(bool stop);

	sf::Sprite ReturnSprite();
	//stat functions
	int ReturnHp();
	void TakeDamage(int damage);
	int getY(){return y;};
	int getX(){return x;};
	int getVelY(){return vely;};
	int getVelX(){return velx;};
	void setY(int newY){y = newY;};
	void setX(int newX){x = newX;};


private:
	float health;
	int luck;
	int agility;
	int tech;
	int damage;
	sf::Sprite sp;
	sf::Texture tex;
	string name;
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
	float velx, vely;
	float x , y, speed;
	int sourceX , sourceY;
	bool stop;
	Utility * tools;
	int down;
	int left;			//picture splits
	int right;
	int up;
	int hp;
};

#endif