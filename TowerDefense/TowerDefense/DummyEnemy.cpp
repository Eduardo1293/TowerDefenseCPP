#include "DummyEnemy.h"



DummyEnemy::DummyEnemy(float XCoord, float YCoord) {
	e_MaxLife = 100;
	e_CurrentLife = 100;
	e_XCoord = XCoord;
	e_YCoord = YCoord;
	dummyEnemyTexture.loadFromFile("ArtAssets/Enemies/enemyBlack1.png");
	dummyEnemySprite.setTexture(dummyEnemyTexture);
	dummyEnemySprite.setOrigin(32, 32);
}

void DummyEnemy::eSetRotation(float rotation) {
	dummyEnemySprite.setRotation(rotation);
}

void DummyEnemy::eSetPosition() {
	dummyEnemySprite.setPosition(e_XCoord, e_YCoord);
}

void DummyEnemy::eSetXCoord(float XCoord) {
	e_XCoord = XCoord;
}

void DummyEnemy::eSetYCoord(float YCoord) {
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

float DummyEnemy::getXCoord()
{
	return e_XCoord;
}

float DummyEnemy::getYCoord()
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
