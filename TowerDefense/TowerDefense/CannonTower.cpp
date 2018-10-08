#include "BasicTower.h"

CannonTower::CannonTower(float XCoord, float YCoord, int areaID)
	: BasicTower(XCoord, YCoord, areaID, "ArtAssets/Tower/tank_green.png", "Cannontower",
		"Kanonenturm mit größerer Reichweite", 40, 0, 30, 2)
{
}

vector<int> CannonTower::checkForEnemies(vector<BasicEnemy*>* enemyActiveVector)
{
	vector<int> enemies;

	if (tAttackCooldown == 0)
	{
		for (unsigned int i = 0; i < enemyActiveVector->size(); i++) {
			int enemyLocation = enemyActiveVector->at(i)->eGetGlobalLocation();

			//rechts unten
			if (tXCoord != 447 && tYCoord != 703 && enemyLocation == tGlobalLocation + 8)
			{
				tBasicTurmSprite.setRotation(315);
				tAttackCooldown = 10;
				enemies.push_back(i);
				return enemies;
			}

			//rechts 
			else if (tXCoord != 447 && enemyLocation == tGlobalLocation + 1)
			{
				tBasicTurmSprite.setRotation(270);
				tAttackCooldown = 10;
				enemies.push_back(i);
				return enemies;
			}

			//unten
			else if (tYCoord != 703 && enemyLocation == tGlobalLocation + 7)
			{
				tBasicTurmSprite.setRotation(0);
				tAttackCooldown = 10;
				enemies.push_back(i);
				return enemies;
			}

			//links unten 
			else if (tXCoord != 63 && tYCoord != 703 && enemyLocation == tGlobalLocation + 6)
			{
				tBasicTurmSprite.setRotation(45);
				tAttackCooldown = 10;
				enemies.push_back(i);
				return enemies;
			}

			//rechts oben
			else if (tXCoord != 448 && tYCoord != 191 && enemyLocation == tGlobalLocation - 6)
			{
				tBasicTurmSprite.setRotation(225);
				tAttackCooldown = 10;
				enemies.push_back(i);
				return enemies;
			}

			//links
			else if (tXCoord != 63 && enemyLocation == tGlobalLocation - 1)
			{
				tBasicTurmSprite.setRotation(90);
				tAttackCooldown = 10;
				enemies.push_back(i);
				return enemies;
			}

			//oben
			else if (tYCoord != 191 && enemyLocation == tGlobalLocation - 7)
			{
				tBasicTurmSprite.setRotation(180);
				tAttackCooldown = 10;
				enemies.push_back(i);
				return enemies;
			}

			//links oben
			else if (tXCoord != 63 && tYCoord != 191 && enemyLocation == tGlobalLocation - 8)
			{
				tBasicTurmSprite.setRotation(135);
				tAttackCooldown = 10;
				enemies.push_back(i);
				return enemies;
			}

			else
			{
				return enemies;
			}
		}
	}
	else
	{
		tAttackCooldown -= 1;
		return enemies;
	}

}

