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
	double eMaxLife;
	double eCurrentLife;
	float eXCoord;
	float eYCoord;
	int eGlobalLocation;
	int eNavigationHelper;
	int eMovementSpeed;
	int eFrozenTimer;

public:
	BasicEnemy();
	BasicEnemy(int maxLife, int movSpeed, string textureLocation);

	//Setter
	void eSetRotation(float rotation);
	void eSetPosition();
	void eSetXCoord(float XCoord);
	void eSetYCoord(float YCoord);
	void eSetGlobalLocation(int location);
	void eSetNavigationHelper(int navi);
	void eSetMovementSpeed(int speed);
	void eSetFrozenTimer(int timer);

	//getter
	double eGetMaxLife(); 
	double eGetCurrentLife(); 
	float eGetXCoord();
	float eGetYCoord();						
	int eGetGlobalLocation();
	int eGetNavigationHelper();
	int eGetMovementSpeed();
	int eGetFrozenTimer();
	sf::Sprite eGetSprite();

	void takeDamage(int damage);

	~BasicEnemy();
};

class FastEnemy : public BasicEnemy 
{
public:
	FastEnemy();
};


class WeakestEnemy : public BasicEnemy 
{
public:
	WeakestEnemy();
};


class WeakerEnemy : public BasicEnemy
{
public:
	WeakerEnemy();
};


class WeakEnemy : public BasicEnemy
{
public:
	WeakEnemy();
};


class StrongEnemy : public BasicEnemy 
{
public:
	StrongEnemy();
};


class StrongerEnemy : public BasicEnemy
{
public:
	StrongerEnemy();
};


class StrongestEnemy : public BasicEnemy
{
public:
	StrongestEnemy();
};


class BossEnemy : public BasicEnemy
{
public:
	BossEnemy();
};

#endif


