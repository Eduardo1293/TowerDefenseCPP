#include "BasicTower.h"

FrostTower::FrostTower()
{
	tDescription = "Frost Turm : Gold XX";
}

FrostTower::FrostTower(float XCoord, float YCoord, int areaID)
	: BasicTower(XCoord, YCoord, areaID, "ArtAssets/Tower/tank_blue.png", "Flametower",
		"Flamenturm mit Area-Schaden", 60, 20, 10, 3)
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
vector<int> FrostTower::checkForEnemies(vector<BasicEnemy*>* enemyActiveVector)
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
				tAttackCooldown = tAttackSpeed;
				enemies.push_back(i);
				return enemies;
			}

			//rechts 
			else if (tXCoord != 447 && enemyLocation == tGlobalLocation + 1)
			{
				tBasicTurmSprite.setRotation(270);
				tAttackCooldown = tAttackSpeed;
				enemies.push_back(i);
				return enemies;
			}

			//unten
			else if (tYCoord != 703 && enemyLocation == tGlobalLocation + 7)
			{
				tBasicTurmSprite.setRotation(0);
				tAttackCooldown = tAttackSpeed;
				enemies.push_back(i);
				return enemies;
			}

			//links unten 
			else if (tXCoord != 63 && tYCoord != 703 && enemyLocation == tGlobalLocation + 6)
			{
				tBasicTurmSprite.setRotation(45);
				tAttackCooldown = tAttackSpeed;
				enemies.push_back(i);
				return enemies;
			}

			//rechts oben
			else if (tXCoord != 447 && tYCoord != 191 && enemyLocation == tGlobalLocation - 6)
			{
				tBasicTurmSprite.setRotation(225);
				tAttackCooldown = tAttackSpeed;
				enemies.push_back(i);
				return enemies;
			}

			//links
			else if (tXCoord != 63 && enemyLocation == tGlobalLocation - 1)
			{
				tBasicTurmSprite.setRotation(90);
				tAttackCooldown = tAttackSpeed;
				enemies.push_back(i);
				return enemies;
			}

			//oben
			else if (tYCoord != 191 && enemyLocation == tGlobalLocation - 7)
			{
				tBasicTurmSprite.setRotation(180);
				tAttackCooldown = tAttackSpeed;
				enemies.push_back(i);
				return enemies;
			}

			//links oben
			else if (tXCoord != 63 && tYCoord != 191 && enemyLocation == tGlobalLocation - 8)
			{
				tBasicTurmSprite.setRotation(135);
				tAttackCooldown = tAttackSpeed;
				enemies.push_back(i);
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


