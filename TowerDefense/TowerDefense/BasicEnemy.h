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

public:
	BasicEnemy(float XCoord, float YCoord);
	BasicEnemy(float XCoord, float YCoord, int maxLife, int CurrentLife, string textureLocation);

	//Setter
	void eSetRotation(float rotation);
	void eSetPosition();
	void eSetXCoord(float XCoord);
	void eSetYCoord(float YCoord);

	//Getter
	double getMaxLife(); 
	double getCurrentLife(); 
	float getXCoord();
	float getYCoord();
	sf::Sprite getSprite();

	void takeDamage(int damage);

	BasicEnemy();

	~BasicEnemy();
};

class FastEnemy : public BasicEnemy {
public:
	FastEnemy(float XCoord, float YCoord,string textureLocation);
};


#endif


