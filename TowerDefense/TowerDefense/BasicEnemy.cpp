#include "BasicEnemy.h"



BasicEnemy::BasicEnemy(float XCoord, float YCoord, int maxLife, int CurrentLife, string textureLocation) {
	e_MaxLife = maxLife;
	e_CurrentLife = CurrentLife;
	e_XCoord = XCoord;
	e_YCoord = YCoord;
	BasicEnemyTexture.loadFromFile(textureLocation);
	BasicEnemySprite.setTexture(BasicEnemyTexture);
	BasicEnemySprite.setOrigin(32, 32);
	//"ArtAssets/Enemies/enemyBlack1.png"
}

BasicEnemy::~BasicEnemy()
{
}

void BasicEnemy::eSetRotation(float rotation) {
	BasicEnemySprite.setRotation(rotation);
}

void BasicEnemy::eSetPosition() {
	BasicEnemySprite.setPosition(e_XCoord, e_YCoord);
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
	return BasicEnemySprite;
}

void BasicEnemy::takeDamage(int damage) {
	e_CurrentLife = (e_CurrentLife - damage);
}

BasicEnemy::BasicEnemy()
{
}
