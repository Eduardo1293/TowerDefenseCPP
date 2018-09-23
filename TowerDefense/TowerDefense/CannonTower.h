#pragma once
#include "BasicTower.h"
class CannonTower : BasicTower {

private:
	sf::Texture CannonTurmTexture;
	sf::Sprite CannonTurmSprite;
	string t_Name;
	string t_Description;
	int t_Cost;
	float t_XCoord;
	float t_YCoord;
	int attackCooldown;
	int damage;

public:
	CannonTower(float XCoord, float YCoord);
	//Getter
	inline int getCost() const { return t_Cost; }
	inline float getXCoord() const { return t_XCoord; }
	inline float getYCoord() const { return t_YCoord; }
	inline int getAttackCooldown() const { return attackCooldown; }
	inline int getDamage() const { return damage; }
	inline string getDescription() const { return t_Description; }
	inline sf::Sprite getSprite() const { return CannonTurmSprite; };

	CannonTower();

	int checkForEnemies(vector<DummyEnemy*> *enemyActiveVector);
	void dealDamage();
};

