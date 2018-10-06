#include "BasicTower.h"



BasicTower::BasicTower(float XCoord, float YCoord, int areaID) {
	tName = "Basistower";
	tDescription = "Test";
	tCost = 1;
	tXCoord = XCoord;
	tYCoord = YCoord;
	tAttackCooldown = 0;
	tDamage = 10;
	tBasicTurmTexture.loadFromFile("ArtAssets/Tower/tank_dark.png");
	tBasicTurmSprite.setTexture(tBasicTurmTexture);
	tBasicTurmSprite.setOrigin(32, 32);
	tBasicTurmSprite.setPosition(tXCoord, tYCoord);
}

BasicTower::BasicTower(float xCoord, float yCoord, int areaID, string textureLocation, string name, string description, int cost, int attackCooldown, int damage)
{
	tName = textureLocation;
	tDescription = description;
	tCost = cost;
	tXCoord = xCoord;
	tYCoord = yCoord;
	tGlobalLocation = areaID;
	tAttackCooldown = attackCooldown;
	tDamage = damage;
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

vector<int> BasicTower::checkForEnemies(vector<BasicEnemy*> *enemyActiveVector) 
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
			else if (enemyLocation == tGlobalLocation -7) 
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
			}
		}
	}
	else 
	{
		tAttackCooldown -= 1;
	}
	
}

/*
for (unsigned int i = 0; i < enemyActiveVector->size(); i++) {
	vector<int> enemies;
	enemies.push_back(999);
	float enemyXCoord = enemyActiveVector->at(i)->eGetXCoord();
	float enemyYCoord = enemyActiveVector->at(i)->eGetYCoord();
	//rechts unten
	if ((enemyXCoord >(t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
		&& (enemyYCoord >(t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
		tBasicTurmSprite.setRotation(315);
		tAttackCooldown = 10;
		enemies.push_back(i);
		return enemies;
		break;
		//rechts 
	}
	else if ((enemyXCoord >(t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
		&& (enemyYCoord >(t_YCoord - 32)) && (enemyYCoord < (t_YCoord + 33))) {
		tBasicTurmSprite.setRotation(270);
		tAttackCooldown = 10;
		//deal damage
		enemies.push_back(i);
		return enemies;
		break;
		//unten
	}
	else if ((enemyXCoord >(t_XCoord + -32)) && (enemyXCoord < (t_XCoord + 33))
		&& (enemyYCoord >(t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
		tBasicTurmSprite.setRotation(0);
		tAttackCooldown = 10;
		//deal damage
		enemies.push_back(i);
		return enemies;
		break;
		//links unten 
	}
	else if ((enemyXCoord >(t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
		&& (enemyYCoord >(t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
		tBasicTurmSprite.setRotation(45);
		tAttackCooldown = 10;
		//deal damage
		enemies.push_back(i);
		return enemies;
		break;
		//rechts oben
	}
	else if ((enemyXCoord >(t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
		&& (enemyYCoord >(t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
		tBasicTurmSprite.setRotation(225);
		tAttackCooldown = 10;
		//deal damage
		enemies.push_back(i);
		return enemies;
		break;
		//links
	}
	else if ((enemyXCoord >(t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
		&& (enemyYCoord >(t_YCoord - 32)) && (enemyYCoord < (t_YCoord + 33))) {
		tBasicTurmSprite.setRotation(90);
		tAttackCooldown = 10;
		//deal damage
		enemies.push_back(i);
		return enemies;
		break;
		//oben
	}
	else if ((enemyXCoord >(t_XCoord - 32)) && (enemyXCoord < (t_XCoord + 33))
		&& (enemyYCoord >(t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
		tBasicTurmSprite.setRotation(180);
		tAttackCooldown = 10;
		enemies.push_back(i);
		return enemies;
		break;
		//deal damage
		//links oben
	}
	else if ((enemyXCoord >(t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
		&& (enemyYCoord >(t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
		tBasicTurmSprite.setRotation(135);
		tAttackCooldown = 10;
		enemies.push_back(i);
		return enemies;
		break;
		//deal damage	
	}
	else
	{
		return enemies;
	}
}
	}
	else {
		tAttackCooldown -= 1;
	}

}
*/

void BasicTower::dealDamage() {
}


