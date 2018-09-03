#pragma once
#ifndef _DUMMYENEMY_H_
#define _DUMMYENEMY_H_

#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class DummyEnemy {
private:
	sf::Texture dummyEnemyTexture;
	sf::Sprite dummyEnemySprite;
	sf::Texture lifeBarTexture;
	sf::Sprite lifeBarSprite;
	double e_MaxLife;
	double e_CurrentLife;
	int e_XCoord;
	int e_YCoord;

public:
	DummyEnemy(int XCoord, int YCoord);

	//Setter
	void eSetRotation(int rotation);
	void eSetPosition();
	void eSetXCoord(int XCoord);
	void eSetYCoord(int YCoord);

	//Getter
	double getMaxLife(); 
	double getCurrentLife(); 
	int getXCoord();
	int getYCoord();
	sf::Sprite getSprite();

	void takeDamage(int damage);

	DummyEnemy();
};


#endif


