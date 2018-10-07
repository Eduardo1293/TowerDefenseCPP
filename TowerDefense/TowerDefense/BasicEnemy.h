#pragma once
#ifndef _DUMMYENEMY_H_
#define _DUMMYENEMY_H_

#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class BasicEnemy {
private:
	sf::Texture BasicEnemyTexture;
	sf::Sprite BasicEnemySprite;
	sf::Texture lifeBarTexture;
	sf::Sprite lifeBarSprite;
	double e_MaxLife;
	double e_CurrentLife;
	float e_XCoord;
	float e_YCoord;
	int e_globalLocation;
	int e_navigationHelper;
	int e_movementSpeed;
	bool e_frozen;
	int e_frozenTimer;


public:
	BasicEnemy(float XCoord, float YCoord);
	BasicEnemy(float XCoord, float YCoord, int maxLife, int CurrentLife, string textureLocation);

	//Setter
	void eSetRotation(float rotation);
	void eSetPosition();
	void eSetXCoord(float XCoord);
	void eSetYCoord(float YCoord);
	void eSetGlobalLocation(int location);
	void eSetNavigationHelper(int navi);
	void eSetFrozen();

	//getter
	double eGetMaxLife(); 
	double eGetCurrentLife(); 
	float eGetXCoord();
	float eGetYCoord();						
	int eGetGlobalLocation();
	int eGetNavigationHelper();
	int eGetMovementSpeed();
	bool eGetFrozen;
	sf::Sprite eGetSprite();

	void takeDamage(int damage);

	BasicEnemy();

	~BasicEnemy();
};

class FastEnemy : public BasicEnemy 
{
public:
	FastEnemy(float XCoord, float YCoord, string textureLocation);
};


class WeakestEnemy : public BasicEnemy 
{
public:
	WeakestEnemy(float XCoord, float YCoord, string textureLocation);
};


class WeakerEnemy : public BasicEnemy
{
public:
	WeakerEnemy(float XCoord, float YCoord, string textureLocation);
};


class WeakEnemy : public BasicEnemy
{
public:
	WeakEnemy(float XCoord, float YCoord, string textureLocation);
};


class StrongEnemy : public BasicEnemy 
{
public:
	StrongEnemy(float XCoord, float YCoord, string textureLocation);
};


class StrongerEnemy : public BasicEnemy
{
public:
	StrongerEnemy(float XCoord, float YCoord, string textureLocation);
};


class StrongestEnemy : public BasicEnemy
{
public:
	StrongestEnemy(float XCoord, float YCoord, string textureLocation);
};


class BossEnemy : public BasicEnemy
{
public:
	BossEnemy(float XCoord, float YCoord, string textureLocation);
};

#endif


