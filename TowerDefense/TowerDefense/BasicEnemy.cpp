#include "BasicEnemy.h"



BasicEnemy::BasicEnemy(float XCoord, float YCoord) {
	e_MaxLife = 100;
	e_CurrentLife = 100;
	e_XCoord = XCoord;
	e_YCoord = YCoord;
	dummyEnemyTexture.loadFromFile("ArtAssets/Enemies/enemyBlack1.png");
	dummyEnemySprite.setTexture(dummyEnemyTexture);
	dummyEnemySprite.setOrigin(32, 32);
}

void BasicEnemy::eSetRotation(float rotation) {
	dummyEnemySprite.setRotation(rotation);
}

void BasicEnemy::eSetPosition() {
	dummyEnemySprite.setPosition(e_XCoord, e_YCoord);
}

void BasicEnemy::eSetXCoord(float XCoord) {
	e_XCoord = XCoord;
}

void BasicEnemy::eSetYCoord(float YCoord) {
	e_YCoord = YCoord;
}

double BasicEnemy::getMaxLife()
{
	return e_MaxLife;
}

double BasicEnemy::getCurrentLife()
{
	return e_CurrentLife;
}

float BasicEnemy::getXCoord()
{
	return e_XCoord;
}

float BasicEnemy::getYCoord()
{
	return e_YCoord;
}

sf::Sprite BasicEnemy::getSprite()
{
	return dummyEnemySprite;
}

void BasicEnemy::takeDamage(int damage) {
	e_CurrentLife = (e_CurrentLife - damage);
}

BasicEnemy::BasicEnemy()
{
}
