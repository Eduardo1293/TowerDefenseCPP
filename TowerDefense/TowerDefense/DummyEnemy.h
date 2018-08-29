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
	int e_MaxLife;
	int e_CurrentLife;
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
	inline int getMaxLife() const { return e_MaxLife; }
	inline int getCurrentLife() const { return e_CurrentLife; }
	inline int getXCoord() const { return e_XCoord; }
	inline int getYCoord() const { return e_YCoord; }
	inline sf::Sprite getSprite() const { return dummyEnemySprite; }

	void takeDamage(int damage);

	DummyEnemy();
};


#endif


