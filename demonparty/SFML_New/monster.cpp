#include "utility.h"
#include "monster.h"

using namespace std;

//const int MonsterClass::LEVEL_CHART[10] = {0, 10, 35, 70, 110, 175, 250, 500, 750, 1000};

MonsterClass::MonsterClass(){
  name = breed = desc = "";
  level = xp = hp = 0;
  for(int i = 0; i < 6; i++)
	  attributes[i] = 0;
  parents.first = parents.second = "";
  isDead = false;
}

MonsterClass::MonsterClass(string n, string d, string b, MoodType m, int attOffset[6], MonsterClass p1, MonsterClass p2){
  name = n;
  desc = d;
  breed = b;
  mood = m;
  //line for dealing with attributes
  parents.first = p1.GetBreed();
  parents.second = p2.GetBreed();
  isDead = false;
}

void MonsterClass::InitAttributes(){
}

void MonsterClass::UpdateXP(int val){
	int i = 0;
	xp+=val;
//	while(xp >= LEVEL_CHART[i] && i != 10) i++;
	level = i;
}

void MonsterClass::UpdateHP(int val){
	hp += val;
	if(hp < 0)
		isDead = true;
}

string MonsterClass::MoodToStr(MoodType m){
    string tmp = "";
	switch(m){
	case HAPPY:
		tmp = "HAPPY";
		break;
	case ANGRY:
		tmp = "ANGRY";
		break;
	case SAD:
		tmp = "SAD";
		break;
	case APATHETIC:
		tmp = "APATHETIC";
		break;
	case CRAZY:
		tmp = "CRAZY";
		break;
	}
	return tmp;
}
