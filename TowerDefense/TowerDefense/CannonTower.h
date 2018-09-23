#pragma once
#include "BasicTower.h"
class CannonTower : public BasicTower {

private:
	sf::Texture CannonTurmTexture;
	sf::Sprite CannonTurmSprite;
	string t_Name;
	string t_Description;
	int t_Cost;
	int t_XCoord;
	int t_YCoord;
	int attackCooldown;
	int damage;

public:
	CannonTower(int XCoord, int YCoord);
	//Getter
	inline int getCost() const { return t_Cost; }
	inline int getXCoord() const { return t_XCoord; }
	inline int getYCoord() const { return t_YCoord; }
	inline int getAttackCooldown() const { return attackCooldown; }
	inline int getDamage() const { return damage; }
	inline string getDescription() const { return t_Description; }
	inline sf::Sprite getSprite() const { return CannonTurmSprite; };

	CannonTower();

	int checkForEnemies(vector<DummyEnemy*> *enemyActiveVector);
	void dealDamage();
};

