#pragma once
#ifndef _BASICTOWER_H_
#define _BASICTOWER_H_

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include "BasicEnemy.h"

using namespace std;

class BasicTower {

private:
	sf::Texture t_BasicTurmTexture;
	string t_Name;
	string t_Description;
	int t_Cost;
	
protected:
	int t_attackCooldown;
	int t_damage;
	float t_XCoord;
	float t_YCoord;
	sf::Sprite t_BasicTurmSprite;
	
public:

	//Konstruktor
	BasicTower(float XCoord, float YCoord);
	BasicTower(float XCoord, float YCoord, string t_TextureLocation, string t_Name,
		string t_Description, int t_Cost, int attackCooldown, int damage);

	//Destruktor
	~BasicTower();

	//Getter
	inline int getCost() const { return t_Cost; }
	inline float getXCoord() const { return t_XCoord; }
	inline float getYCoord() const { return t_YCoord; }
	inline int getAttackCooldown() const { return t_attackCooldown; }
	inline int getDamage() const { return t_damage; }
	inline string getDescription() const { return t_Description; }
	inline sf::Sprite getSprite() const { return t_BasicTurmSprite; };
	
	BasicTower();

	int checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	void dealDamage();

};

class CannonTower : public BasicTower {

public:
	CannonTower(float XCoord, float YCoord);

	int checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	void dealDamage();
};

class FlameTower : public BasicTower {

public:
	FlameTower(float XCoord, float YCoord);

	int checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	void dealDamage();
};

class FrostTower : public BasicTower {

public:
	FrostTower(float XCoord, float YCoord);

	int checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	void dealDamage();
};

class LightningTower : public BasicTower {

public:
	LightningTower(float XCoord, float YCoord);

	int checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	void dealDamage();
};
#endif