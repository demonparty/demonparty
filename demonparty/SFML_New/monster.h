//Monster Class Header

#ifndef MW_MONHEADER
#define MW_MONHEADER

#include "utility.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

enum MoodType {HAPPY, SAD, ANGRY, APATHETIC, CRAZY};

enum AType {A,B,C,D,E,F,G};

class MonsterClass{
public:
	sf::Sprite sprite;
	MonsterClass();
	MonsterClass(string name, string desc, string breed, MoodType m,
		         int attOffset[6], MonsterClass p1, MonsterClass p2);

	void UpdateHP(int val);
	void UpdateXP(int val);

	void SetBreed(string b) {breed = b;};
	void SetName(string n) {name = n;};
	void SetDesc(string d) {desc = d;};
	void SetMood(MoodType m) {mood = m;};
	void InitAttributes();

	bool IsDead() {return isDead;};

	string GetBreed() {return breed;};
	string GetName() {return name;};
	string GetDesc() {return desc;};
	int GetHP() {return hp;};
	int GetLevel() {return level;};
	int GetXP() {return xp;};

	string MoodToStr(MoodType m);

private:
	int hp;
	int xp;
	int level;
	int attributes[6];
	bool isDead;
	string name;
	string desc;
	string breed;
	MoodType mood;
	vector<string>skills;
	pair<string, string> parents;
//	static const int LEVEL_CHART[10];
};




#endif
