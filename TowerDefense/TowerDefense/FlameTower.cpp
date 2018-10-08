#include "BasicTower.h"

FlameTower::FlameTower(float XCoord, float YCoord, int areaID)
	: BasicTower(XCoord, YCoord, areaID, "ArtAssets/Tower/tank_red.png", "Flametower", 
		"Flamenturm mit Area-Schaden", 30, 0, 10, 4)
{
}

//wip
/*
Attacken-Cooldown auf 0:
Sucht auf den benachbarten Feldern nach Gegner. Priorisiert Gegner, die sich rechts unterhalb und damit
wahrscheinlich näher am Ziel befinden. Gibt die Position dieser Gegner im Gegner-Array als int-Vector
zurück. Setzt dann den Attacken-Cooldown
Attacken-Cooldown nicht auf 0:
Zählt den Cooldown um 1 runter.
*/
vector<int> FlameTower::checkForEnemies(vector<BasicEnemy*>* enemyActiveVector)
{
	vector<int> enemies;
	if (tAttackCooldown == 0)
	{

		for (unsigned int i = 0; i < enemyActiveVector->size(); i++) 
		{			

			int enemyLocation = enemyActiveVector->at(i)->eGetGlobalLocation();

			//rechts unten
			if (enemyLocation == tGlobalLocation + 8)
			{
				tBasicTurmSprite.setRotation(315);
				tAttackCooldown = 10;
				for (unsigned int j = 0; j < enemyActiveVector->size(); j++)
				{
					int addEnemyLocation = enemyActiveVector->at(j)->eGetGlobalLocation();				
					if (addEnemyLocation == tGlobalLocation + 8 || addEnemyLocation == tGlobalLocation + 1
						|| addEnemyLocation == tGlobalLocation + 1)
					{
						enemies.push_back(j);
					}
				}
				return enemies;
				break;
			}

			//rechts 
			else if (enemyLocation == tGlobalLocation + 1)
			{
				tBasicTurmSprite.setRotation(270);
				tAttackCooldown = 10;
				for (unsigned int j = 0; j < enemyActiveVector->size(); j++)
				{
					int addEnemyLocation = enemyActiveVector->at(j)->eGetGlobalLocation();
					if (addEnemyLocation == tGlobalLocation + 1 || addEnemyLocation == tGlobalLocation - 6
						|| addEnemyLocation == tGlobalLocation + 8)
					{
						enemies.push_back(j);
					}
				}
				return enemies;
				break;
			}

			//unten
			else if (enemyLocation == tGlobalLocation + 7)
			{
				tBasicTurmSprite.setRotation(0);
				tAttackCooldown = 10;
				for (unsigned int j = 0; j < enemyActiveVector->size(); j++)
				{
					int addEnemyLocation = enemyActiveVector->at(j)->eGetGlobalLocation();
					if (addEnemyLocation == tGlobalLocation + 7 || addEnemyLocation == tGlobalLocation + 8
						|| addEnemyLocation == tGlobalLocation + 6)
					{
						enemies.push_back(j);
					}
				}
				return enemies;
				break;
			}

			//links unten 
			else if (enemyLocation == tGlobalLocation + 6)
			{
				tBasicTurmSprite.setRotation(45);
				tAttackCooldown = 10;
				for (unsigned int j = 0; j < enemyActiveVector->size(); j++)
				{
					int addEnemyLocation = enemyActiveVector->at(j)->eGetGlobalLocation();
					if (addEnemyLocation == tGlobalLocation + 6 || addEnemyLocation == tGlobalLocation + 7
						|| addEnemyLocation == tGlobalLocation - 1)
					{
						enemies.push_back(j);
					}
				}
				return enemies;
				break;
			}

			//rechts oben
			else if (enemyLocation == tGlobalLocation - 6)
			{
				tBasicTurmSprite.setRotation(225);
				tAttackCooldown = 10;
				for (unsigned int j = 0; j < enemyActiveVector->size(); j++)
				{
					int addEnemyLocation = enemyActiveVector->at(j)->eGetGlobalLocation();
					if (addEnemyLocation == tGlobalLocation - 6 || addEnemyLocation == tGlobalLocation + 1
						|| addEnemyLocation == tGlobalLocation - 7)
					{
						enemies.push_back(j);
					}
				}
				return enemies;
				break;
			}

			//links
			else if (enemyLocation == tGlobalLocation - 1)
			{
				tBasicTurmSprite.setRotation(90);
				tAttackCooldown = 10;
				for (unsigned int j = 0; j < enemyActiveVector->size(); j++)
				{
					int addEnemyLocation = enemyActiveVector->at(j)->eGetGlobalLocation();
					if (addEnemyLocation == tGlobalLocation - 1 || addEnemyLocation == tGlobalLocation + 6
						|| addEnemyLocation == tGlobalLocation - 8)
					{
						enemies.push_back(j);
					}
				}
				return enemies;
				break;
			}

			//oben
			else if (enemyLocation == tGlobalLocation - 7)
			{
				tBasicTurmSprite.setRotation(180);
				tAttackCooldown = 10;
				for (unsigned int j = 0; j < enemyActiveVector->size(); j++)
				{
					int addEnemyLocation = enemyActiveVector->at(j)->eGetGlobalLocation();
					if (addEnemyLocation == tGlobalLocation - 7 || addEnemyLocation == tGlobalLocation - 6
						|| addEnemyLocation == tGlobalLocation - 8)
					{
						enemies.push_back(j);
					}
				}
				return enemies;
				break;
			}

			//links oben
			else if (enemyLocation == tGlobalLocation - 8)
			{
				tBasicTurmSprite.setRotation(135);
				tAttackCooldown = 10;
				for (unsigned int j = 0; j < enemyActiveVector->size(); j++)
				{
					int addEnemyLocation = enemyActiveVector->at(j)->eGetGlobalLocation();
					if (addEnemyLocation == tGlobalLocation - 8 || addEnemyLocation == tGlobalLocation - 1
						|| addEnemyLocation == tGlobalLocation - 7)
					{
						enemies.push_back(j);
					}
				}
				return enemies;
				break;
			}

			else
			{
				return enemies;
				break;
			}
		}
	}
	else
	{
		enemies.clear();
		tAttackCooldown -= 1;
		return enemies;
		tAttackCooldown -= 1;
	}

}

