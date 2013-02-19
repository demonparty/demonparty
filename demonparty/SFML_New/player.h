//public:
#include <SFML/Graphics.hpp>
#include <iostream>

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