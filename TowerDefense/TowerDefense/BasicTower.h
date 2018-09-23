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
	sf::Texture BasicTurmTexture;
	sf::Sprite BasicTurmSprite;
	string t_Name;
	string t_Description;
	int t_Cost;
	int t_XCoord;
	int t_YCoord;
	int attackCooldown;
	int damage;
	
public:
	BasicTower(int XCoord, int YCoord);

	//Getter
	inline int getCost() const { return t_Cost; }
	inline int getXCoord() const { return t_XCoord; }
	inline int getYCoord() const { return t_YCoord; }
	inline int getAttackCooldown() const { return attackCooldown; }
	inline int getDamage() const { return damage; }
	inline string getDescription() const { return t_Description; }
	inline sf::Sprite getSprite() const { return BasicTurmSprite; };
	
	BasicTower();

	int checkForEnemies(vector<DummyEnemy*> *enemyActiveVector);
	void dealDamage();

};

#endif