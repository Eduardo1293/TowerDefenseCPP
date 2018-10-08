#include "BasicTower.h"



BasicTower::BasicTower(float XCoord, float YCoord, int areaID) {
	tName = "Basistower";
	tDescription = "Test";
	tCost = 1;
	tXCoord = XCoord;
	tYCoord = YCoord;
	tGlobalLocation = areaID;
	tAttackCooldown = 0;
	tDamage = 10;
	tBasicTurmTexture.loadFromFile("ArtAssets/Tower/tank_dark.png");
	tBasicTurmSprite.setTexture(tBasicTurmTexture);
	tBasicTurmSprite.setOrigin(32, 32);
	tBasicTurmSprite.setPosition(tXCoord, tYCoord);
}

BasicTower::BasicTower(float xCoord, float yCoord, int areaID, string textureLocation, string name, string description, int cost, int attackCooldown, int damage, int type)
{
	tName = textureLocation;
	tDescription = description;
	tCost = cost;
	tXCoord = xCoord;
	tYCoord = yCoord;
	tGlobalLocation = areaID;
	tAttackCooldown = attackCooldown;
	tDamage = damage;
	tTowerType = type;
	tBasicTurmTexture.loadFromFile(textureLocation);
	tBasicTurmSprite.setTexture(tBasicTurmTexture);
	tBasicTurmSprite.setOrigin(32, 32);
	tBasicTurmSprite.setPosition(tXCoord, tYCoord);

}

BasicTower::~BasicTower()
{
}

BasicTower::BasicTower()
{
	tDescription = "Der Basisturm, er macht 10 Schaden";
}

/*
Attacken-Cooldown auf 0:
Sucht auf den benachbarten Feldern nach Gegnern. Priorisiert Gegner, die sich rechts unterhalb und damit
wahrscheinlich näher am Ziel befinden. Gibt die Position dieser Gegner im Gegner-Array als int-Vector 
zurück. Setzt dann den Attacken-Cooldown auf 10.

Attacken-Cooldown nicht auf 0:
Zählt den Cooldown um 1 runter.
*/
/*vector<int> BasicTower::checkForEnemies(vector<BasicEnemy*> *enemyActiveVector) = 0;
{
	if (tAttackCooldown == 0) 
	{
		
		for (unsigned int i = 0; i < enemyActiveVector->size(); i++) {
			vector<int> enemies;
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
				enemies.push_back(i);
				return enemies;
				break;				
			}

			//unten
			else if (enemyLocation == tGlobalLocation + 7) 
			{
				tBasicTurmSprite.setRotation(0);
				tAttackCooldown = 10;
				enemies.push_back(i);
				return enemies;
				break;				
			}

			//links unten 
			else if (enemyLocation == tGlobalLocation + 6) 
			{
				tBasicTurmSprite.setRotation(45);
				tAttackCooldown = 10;
				enemies.push_back(i);
				return enemies;
				break;				
			}

			//rechts oben
			else if (enemyLocation == tGlobalLocation - 6) 
			{
				tBasicTurmSprite.setRotation(225);
				tAttackCooldown = 10;				
				enemies.push_back(i);
				return enemies;
				break;				
			}

			//links
			else if (enemyLocation == tGlobalLocation - 1) 
			{
				tBasicTurmSprite.setRotation(90);
				tAttackCooldown = 10;
				enemies.push_back(i);
				return enemies;
				break;				
			}

			//oben
			else if (enemyLocation == (tGlobalLocation -7)) 
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
*/


