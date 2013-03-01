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
	bool PlayLevel(sf::RenderWindow *w,sf::Clock * clock);
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
	void CheckItemCollision();
	void DrawItems(sf::RenderWindow *w);
	void MouseOverItem(sf::RenderWindow *w);
	void PlayerOnItem(PlayerClass& player, ItemT item);
	//called when the player collides with the item
	void LoadPlayerControls();
	void DrawAttacks(sf::RenderWindow *w);

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
	vector<AttackT> Pattacks;
	vector<AttackT> Eattacks;
	vector<ItemT> items;
	AttackT copys[10];

	sf::Clock attackTimer;
};

#endif