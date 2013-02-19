//ERIC SUCKS

#include <SFML/Graphics.hpp>
#include "player.h"
#include <iostream>
#include "utility.h"

//Nah Nolan sucks


using namespace std;

void Start(sf::Sprite &s, sf::Texture &t);
bool Menu(sf::RenderWindow &w, float ratioX, float ratioY);

//made these global while testing
PlayerClass player;
Utility tools;			
sf::View mainView;


int main()
{ 
	//JOYSTICK SETUP
	sf::Joystick::update();
	if(sf::Joystick::isConnected(0))
		std::cout<<"Controller 1: Connected"<<std::endl;

	//RENDER WINDOW
	sf::RenderWindow *window = tools.ReturnWindow();

	//Setting up sprites and thier textures
	// bgs - background sprite			bg - background texture
	// bottom - bottom sprite          bottom texture - bottom picture
	sf::Sprite bgs,bottom,pizza,bubble;
	sf::Texture bg,bottom_texture,pizza_texture,bubble_texture;

	
	sf::Font f;
	sf::Color c(0,0,0);

	f.loadFromFile("Fonts/AgentOrange.ttf");

	sf::Text text("This is pizza, it will \n heal you, YUM!",f, int(15* tools.ReturnRatioX())+.5);

	text.setColor(c);

	//pizza
	pizza_texture.loadFromFile("Images/pizza.png");
	pizza.setTexture(pizza_texture);
	pizza.setPosition(tools.ReturnWidth()/2,tools.ReturnHeight()/2 );
	pizza.scale(tools.ReturnRatioX(),tools.ReturnRatioY());
	
	//speech bubble
	bubble_texture.loadFromFile("Images/bubble.png");
	bubble.setTexture(bubble_texture);
	bubble.scale(tools.ReturnRatioX(),tools.ReturnRatioY());

	//Start function sets up background image and texture
	Start(bgs,bg);
	bgs.setScale(tools.ReturnRatioX(),tools.ReturnRatioY());

	//loading bottom texture to sprite
	bottom_texture.loadFromFile("Images/bottom.png");
	bottom.setTexture(bottom_texture);
	bottom.scale(10,10);

	//Image manipulation, making transparent
	tools.SetMask(43,133,133,"Images/man.png");
	tools.SetMask(255,255,255,"Images/bottom.png");
	tools.SetMask(255,255,255,"Images/pizza.png");
	tools.SetMask(255,128,255,"Images/bubble.png");

	//Setting up the view from tools
	mainView = tools.ReturnView();

	//Start menu loop control
	bool start = true;

	//MAIN LOOP
    while (window->isOpen())
    {	
        sf::Event event;

        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window->close();						// if escape, close window
			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11)
				tools.SetUpWindow(800.0,600.0);			// if F11 change res
			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F10)
				tools.SetUpWindow(1024.0,768.0);		// if F10 change res
			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F9)
				tools.SetUpWindow(1366.0,768.0);		// if F9 change res
			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F8)
				tools.SetUpWindow(1280.0,1024.0);		// if F8 change res
        }
		//Checks if the start menu is still up
		if(start)
			start = Menu(*window,tools.ReturnRatioX(),tools.ReturnRatioY());
		if(!start)
		{
			window->clear();
			window->draw(bgs);
			window->draw(pizza);
			//loads the player player,images, ect. (see char_player.h )
			player.LoadControls(*window);
			//scales player to proper resolution
			player.ReturnPosition().scale(tools.ReturnRatioX(),tools.ReturnRatioY());

			if(tools.MouseOver(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y,pizza,tools.ReturnRatioX(),tools.ReturnRatioY()))
			{
				text.setPosition(pizza.getPosition().x,pizza.getPosition().y- tools.ReturnHeight()*.15);
				bubble.setPosition(pizza.getPosition().x - tools.ReturnWidth()*.02,pizza.getPosition().y - tools.ReturnHeight()*.25);
				window->draw(bubble);
				window->draw(text);
			}
		}
		window->display();
    }
	
    return 0;
}

void Start(sf::Sprite &s, sf::Texture &t)
{	
	if(t.loadFromFile("Images/background.png"))			//loads background image from file
		std::cout<<"Background loaded"<<std::endl;		//outputs into console
	s.setTexture(t);									//sets texture to sprite
}


bool Menu(sf::RenderWindow &w, float ratioX, float ratioY)
{

	sf::Sprite menu,				//menu background sprite
		play_button,				//play button sprite
		quit_button;				//quit button sprite

	sf::Texture menu_pic,			//the textures to the 
		play_button_pic,			// corresponding sprite
		quit_button_pic;

	//loads the images  to the textures
	menu_pic.loadFromFile("Images/menu_bg.png");
	play_button_pic.loadFromFile("images/play_button.png");
	quit_button_pic.loadFromFile("images/quit_button.png");

	//attaches the textures to the sprites
	menu.setTexture(menu_pic);
	play_button.setTexture(play_button_pic);
	quit_button.setTexture(quit_button_pic);
	
	//scales sprites according to the resolution
	menu.scale(ratioX,ratioY);
	play_button.scale(ratioX,ratioY);
	quit_button.scale(ratioX,ratioY);
	
	//setting position of the play and quit buttons
	play_button.setPosition((mainView.getCenter().x-(play_button.getTextureRect().width/2)),mainView.getCenter().y +(mainView.getCenter().y*.35));
	quit_button.setPosition((mainView.getCenter().x-(play_button.getTextureRect().width/2)),mainView.getCenter().y +(mainView.getCenter().y*.50));

	//clear the window before drawing
	w.clear();
	
	//draw the sprites to the render window
	w.draw(menu);
	w.draw(play_button);
	w.draw(quit_button);
	
	//checking if the play and quit sprites are being(left) clicked. (see utility.h)
	if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && tools.MouseOver(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y,quit_button,tools.ReturnRatioX(),tools.ReturnRatioY()))
		w.close();
	if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && tools.MouseOver(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y,play_button,tools.ReturnRatioX(),tools.ReturnRatioY()))
		return false;

	return true;
}