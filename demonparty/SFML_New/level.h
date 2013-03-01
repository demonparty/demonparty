#ifndef LEVEL_H
#define LEVEL_H

#include<SFML\Graphics.hpp>
#include "utility.h"
#include<SFML\System.hpp>
#include<vector>
#include"player.h"
#include "monster.h"
#include<sstream>

class Level{
public:
	Level(Utility *tools);
	bool PlayLevel(sf::RenderWindow *w);
	void SetBoundaries();
	sf::Time lvlTimer;
	void PlayerPickups();
	sf::Time SetTime();
	void LoadLevel();
	void PlayerControls();
	void PlayerAttacks();
	void CheckAttackTimers();
	void PlayerAttackCheck();
	void EnemyAttackCheck();	


private:

	sf::Sprite pizza, bubble, bgs;
	sf::Texture pizza_texture, bubble_texture,bg_texture ;
	bool pickedUp;
	sf::Text text;
	sf::Font f;
	sf::Color c;
	Utility *tools;

	float top, bottom, right, left;
	vector<MonsterClass> enemies;
	vector<PlayerClass> players;
	vector<AttackT> activeAttacks;
	vector<AttackT> enemyAttacks;
	vector<ItemT> items;

};

#endif