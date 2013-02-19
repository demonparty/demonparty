

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
		PlayerClass();
		//constructor to set default values
	
		void LoadControls(sf::RenderWindow & w);
		sf::Sprite ReturnPosition();

	private:
		sf::Sprite playerSprite;
		sf::Texture playerTexture;
		float velx, vely;
		float x , y, speed;
		int sourceX , sourceY;

		int down;
		int left;			//picture splits
		int right;
		int up;
};

#endif