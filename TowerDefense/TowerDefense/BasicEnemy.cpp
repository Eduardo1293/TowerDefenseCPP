#include "BasicEnemy.h"



BasicEnemy::BasicEnemy(int maxLife, int movSpeed, string textureLocation) {
	eMaxLife = maxLife;
	eCurrentLife = maxLife;
	eXCoord = 63;
	eYCoord = 96;
	eGlobalLocation = 999;
	eMovementSpeed = movSpeed;
	eNavigationHelper = -1;
	eFrozenTimer = 0;
	BasicEnemyTexture.loadFromFile(textureLocation);
	BasicEnemySprite.setTexture(BasicEnemyTexture);
	BasicEnemySprite.setOrigin(32, 32);
}

BasicEnemy::~BasicEnemy()
{
}

void BasicEnemy::eSetRotation(float rotation) {
	BasicEnemySprite.setRotation(rotation);
}

void BasicEnemy::eSetPosition() {
	BasicEnemySprite.setPosition(eXCoord, eYCoord);
}

void BasicEnemy::eSetXCoord(float XCoord) {
	eXCoord = XCoord;
}

void BasicEnemy::eSetYCoord(float YCoord) {
	eYCoord = YCoord;
}

void BasicEnemy::eSetGlobalLocation(int location)
{
	eGlobalLocation = location;
}

void BasicEnemy::eSetNavigationHelper(int navi)
{
	eNavigationHelper = navi;
}

void BasicEnemy::eSetMovementSpeed(int speed)
{
	eMovementSpeed = speed;
}

void BasicEnemy::eSetFrozenTimer(int timer)
{
	eFrozenTimer = timer;
}

//Getter
double BasicEnemy::eGetMaxLife()
{
	return eMaxLife;
}

double BasicEnemy::eGetCurrentLife()
{
	return eCurrentLife;
}

float BasicEnemy::eGetXCoord()
{
	return eXCoord;
}

float BasicEnemy::eGetYCoord()
{
	return eYCoord;
}

int BasicEnemy::eGetGlobalLocation()
{
	return eGlobalLocation;
}

int BasicEnemy::eGetFrozenTimer()
{
	return eFrozenTimer;
}

int BasicEnemy::eGetNavigationHelper()
{
	return eNavigationHelper;
}

int BasicEnemy::eGetMovementSpeed()
{
	return eMovementSpeed;
}

sf::Sprite BasicEnemy::eGetSprite()
{
	return BasicEnemySprite;
}

void BasicEnemy::takeDamage(int damage) {
	eCurrentLife = (eCurrentLife - damage);
}



BasicEnemy::BasicEnemy()
{
}
