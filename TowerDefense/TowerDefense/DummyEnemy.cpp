#include "DummyEnemy.h"



DummyEnemy::DummyEnemy(int XCoord, int YCoord) {
	e_MaxLife = 100;
	e_CurrentLife = 100;
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

void DummyEnemy::takeDamage()
{
}

DummyEnemy::DummyEnemy()
{
}