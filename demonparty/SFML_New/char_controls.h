
/* char_controls.h - Nolan Vance
---------------------------------
+ keyboard input
+ movement

*/

#include <SFML/Graphics.hpp>


class Char_controls{
public:
	Char_controls();
	//constructor to set default values

	void LoadControls(sf::RenderWindow & w);
	sf::Sprite ReturnPosition();

private:
	float velx, vely;
	float x , y, speed;
	int sourceX , sourceY;

	int down;
	int left;			//picture splits
	int right;
	int up;

	sf::Sprite manSprite;
	sf::Texture man;
};