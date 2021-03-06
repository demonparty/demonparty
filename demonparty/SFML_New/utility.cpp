// utility.cpp - Nolan Vance

#include "utility.h"

void CheckResolution(float &resX, float &resY);

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

	CheckResolution(width,height);

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
	return window.getSize().y;
}
//---------------------------------------------------------------------------------------
int Utility::ReturnWidth()
{
	return window.getSize().x;
}
//---------------------------------------------------------------------------------------
sf::RenderWindow* Utility::ReturnWindow()
{
	return &window;
}
//---------------------------------------------------------------------------------------
bool Utility::SetUpWindow(float resX, float resY)
{
	CheckResolution(resX,resY);

	ratioX = resX/1920.0;
	ratioY = resY/1080.0;

	//creates a mew renderwindow with the inputed sizes
	window.create(sf::VideoMode(resX,resY),"Demon Party",sf::Style::Fullscreen);

	int newH = (width*resY)/resX;
	displace = (newH - height)/(-2);

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
void Utility::CopyAttackT(AttackT att_1, AttackT &att_2)
{
	att_2.damage = att_1.damage;
	att_2.name = att_1.name;
	att_2.parent = att_1.parent;
	att_2.sp = att_1.sp;
	att_2.tex = att_1.tex;
	att_2.time = att_1.time;
}
float Utility::ReturnOriginalHeight()
{
	return Original_h;
}
float Utility::ReturnOriginalWidth()
{
	return Original_w;
}

void CheckResolution(float &resX, float &resY)
{
	if(resY == 1200 && resX == 1920){
		resY = 1080;}
	if(resY == 600 && resX == 800){
		resY = 540;resX = 960;}
}