#include "BasicTower.h"

FrostTower::FrostTower(float XCoord, float YCoord, int areaID)
	: BasicTower(XCoord, YCoord, areaID, "ArtAssets/Tower/tank_red.png", "Flametower",
		"Flamenturm mit Area-Schaden", 30, 0, 10, 3)
{
}

//wip
/*
Attacken-Cooldown auf 0:
Sucht auf den benachbarten Feldern nach Gegner. Priorisiert Gegner, die sich rechts unterhalb und damit
wahrscheinlich n�her am Ziel befinden. Gibt die Position dieser Gegner im Gegner-Array als int-Vector
zur�ck. Setzt dann den Attacken-Cooldown
Attacken-Cooldown nicht auf 0:
Z�hlt den Cooldown um 1 runter.
*/
vector<int> FrostTower::checkForEnemies(vector<BasicEnemy*>* enemyActiveVector)
{
	vector<int> enemies;

	if (tAttackCooldown == 0)
	{
		for (unsigned int i = 0; i < enemyActiveVector->size(); i++) {
			int enemyLocation = enemyActiveVector->at(i)->eGetGlobalLocation();

			//rechts unten
			if (enemyLocation == tGlobalLocation + 8)
			{
				tBasicTurmSprite.setRotation(315);
				tAttackCooldown = 10;
				enemies.push_back(i);
				return enemies;
			}

			//rechts 
			else if (enemyLocation == tGlobalLocation + 1)
			{
				tBasicTurmSprite.setRotation(270);
				tAttackCooldown = 10;
				//deal damage
				enemies.push_back(i);
				return enemies;
			}

			//unten
			else if (enemyLocation == tGlobalLocation + 7)
			{
				tBasicTurmSprite.setRotation(0);
				tAttackCooldown = 10;
				//deal damage
				enemies.push_back(i);
				return enemies;
			}

			//links unten 
			else if (enemyLocation == tGlobalLocation + 6)
			{
				tBasicTurmSprite.setRotation(45);
				tAttackCooldown = 10;
				//deal damage
				enemies.push_back(i);
				return enemies;
			}

			//rechts oben
			else if (enemyLocation == tGlobalLocation - 6)
			{
				tBasicTurmSprite.setRotation(225);
				tAttackCooldown = 10;
				//deal damage
				enemies.push_back(i);
				return enemies;
			}

			//links
			else if (enemyLocation == tGlobalLocation - 1)
			{
				tBasicTurmSprite.setRotation(90);
				tAttackCooldown = 10;
				//deal damage
				enemies.push_back(i);
				return enemies;
			}

			//oben
			else if (enemyLocation == tGlobalLocation - 7)
			{
				tBasicTurmSprite.setRotation(180);
				tAttackCooldown = 10;
				enemies.push_back(i);
				return enemies;
			}

			//links oben
			else if (enemyLocation == tGlobalLocation - 8)
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
		enemies.clear();
		tAttackCooldown -= 1;
		return enemies;
	}

}



