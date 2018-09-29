#include "BasicTower.h"

CannonTower::CannonTower(float XCoord, float YCoord)
	: BasicTower(XCoord, YCoord, "ArtAssets/Tower/tank_green.png", "Cannontower",
		"Kanonenturm mit größerer Reichweite", 40, 0, 30)
{
}

int CannonTower::checkForEnemies(vector<BasicEnemy*>* enemyActiveVector)
{
	if (t_attackCooldown == 0) {
		for (unsigned int i = 0; i < enemyActiveVector->size(); i++) {
			float enemyXCoord = enemyActiveVector->at(i)->getXCoord();
			float enemyYCoord = enemyActiveVector->at(i)->getYCoord();
			//rechts unten
			if ((enemyXCoord > (t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
				&& (enemyYCoord > (t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
				t_BasicTurmSprite.setRotation(315);
				t_attackCooldown = 10;
				return i;
				break;
				//rechts 
			}
			else if ((enemyXCoord > (t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
				&& (enemyYCoord > (t_YCoord - 32)) && (enemyYCoord < (t_YCoord + 33))) {
				t_BasicTurmSprite.setRotation(270);
				t_attackCooldown = 10;
				//deal damage
				return i;
				break;
				//unten
			}
			else if ((enemyXCoord > (t_XCoord + -32)) && (enemyXCoord < (t_XCoord + 33))
				&& (enemyYCoord > (t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
				t_BasicTurmSprite.setRotation(0);
				t_attackCooldown = 10;
				//deal damage
				return i;
				break;
				//links unten 
			}
			else if ((enemyXCoord > (t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
				&& (enemyYCoord > (t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
				t_BasicTurmSprite.setRotation(45);
				t_attackCooldown = 10;
				//deal damage
				return i;
				break;
				//rechts oben
			}
			else if ((enemyXCoord > (t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
				&& (enemyYCoord > (t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
				t_BasicTurmSprite.setRotation(225);
				t_attackCooldown = 10;
				//deal damage
				return i;
				break;
				//links
			}
			else if ((enemyXCoord > (t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
				&& (enemyYCoord > (t_YCoord - 32)) && (enemyYCoord < (t_YCoord + 33))) {
				t_BasicTurmSprite.setRotation(90);
				t_attackCooldown = 10;
				//deal damage
				return i;
				break;;
				//oben
			}
			else if ((enemyXCoord > (t_XCoord - 32)) && (enemyXCoord < (t_XCoord + 33))
				&& (enemyYCoord > (t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
				t_BasicTurmSprite.setRotation(180);
				t_attackCooldown = 10;
				return i;
				break;
				//deal damage
				//links oben
			}
			else if ((enemyXCoord > (t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
				&& (enemyYCoord > (t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
				t_BasicTurmSprite.setRotation(135);
				t_attackCooldown = 10;
				return i;
				break;
				//deal damage	
			}
		}
	}
	else {
		t_attackCooldown -= 1;
	}
	return 999;
}

void CannonTower::dealDamage()
{
}
