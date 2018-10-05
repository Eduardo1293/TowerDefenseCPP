#include "BasicTower.h"

FrostTower::FrostTower(float XCoord, float YCoord)
	: BasicTower(XCoord, YCoord, "ArtAssets/Tower/tank_red.png", "Flametower",
		"Flamenturm mit Area-Schaden", 30, 0, 10)
{
}

vector<int> FrostTower::checkForEnemies(vector<BasicEnemy*>* enemyActiveVector)
{
	return vector<int>();
}

