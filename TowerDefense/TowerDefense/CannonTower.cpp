#include "CannonTower.h"

CannonTower::CannonTower(int XCoord, int YCoord)
{
	t_Name = "Cannontower";
	t_Description = "Ein Turm der Feuer schieﬂt";
	t_Cost = 20;
	t_XCoord = XCoord;
	t_YCoord = YCoord;
	attackCooldown = 2;
	damage = 25;
	CannonTurmTexture.loadFromFile("ArtAssets/Tower/tank_green.png");
	CannonTurmSprite.setTexture(CannonTurmTexture);
	CannonTurmSprite.setOrigin(32, 32);
	CannonTurmSprite.setPosition(t_XCoord, t_YCoord);
}

CannonTower::CannonTower()
{
	t_Description = "Ein Turm der Feuer schieﬂt, 25 Schaden";
}

int CannonTower::checkForEnemies(vector<DummyEnemy*>* enemyActiveVector)
{
	if (attackCooldown == 0) {
		for (unsigned int i = 0; i < enemyActiveVector->size(); i++) {
			int enemyXCoord = enemyActiveVector->at(i)->getXCoord();
			int enemyYCoord = enemyActiveVector->at(i)->getYCoord();
			//rechts unten
			if ((enemyXCoord > (t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
				&& (enemyYCoord > (t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
				CannonTurmSprite.setRotation(315);
				attackCooldown = 10;
				return i;
				break;
				//rechts 
			}
			else if ((enemyXCoord > (t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
				&& (enemyYCoord > (t_YCoord - 32)) && (enemyYCoord < (t_YCoord + 33))) {
				CannonTurmSprite.setRotation(270);
				attackCooldown = 10;
				//deal damage
				return i;
				break;
				//unten
			}
			else if ((enemyXCoord > (t_XCoord + -32)) && (enemyXCoord < (t_XCoord + 33))
				&& (enemyYCoord > (t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
				CannonTurmSprite.setRotation(0);
				attackCooldown = 10;
				//deal damage
				return i;
				break;
				//links unten 
			}
			else if ((enemyXCoord > (t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
				&& (enemyYCoord > (t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
				CannonTurmSprite.setRotation(45);
				attackCooldown = 10;
				//deal damage
				return i;
				break;
				//rechts oben
			}
			else if ((enemyXCoord > (t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
				&& (enemyYCoord > (t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
				CannonTurmSprite.setRotation(225);
				attackCooldown = 10;
				//deal damage
				return i;
				break;
				//links
			}
			else if ((enemyXCoord > (t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
				&& (enemyYCoord > (t_YCoord - 32)) && (enemyYCoord < (t_YCoord + 33))) {
				CannonTurmSprite.setRotation(90);
				attackCooldown = 10;
				//deal damage
				return i;
				break;;
				//oben
			}
			else if ((enemyXCoord > (t_XCoord - 32)) && (enemyXCoord < (t_XCoord + 33))
				&& (enemyYCoord > (t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
				CannonTurmSprite.setRotation(180);
				attackCooldown = 10;
				return i;
				break;
				//deal damage
				//links oben
			}
			else if ((enemyXCoord > (t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
				&& (enemyYCoord > (t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
				CannonTurmSprite.setRotation(135);
				attackCooldown = 10;
				return i;
				break;
				//deal damage	
			}
		}
	}
	else {
		attackCooldown -= 1;
	}
	return 999;
}

void CannonTower::dealDamage()
{
}
