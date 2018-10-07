#include "BasicTower.h"



LightningTower::LightningTower(float XCoord, float YCoord, int areaID)
	: BasicTower(XCoord, YCoord, areaID, "ArtAssets/Tower/tank_red.png", "Flametower",
		"Flamenturm mit Area-Schaden", 30, 0, 10)
{
}

vector<int> LightningTower::checkForEnemies(vector<BasicEnemy*>* enemyActiveVector)
{
	if (tAttackCooldown == 0)
	{

		for (unsigned int i = 0; i < enemyActiveVector->size(); i++) {
			vector<int> enemies;
			enemies.clear();
			enemies.push_back(999);
			int enemyLocation = enemyActiveVector->at(i)->eGetGlobalLocation();

			//rechts unten
			if (enemyLocation == tGlobalLocation + 8)
			{
				tBasicTurmSprite.setRotation(315);
				tAttackCooldown = 10;
				enemies.push_back(i);
				return enemies;
				break;
			}

			//rechts 
			else if (enemyLocation == tGlobalLocation + 1)
			{
				tBasicTurmSprite.setRotation(270);
				tAttackCooldown = 10;
				//deal damage
				enemies.push_back(i);
				return enemies;
				break;
			}

			//unten
			else if (enemyLocation == tGlobalLocation + 7)
			{
				tBasicTurmSprite.setRotation(0);
				tAttackCooldown = 10;
				//deal damage
				enemies.push_back(i);
				return enemies;
				break;
			}

			//links unten 
			else if (enemyLocation == tGlobalLocation + 6)
			{
				tBasicTurmSprite.setRotation(45);
				tAttackCooldown = 10;
				//deal damage
				enemies.push_back(i);
				return enemies;
				break;
			}

			//rechts oben
			else if (enemyLocation == tGlobalLocation - 6)
			{
				tBasicTurmSprite.setRotation(225);
				tAttackCooldown = 10;
				//deal damage
				enemies.push_back(i);
				return enemies;
				break;
			}

			//links
			else if (enemyLocation == tGlobalLocation - 1)
			{
				tBasicTurmSprite.setRotation(90);
				tAttackCooldown = 10;
				//deal damage
				enemies.push_back(i);
				return enemies;
				break;
			}

			//oben
			else if (enemyLocation == tGlobalLocation - 7)
			{
				tBasicTurmSprite.setRotation(180);
				tAttackCooldown = 10;
				enemies.push_back(i);
				return enemies;
				break;
			}

			//links oben
			else if (enemyLocation == tGlobalLocation - 8)
			{
				tBasicTurmSprite.setRotation(135);
				tAttackCooldown = 10;
				enemies.push_back(i);
				return enemies;
				break;
			}

			else
			{
				enemies.push_back(999);
				return enemies;
				break;
			}
		}
	}
	else
	{
		tAttackCooldown -= 1;
	}

}
