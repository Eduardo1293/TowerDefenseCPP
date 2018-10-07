#pragma once
#ifndef _BASICTOWER_H_
#define _BASICTOWER_H_

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include "BasicEnemy.h"

using namespace std;

/*
Der Basisturm. Fungiert gleichzeitig als Basisklasse für alle Türme
*/

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

	//Konstruktoren
	BasicTower();
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
	
	//Funktionen
	vector<int> checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	

};

/*
Grundlegender Turm, greift einen einzelnen Gegner an
*/

class AttackTower : public BasicTower 
{

public:
	AttackTower(float XCoord, float YCoord, int areaID);

	//Funktionen
	vector<int> checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);

};

/*
Kanonenturm, langsamer aber starker Angriff
*/
class CannonTower : public BasicTower 
{

public:
	CannonTower(float XCoord, float YCoord, int areaID);

	//Funktionen
	vector<int> checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	
};

/*
Flamenturm mit Flächenangriff
*/
class FlameTower : public BasicTower 
{

public:
	FlameTower(float XCoord, float YCoord, int areaID);

	//Funktionen
	vector<int> checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	
};

/*
Frostturm, der Gegner verlangsamen kann
*/
class FrostTower : public BasicTower {

public:
	FrostTower(float XCoord, float YCoord, int areaID);

	//Funktionen
	vector<int> checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	
};

/*
Blitzturm, greift einen zufälligen Gegner auf der Karte an
*/
class LightningTower : public BasicTower {

public:
	LightningTower(float XCoord, float YCoord, int areaID);

	//Funktionen
	vector<int> checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	
};
#endif