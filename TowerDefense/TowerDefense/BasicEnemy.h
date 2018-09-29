#pragma once
#ifndef _DUMMYENEMY_H_
#define _DUMMYENEMY_H_

#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class BasicEnemy {
private:
	sf::Texture dummyEnemyTexture;
	sf::Sprite dummyEnemySprite;
	sf::Texture lifeBarTexture;
	sf::Sprite lifeBarSprite;
	double e_MaxLife;
	double e_CurrentLife;
	float e_XCoord;
	float e_YCoord;

public:
	BasicEnemy(float XCoord, float YCoord);

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
};


#endif


