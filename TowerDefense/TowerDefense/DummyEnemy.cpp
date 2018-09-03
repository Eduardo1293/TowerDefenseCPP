#include "DummyEnemy.h"



DummyEnemy::DummyEnemy(int XCoord, int YCoord) {
	e_MaxLife = 500;
	e_CurrentLife = 500;
	e_XCoord = XCoord;
	e_YCoord = YCoord;
	dummyEnemyTexture.loadFromFile("ArtAssets/Enemies/enemyBlack1.png");
	dummyEnemySprite.setTexture(dummyEnemyTexture);
	dummyEnemySprite.setOrigin(32, 32);
}

void DummyEnemy::eSetRotation(int rotation) {
	dummyEnemySprite.setRotation(rotation);
}

void DummyEnemy::eSetPosition() {
	dummyEnemySprite.setPosition(e_XCoord, e_YCoord);
}

void DummyEnemy::eSetXCoord(int XCoord) {
	e_XCoord = XCoord;
}

void DummyEnemy::eSetYCoord(int YCoord) {
	e_YCoord = YCoord;
}

double DummyEnemy::getMaxLife()
{
	return e_MaxLife;
}

double DummyEnemy::getCurrentLife()
{
	return e_CurrentLife;
}

int DummyEnemy::getXCoord()
{
	return e_XCoord;
}

int DummyEnemy::getYCoord()
{
	return e_YCoord;
}

sf::Sprite DummyEnemy::getSprite()
{
	return dummyEnemySprite;
}

void DummyEnemy::takeDamage(int damage) {
	e_CurrentLife = (e_CurrentLife - damage);
}

DummyEnemy::DummyEnemy()
{
}
