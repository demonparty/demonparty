#include "level.h"

Level::Level(Utility *t)
{
	PlayerClass* player;
	player = new PlayerClass(t);
	players.push_back(*player);

	tools = t;
	pickedUp = false;
	
	//speech bubble
	bubble_texture.loadFromFile("Images/bubble.png");
	bubble.setTexture(bubble_texture);
	bubble.scale(tools->ReturnRatioX(),tools->ReturnRatioY());
	
	bg_texture.loadFromFile("Images/fink_bg.jpg");
	bgs.setTexture(bg_texture);				
	bgs.setScale(tools->ReturnRatioX(),tools->ReturnRatioY());

	//pizza
	ItemT *pizza;
	pizza = new ItemT;
	pizza->name = "pizza";
	pizza->description = "This is pizza, it will \n heal you, YUM!";
	pizza->texture.loadFromFile("Images/pizza.png");
	items.push_back(*pizza);
	items[0].sprite.setTexture(items[0].texture);
	items[0].sprite.setPosition(tools->ReturnWidth()*.5,tools->ReturnHeight()*.7);
	items[0].sprite.scale(tools->ReturnRatioX(),tools->ReturnRatioY());
	items[0].sprite.setPosition(tools->ReturnWidth()*.5,tools->ReturnHeight()*.7);
	
	//text
	f.loadFromFile("Fonts/AgentOrange.ttf");
	c = sf::Color(0,0,0);
	text = sf::Text(items[0].description,f, int(15* tools->ReturnRatioX())+.5);
	text.setColor(c);
}
//------------------------------------------------------------------------
bool Level::PlayLevel(sf::RenderWindow *w, sf::Clock* clock)
{

	std::stringstream ss;
	//ss<<players[0].ReturnHealth();
	ss<<int(clock->getElapsedTime().asSeconds());
	sf::Text health(ss.str(),f,50);
	ss.clear();
	SetBoundaries();
	
	health.setPosition((tools->ReturnWidth()/2) - (health.getGlobalBounds().width/2),0);
	
	w->clear();

	w->draw(bgs);
	//cout<<"Number of attacks: "<<Pattacks.size()<<endl;
	DrawItems(w);
	DrawAttacks(w);
	CheckItemCollision();
	MouseOverItem(w);
	if(attackTimer.getElapsedTime().asMilliseconds() > 100)
	{
		PlayerAttackCheck();
		attackTimer.restart();
	}

	//scales player to proper resolution
	players[0].ReturnSprite().scale(tools->ReturnRatioX(),tools->ReturnRatioY());
	
	w->draw(health);
	
	LoadPlayerControls();

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
void Level::DrawItems(sf::RenderWindow *w)
{
	for(int i=0;i<items.size();i++)
	{
		w->draw(items[i].sprite);
	}
}
void Level::MouseOverItem(sf::RenderWindow *w)
{
	for(int i=0;i<items.size();i++)
	{
		if(tools->MouseOver(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y,items[i].sprite))
		{
			text.setPosition(items[i].sprite.getPosition().x,items[i].sprite.getPosition().y- tools->ReturnHeight()*.15);
			bubble.setPosition(items[i].sprite.getPosition().x - tools->ReturnWidth()*.02,items[i].sprite.getPosition().y - tools->ReturnHeight()*.25);
			w->draw(bubble);
			w->draw(text);
		}
	}
}
void Level::PlayerOnItem(PlayerClass& player, ItemT item)
{
	if(item.name == "pizza")
	{
		player.TakeDamage(-10);
		std::vector<ItemT>::iterator i = items.begin();
		while(i != items.end())
		{
			if(i->name == item.name)
			{
				items.erase(i);
				i = items.end();
			}
			else
				i++;
		}
	}
}
void Level::CheckItemCollision()
{
	for(int i=0;i<players.size();i++)
	{
		for(int j=0;j<items.size();j++)
		{
			if(tools->SpriteCollision(players[i].ReturnSprite(),items[j].sprite,0))
				PlayerOnItem(players[i],items[j]);
		}
	}
}
void Level::LoadPlayerControls()
{
	for(int i=0;i<players.size();i++)
		players[i].LoadControls(*tools->ReturnWindow());
}
void Level::PlayerAttackCheck()
{
	for(int i=0;i<players.size();i++)
	{
		if(players[i].HasAttacked())
		{
			AttackT* tmp;

			tmp = players[i].Attack();
			tmp->sp.setPosition(players[i].ReturnSprite().getPosition());
			Pattacks.push_back(*tmp);
			
		}
	}

}
void Level::DrawAttacks(sf::RenderWindow *w)
{
	for(int i=0;i<Pattacks.size();i++)
	{
		w->draw(Pattacks[i].sp);

		if(Pattacks[i].name == "fireball")
			Pattacks[i].sp.move(30,0);

		if(Pattacks[i].sp.getPosition().x > tools->ReturnWidth() || Pattacks[i].sp.getPosition().y < 0)
		{
			std::vector<AttackT>::iterator iter = Pattacks.begin();
			while(iter != Pattacks.end())
			{
				if(iter->name == Pattacks[i].name)
				{
					Pattacks.erase(iter);
					iter = Pattacks.end();
				}
				else
					iter++;
			}
		}
	}
}