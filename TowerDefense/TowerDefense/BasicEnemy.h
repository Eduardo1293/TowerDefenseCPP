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
	int eXCoord;
	int eYCoord;
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
	void eSetXCoord(int XCoord);
	void eSetYCoord(int YCoord);
	void eSetGlobalLocation(int location);
	void eSetMovementSpeed(int speed);
	void eSetFrozenTimer(int timer);

	//getter
	double eGetMaxLife(); 
	double eGetCurrentLife(); 
	int eGetXCoord();
	int eGetYCoord();						
	int eGetGlobalLocation();
	int eGetMovementSpeed();
	int eGetFrozenTimer();
	sf::Sprite eGetSprite();

	void eMovement(vector<int> path, vector<int> pathXCoord, vector<int> pathYCoord, vector<int> pathDirection);
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


