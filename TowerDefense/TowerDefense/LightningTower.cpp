#include "BasicTower.h"
#include <random>



LightningTower::LightningTower(float XCoord, float YCoord, int areaID)
	: BasicTower(XCoord, YCoord, areaID, "ArtAssets/Tower/tank_sand.png", "Lightning Tower",
		"Greift einen zufälligen Gegner auf dem Feld an", 30, 0, 30, 5)
{
}

vector<int> LightningTower::checkForEnemies(vector<BasicEnemy*>* enemyActiveVector)
{
	if (tAttackCooldown == 0)
	{

		vector<int> enemies;
		enemies.clear();
		enemies.push_back(999);

		//Greift einen zufälligen Gegner auf der Map an
		random_device randomDevice;
		mt19937 generator(randomDevice());
		uniform_int_distribution<> verteilung(0, (enemyActiveVector->size() - 1));

		enemies.push_back(verteilung(generator));
		tAttackCooldown = 20;

		return enemies;
	}
	else
	{
		tAttackCooldown -= 1;
	}

}
