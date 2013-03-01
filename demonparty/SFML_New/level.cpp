#include "level.h"

Level::Level(Utility *t)
{
	PlayerClass* player;
	player = new PlayerClass(t);
	players.push_back(*player);

	tools = t;
	pickedUp = false;
	//pizza
	pizza_texture.loadFromFile("Images/pizza.png");
	pizza.setTexture(pizza_texture);
	pizza.setPosition(tools->ReturnWidth()*.5,tools->ReturnHeight()*.7);
	pizza.scale(tools->ReturnRatioX(),tools->ReturnRatioY());
	
	//speech bubble
	bubble_texture.loadFromFile("Images/bubble.png");
	bubble.setTexture(bubble_texture);
	bubble.scale(tools->ReturnRatioX(),tools->ReturnRatioY());
	//text
	f.loadFromFile("Fonts/AgentOrange.ttf");
	c = sf::Color(0,0,0);
	text = sf::Text("This is pizza, it will \n heal you, YUM!",f, int(15* tools->ReturnRatioX())+.5);
	text.setColor(c);
	bg_texture.loadFromFile("Images/fink_bg.jpg");
	bgs.setTexture(bg_texture);				
	bgs.setScale(tools->ReturnRatioX(),tools->ReturnRatioY());
}
//------------------------------------------------------------------------
bool Level::PlayLevel(sf::RenderWindow *w)
{
	std::stringstream ss;
	ss<<players[0].ReturnHp();
	
	sf::Text health(ss.str(),f,50);
	ss.clear();
	SetBoundaries();

	health.setPosition((tools->ReturnWidth()/2) - (health.getGlobalBounds().width/2),0);
		
	w->clear();

	w->draw(bgs);
	
	//scales player to proper resolution
	players[0].ReturnSprite().scale(tools->ReturnRatioX(),tools->ReturnRatioY());

	if(tools->MouseOver(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y,pizza))
	{
		text.setPosition(pizza.getPosition().x,pizza.getPosition().y- tools->ReturnHeight()*.15);
		bubble.setPosition(pizza.getPosition().x - tools->ReturnWidth()*.02,pizza.getPosition().y - tools->ReturnHeight()*.25);
		w->draw(bubble);
		w->draw(text);
	}
	if(!pickedUp)
		w->draw(pizza);

	if(tools->SpriteCollision(pizza,players[0].ReturnSprite(),0))
		pickedUp = true;

	if(pickedUp)
	{
		pickedUp = false;
		players[0].TakeDamage(-10);
	}
	
	w->draw(health);
	
	players[0].LoadControls(*w);
	return false;
}
void Level::SetBoundaries()
{
	float side_right = 0;
	float side_left = 0;
	float top = 0;
	float bottom = 0;

	side_right = tools->ReturnWidth() - players[0].ReturnSprite().getGlobalBounds().width;
	top = tools->ReturnHeight() *.45;
	bottom = tools->ReturnHeight() - players[0].ReturnSprite().getGlobalBounds().height;

	if(players[0].getX() <= side_left)
		players[0].setX(side_left);
	if(players[0].getX() >= side_right)
		players[0].setX(side_right);
	if(players[0].getY() <= top)
		players[0].setY(top);
	if(players[0].getY() >= bottom)
		players[0].setY(bottom);
	

}