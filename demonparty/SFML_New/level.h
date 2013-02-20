#ifndef LEVEL_H
#define LEVEL_H

#include<SFML\Graphics.hpp>
#include "utility.h"
#include<SFML\System.hpp>
#include<vector>
#include"player.h"
#include<sstream>

class Level{
public:
	Level(Utility *tools);
	bool PlayLevel(sf::RenderWindow *w);
private:
	std::vector<PlayerClass> players;
	sf::Sprite pizza, bubble, bgs;
	sf::Texture pizza_texture, bubble_texture,bg_texture ;
	bool pickedUp;
	sf::Text text;
	sf::Font f;
	sf::Color c;
	Utility *tools;
};

#endif