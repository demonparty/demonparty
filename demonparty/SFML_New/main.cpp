//ERIC SUCKS


#include "utility.h"
#include "player.h"
#include "monster.h"
#include <sstream>
#include "level.h"

//Nah Nolan sucks
bool Menu(sf::RenderWindow &w, float ratioX, float ratioY);

//made these global while testing
Utility tools;			
sf::View mainView;
Level level(&tools);

int main()
{ 
	//JOYSTICK SETUP
	sf::Joystick::update();
	if(sf::Joystick::isConnected(0))
		std::cout<<"Controller 1: Connected"<<std::endl;
	//RENDER WINDOW
	sf::RenderWindow *window = tools.ReturnWindow();

	//Image manipulation, making transparent
	tools.SetMask(43,133,133,"Images/man.png");
	tools.SetMask(255,255,255,"Images/bottom.png");
	tools.SetMask(255,255,255,"Images/pizza.png");
	tools.SetMask(255,128,255,"Images/bubble.png");
	tools.SetMask(255,255,255,"Images/fireball.png");
	//Setting up the view from tools
	mainView = tools.ReturnView();
	window->setFramerateLimit(30);
	window->setVerticalSyncEnabled(true);
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

			level.PlayLevel(window);
		}
		
		window->display();
    }
	
    return 0;
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
	play_button.setPosition((mainView.getCenter().x-(play_button.getTextureRect().width/2)),mainView.getCenter().y +(mainView.getCenter().y*.05));
	quit_button.setPosition((mainView.getCenter().x-(play_button.getTextureRect().width/2)),mainView.getCenter().y +(mainView.getCenter().y*.50));

	//clear the window before drawing
	w.clear();
	
	//draw the sprites to the render window
	w.draw(menu);
	w.draw(play_button);
	w.draw(quit_button);
	
	//checking if the play and quit sprites are being(left) clicked. (see utility.h)
	if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && tools.MouseOver(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y,quit_button))
		w.close();
	if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && tools.MouseOver(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y,play_button))
		return false;

	return true;
}