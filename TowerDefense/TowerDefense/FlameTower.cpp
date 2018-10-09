#include "BasicTower.h"

FlameTower::FlameTower()
{
	tDescription = "Feuer Turm : Gold XX";
}

FlameTower::FlameTower(float XCoord, float YCoord, int areaID)
	: BasicTower(XCoord, YCoord, areaID, "ArtAssets/Tower/tank_red.png", "Flametower", 
		"Flamenturm mit Area-Schaden", 30, 10, 15, 4)
{
}

//wip
/*
Attacken-Cooldown auf 0:
Sucht auf den benachbarten Feldern nach Gegner. Priorisiert Gegner, die sich rechts unterhalb und damit
wahrscheinlich näher am Ziel befinden. Gibt die Position dieser Gegner im Gegner-Array als int-Vector
zurück. Setzt dann den Attacken-Cooldown.
Der Flametower greift alle Gegner auf dem Hauptfeld und den beiden Nachbarfeldern an.
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
			if (tXCoord != 447 && tYCoord != 703 && enemyLocation == tGlobalLocation + 8)
			{
				tBasicTurmSprite.setRotation(315);
				tAttackCooldown = 10;
				for (unsigned int j = 0; j < enemyActiveVector->size(); j++)
				{
					int addEnemyLocation = enemyActiveVector->at(j)->eGetGlobalLocation();				
					if ((addEnemyLocation == tGlobalLocation + 8 && tYCoord != 703 && tXCoord != 447)
						|| (tXCoord != 63 && addEnemyLocation == tGlobalLocation - 1)
						|| (tXCoord != 447 && addEnemyLocation == tGlobalLocation + 1))
					{
						enemies.push_back(j);
					}
				}
				return enemies;
			}

			//rechts 
			else if (tXCoord != 447 && enemyLocation == tGlobalLocation + 1)
			{
				tBasicTurmSprite.setRotation(270);
				tAttackCooldown = 10;
				for (unsigned int j = 0; j < enemyActiveVector->size(); j++)
				{
					int addEnemyLocation = enemyActiveVector->at(j)->eGetGlobalLocation();
					if ((tXCoord != 447 && addEnemyLocation == tGlobalLocation + 1)
						|| (tXCoord != 448 && tYCoord != 191 && addEnemyLocation == tGlobalLocation - 6)
						|| (tXCoord != 447 && tYCoord != 703 && addEnemyLocation == tGlobalLocation + 8))
					{
						enemies.push_back(j);
					}
				}
				return enemies;
			}

			//unten
			else if (tYCoord != 703 && enemyLocation == tGlobalLocation + 7)
			{
				tBasicTurmSprite.setRotation(0);
				tAttackCooldown = 10;
				for (unsigned int j = 0; j < enemyActiveVector->size(); j++)
				{
					int addEnemyLocation = enemyActiveVector->at(j)->eGetGlobalLocation();
					if (addEnemyLocation == tGlobalLocation + 7 
						|| (tXCoord != 447 && tYCoord != 703 && addEnemyLocation == tGlobalLocation + 8)
						|| (tXCoord != 63 && tYCoord != 703 && addEnemyLocation == tGlobalLocation + 6))
					{
						enemies.push_back(j);
					}
				}
				return enemies;
			}

			//links unten 
			else if (tXCoord != 63 && tYCoord != 703 && enemyLocation == tGlobalLocation + 6)
			{
				tBasicTurmSprite.setRotation(45);
				tAttackCooldown = 10;
				for (unsigned int j = 0; j < enemyActiveVector->size(); j++)
				{
					int addEnemyLocation = enemyActiveVector->at(j)->eGetGlobalLocation();
					if (addEnemyLocation == tGlobalLocation + 6 
						|| (tYCoord != 703 && addEnemyLocation == tGlobalLocation + 7)
						|| (tXCoord != 63 && addEnemyLocation == tGlobalLocation - 1))
					{
						enemies.push_back(j);
					}
				}
				return enemies;
			}

			//rechts oben
			else if (tXCoord != 448 && tYCoord != 191 && enemyLocation == tGlobalLocation - 6)
			{
				tBasicTurmSprite.setRotation(225);
				tAttackCooldown = 10;
				for (unsigned int j = 0; j < enemyActiveVector->size(); j++)
				{
					int addEnemyLocation = enemyActiveVector->at(j)->eGetGlobalLocation();
					if (addEnemyLocation == tGlobalLocation - 6 
						|| (tXCoord != 447 && addEnemyLocation == tGlobalLocation + 1)
						|| (tYCoord != 191 && addEnemyLocation == tGlobalLocation - 7))
					{
						enemies.push_back(j);
					}
				}
				return enemies;
			}

			//links
			else if (tXCoord != 63 && enemyLocation == tGlobalLocation - 1)
			{
				tBasicTurmSprite.setRotation(90);
				tAttackCooldown = 10;
				for (unsigned int j = 0; j < enemyActiveVector->size(); j++)
				{
					int addEnemyLocation = enemyActiveVector->at(j)->eGetGlobalLocation();
					if (addEnemyLocation == tGlobalLocation - 1 
						|| (tXCoord != 63 && tYCoord != 703 && addEnemyLocation == tGlobalLocation + 6)
						|| (tXCoord != 63 && tYCoord != 191 && addEnemyLocation == tGlobalLocation - 8))
					{
						enemies.push_back(j);
					}
				}
				return enemies;
			}

			//oben
			else if (tYCoord != 191 && enemyLocation == tGlobalLocation - 7)
			{
				tBasicTurmSprite.setRotation(180);
				tAttackCooldown = 10;
				for (unsigned int j = 0; j < enemyActiveVector->size(); j++)
				{
					int addEnemyLocation = enemyActiveVector->at(j)->eGetGlobalLocation();
					if ((addEnemyLocation == tGlobalLocation - 7)
						|| (tXCoord != 448 && tYCoord != 191 && addEnemyLocation == tGlobalLocation - 6)
						|| (tXCoord != 63 && tYCoord != 191 && addEnemyLocation == tGlobalLocation - 8))
					{
						enemies.push_back(j);
					}
				}
				return enemies;
			}

			//links oben
			else if (tXCoord != 63 && tYCoord != 191 && enemyLocation == tGlobalLocation - 8)
			{
				tBasicTurmSprite.setRotation(135);
				tAttackCooldown = 10;
				for (unsigned int j = 0; j < enemyActiveVector->size(); j++)
				{
					int addEnemyLocation = enemyActiveVector->at(j)->eGetGlobalLocation();
					if (addEnemyLocation == tGlobalLocation - 8 
						|| (tXCoord != 63 && addEnemyLocation == tGlobalLocation - 1)
						|| (tYCoord != 191 && addEnemyLocation == tGlobalLocation - 7))
					{
						enemies.push_back(j);
					}
				}
				return enemies;
			}			
		}
		return enemies;
	}
	else
	{
		tAttackCooldown -= 1;
		return enemies;
	}

}

