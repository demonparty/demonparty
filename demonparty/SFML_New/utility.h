/* utility.h - Nolan Vance
---------------------------------
+ color masking
+ screen sizing
+ mouse over sprite
*/

#ifndef demon_utility
#define demon_utility

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

struct AttackT {
	enum attack;
	sf::Sprite sp;
	sf::Texture tex;
	sf::Time time;
	float damage;
	int parent;
};

struct ItemT{
	string name;
};

class Utility{
	
public:
	Utility();
	//default constructor

	bool MouseOver(int MouseX,int MouseY,sf::Sprite Sprite);
	// Checks if the mouse is currently over the sprite.

	bool SpriteCollision(sf::Sprite s1, sf::Sprite s2, int buffer);
	//true when the first sprite is within the buffer zone of the second
	// (x - axis)

	void SetMask(int red, int blue, int green, std::string filename);
	//this functions takes a color of a pictures background 
	//and makes it transparent.
	
	float ReturnRatioX();
	//returns ratioX

	float ReturnRatioY();
	//returns ratioX

	int ReturnHeight();
	//returns height of the window

	int ReturnWidth();
	//returns width or the window

	sf::RenderWindow* ReturnWindow();
	//returns the window

	bool Utility::SetUpWindow(int resX, int resY);
	//checks for input to change screen size

	sf::View ReturnView();
	//Returns view

private:	
	
	float height;
	float width;
	float ratioX;
	float ratioY;
	float Original_h;
	float Original_w;
	sf::RenderWindow window;
	sf::View v1;
};

#endif