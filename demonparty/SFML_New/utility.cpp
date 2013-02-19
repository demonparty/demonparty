// utility.cpp - Nolan Vance

#include "utility.h"
#include<iostream>

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
bool Utility::MouseOver(int MouseX,int MouseY,sf::Sprite Sprite, float rX, float rY)
{
	//checks is the mouse is inside a sprites rectangle
	return	(MouseX < Sprite.getPosition().x *(width/Original_w) + Sprite.getTextureRect().width *rX ) && (Sprite.getPosition().x *(width/Original_w) < MouseX ) && 
		(MouseY < Sprite.getPosition().y *(height/Original_h) + Sprite.getTextureRect().height *rY ) && (Sprite.getPosition().y * (height/Original_h) < MouseY );
	
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
	
	//this finds values to set the window up to change sizes but not shape
	int newH = (width*resY)/resX;
	int displace = (newH - height)/(-2);

	//sets a view to the window, like a 2d camera
	v1 = sf::View(sf::FloatRect(0,displace,width,newH));

	//sets a center of the view
	v1.setCenter(width/2,height/2);

	//assigns the view to the window
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