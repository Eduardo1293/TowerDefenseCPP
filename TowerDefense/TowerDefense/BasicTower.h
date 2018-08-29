#pragma once
#ifndef _BASICTOWER_H_
#define _BASICTOWER_H_

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include "DummyEnemy.h"

using namespace std;

class BasicTower {

private:
	sf::Texture testTurmTexture;
	sf::Sprite testTurmSprite;
	string t_Name;
	string t_Description;
	int t_Cost;
	int t_XCoord;
	int t_YCoord;
	
public:
	BasicTower(int XCoord, int YCoord);

	//Getter
	inline int getCost() const { return t_Cost; }
	inline int getXCoord() const { return t_XCoord; }
	inline int getYCoord() const { return t_YCoord; }
	inline string getDescription() const { return t_Description; }
	inline sf::Sprite getSprite() const { return testTurmSprite; };
	
	BasicTower();

	vector<DummyEnemy*> checkForEnemies(vector<DummyEnemy*> *enemyActiveVector);
	void dealDamage();

};

#endif