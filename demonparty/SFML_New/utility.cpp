// utility.cpp - Nolan Vance

#include "utility.h"


Utility::Utility()
{
	ratioX = 0;
	ratioY = 0;

	//sets height and width to the detected resolution.
	Original_h = sf::VideoMode::getDesktopMode().height;
	Original_w = sf::VideoMode::getDesktopMode().width;

	//just saving the original height and width, will overwrite eventually
	height = Original_h;
	width = Original_w;

	//getting the ratio of height amd width of the screen to the original size of 1920x1200
	// the background images are set to this.
	ratioX = width/1920.0;
	ratioY = height/1080.0;
	
	SetUpWindow(width,height);
}
//---------------------------------------------------------------------------------------
bool Utility::MouseOver(int MouseX,int MouseY,sf::Sprite Sprite)
{
	sf::Vector2f coords_m, coords_s;
	coords_s = window.convertCoords(sf::Vector2i(Sprite.getPosition()), v1);
	coords_m = window.convertCoords(sf::Vector2i(MouseX,MouseY),v1);

	//checks is the mouse is inside a sprites rectangle
	return	(coords_m.x < Sprite.getPosition().x  + Sprite.getTextureRect().width ) && (Sprite.getPosition().x  < coords_m.x ) && 
		(coords_m.y < Sprite.getPosition().y  + Sprite.getTextureRect().height ) && (Sprite.getPosition().y  < coords_m.y );
	
}
//---------------------------------------------------------------------------------------
bool Utility::SpriteCollision(sf::Sprite s1, sf::Sprite s2, int buffer)
{
	if(s1.getGlobalBounds().intersects(s2.getGlobalBounds()))
		return true;

	return false;
}
//---------------------------------------------------------------------------------------
void Utility::SetMask(int red, int blue, int green, std::string filename)
{
	//set mask is showing sfml what color to ignore from an image
	sf::Image i;
	i.loadFromFile(filename);

	i.createMaskFromColor(sf::Color(red,blue,green));

	i.saveToFile(filename);
}
//---------------------------------------------------------------------------------------
float Utility::ReturnRatioX()
{
	return ratioX;
}
//---------------------------------------------------------------------------------------
float Utility::ReturnRatioY()
{
	return ratioY;
}
//---------------------------------------------------------------------------------------
int Utility::ReturnHeight()
{
	return height;
}
//---------------------------------------------------------------------------------------
int Utility::ReturnWidth()
{
	return width;
}
//---------------------------------------------------------------------------------------
sf::RenderWindow* Utility::ReturnWindow()
{
	return &window;
}
//---------------------------------------------------------------------------------------
bool Utility::SetUpWindow(int resX, int resY)
{
	//creates a mew renderwindow with the inputed sizes

	window.create(sf::VideoMode(resX,resY),"asdasda",sf::Style::Fullscreen);
	

	int newH = (width*resY)/resX;
	int displace = (newH - height)/(-2);

	v1 = sf::View(sf::FloatRect(0,displace,width,newH));

	v1.setCenter(width/2,height/2);

	window.setView(v1);
	
	height = resY;
	width = resX;

	return true;
}

//----------------------------------------------------------------------------------------
sf::View Utility::ReturnView()
{
	return v1;
}