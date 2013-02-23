

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

class PlayerClass{

	public:
		PlayerClass(Utility *tools);
		//constructor to set default values
	
		void LoadControls(sf::RenderWindow & w);
		void StopMovement(bool stop);

		sf::Sprite ReturnSprite();
		//stat functions
		int ReturnHp();
		void TakeDamage(int damage);
	private:
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