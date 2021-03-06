#pragma once
#ifndef _BASICTOWER_H_
#define _BASICTOWER_H_

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include "BasicEnemy.h"

using namespace std;

/*
Der Basisturm. Fungiert gleichzeitig als Basisklasse f�r alle T�rme
*/

class BasicTower {

private:
	sf::Texture tBasicTurmTexture;
	string tName;
	string tDescription;
	int tCost;
	bool tFrosttower;
	int tTowerType;	

protected:
	int tAttackCooldown;
	int tDamage;
	int tGlobalLocation;
	int tAttackSpeed;
	float tXCoord;
	float tYCoord;
	sf::Sprite tBasicTurmSprite;

public:

	//Konstruktoren
	BasicTower();
	BasicTower(float XCoord, float YCoord, int areaID);
	BasicTower(float XCoord, float YCoord, int areaID, string t_TextureLocation, string t_Name,
		string t_Description, int t_Cost, int damage, int attackSpeed, int type);

	//Destruktor
	~BasicTower();

	//Getter
	inline int getCost() const { return tCost; }
	inline float getXCoord() const { return tXCoord; }
	inline float getYCoord() const { return tYCoord; }
	inline int getAttackCooldown() const { return tAttackCooldown; }
	inline int getDamage() const { return tDamage; }
	inline int getType() const { return tTowerType; }
	inline int getLocation() const { return tGlobalLocation; }
	inline string getDescription() const { return tDescription; }
	inline sf::Sprite getSprite() const { return tBasicTurmSprite; }
	inline bool getFrostTower() const { return tFrosttower; }
	
	//Funktionen
	virtual vector<int> checkForEnemies(vector<BasicEnemy*> *enemyActiveVector) = 0;
	

};

/*
Grundlegender Turm, greift einen einzelnen Gegner an
*/

class AttackTower : public BasicTower 
{
private: 
	string tDescription;

public:

	AttackTower();
	AttackTower(float XCoord, float YCoord, int areaID);

	//Funktionen
	vector<int> checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	inline string getDescription() const { return tDescription; }
};

/*
Kanonenturm, langsamer aber starker Angriff
*/
class CannonTower : public BasicTower 
{
private:
	string tDescription;

public:
	CannonTower();
	CannonTower(float XCoord, float YCoord, int areaID);

	//Funktionen
	vector<int> checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	inline string getDescription() const { return tDescription; }
};

/*
Flamenturm mit Fl�chenangriff
*/
class FlameTower : public BasicTower 
{
private:
	string tDescription;

public:
	FlameTower();
	FlameTower(float XCoord, float YCoord, int areaID);


	//Funktionen
	vector<int> checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	inline string getDescription() const { return tDescription; }
};

/*
Frostturm, der Gegner verlangsamen kann
*/
class FrostTower : public BasicTower 
{

private:
	string tDescription;
public:
	FrostTower();
	FrostTower(float XCoord, float YCoord, int areaID);

	//Funktionen
	vector<int> checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	inline string getDescription() const { return tDescription; }
};

/*
Blitzturm, greift einen zuf�lligen Gegner auf der Karte an
*/
class LightningTower : public BasicTower 
{

private:
	string tDescription;
public:
	LightningTower();
	LightningTower(float XCoord, float YCoord, int areaID);

	//Funktionen
	vector<int> checkForEnemies(vector<BasicEnemy*> *enemyActiveVector);
	inline string getDescription() const { return tDescription; }
};
#endif