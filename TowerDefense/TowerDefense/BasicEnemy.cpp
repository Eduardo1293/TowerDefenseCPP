#include "BasicEnemy.h"



BasicEnemy::BasicEnemy(float XCoord, float YCoord, int maxLife, int CurrentLife, string textureLocation) {
	e_MaxLife = maxLife;
	e_CurrentLife = CurrentLife;
	e_XCoord = XCoord;
	e_YCoord = YCoord;
	e_globalLocation = 999;
	e_movementSpeed = 3;
	e_navigationHelper = -1;
	e_frozenTimer = 0;
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

void BasicEnemy::eSetGlobalLocation(int location)
{
	e_globalLocation = location;
}

void BasicEnemy::eSetNavigationHelper(int navi)
{
	e_navigationHelper = navi;
}

//Getter
double BasicEnemy::eGetMaxLife()
{
	return e_MaxLife;
}

double BasicEnemy::eGetCurrentLife()
{
	return e_CurrentLife;
}

float BasicEnemy::eGetXCoord()
{
	return e_XCoord;
}

float BasicEnemy::eGetYCoord()
{
	return e_YCoord;
}

int BasicEnemy::eGetGlobalLocation()
{
	return e_globalLocation;
}

int BasicEnemy::eGetNavigationHelper()
{
	return e_navigationHelper;
}

int BasicEnemy::eGetMovementSpeed()
{
	return e_movementSpeed;
}

sf::Sprite BasicEnemy::eGetSprite()
{
	return BasicEnemySprite;
}

void BasicEnemy::takeDamage(int damage) {
	e_CurrentLife = (e_CurrentLife - damage);
}

BasicEnemy::BasicEnemy()
{
}
