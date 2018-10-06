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
	sf::Texture tBasicTurmTexture;
	string tName;
	string tDescription;
	int tCost;
	bool tFrosttower;

protected:
	int tAttackCooldown;
	int tDamage;
	int tGlobalLocation;
	float tXCoord;
	float tYCoord;
	sf::Sprite tBasicTurmSprite;

public:

	//Konstruktor
	BasicTower(float XCoord, float YCoord, int areaID);
	BasicTower(float XCoord, float YCoord, int areaID, string t_TextureLocation, string t_Name,
		string t_Description, int t_Cost, int attackCooldown, int damage);

	//Destruktor
	~BasicTower();

	//Getter
	inline int getCost() const { return tCost; }
	inline float getXCoord() const { return tXCoord; }
	inline float getYCoord() const { return tYCoord; }
	inline int getAttackCooldown() const { return tAttackCooldown; }
	inline int getDamage() const { return tDamage; }
	inline string getDescription() const { return tDescription; }
	inline sf::Sprite getSprite() const { return tBasicTurmSprite; }
	inline bool getFrostTower() const { return tFrosttower; }
	
	BasicTower();

	vector<int> checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	void dealDamage();

};

class CannonTower : public BasicTower {

public:
	CannonTower(float XCoord, float YCoord, int areaID);

	vector<int> checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	void dealDamage();
};

class FlameTower : public BasicTower {

public:
	FlameTower(float XCoord, float YCoord, int areaID);

	vector<int> checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	void dealDamage();
};

class FrostTower : public BasicTower {

public:
	FrostTower(float XCoord, float YCoord, int areaID);

	vector<int> checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	void dealDamage();
};

class LightningTower : public BasicTower {

public:
	LightningTower(float XCoord, float YCoord, int areaID);

	vector<int> checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	void dealDamage();
};
#endif