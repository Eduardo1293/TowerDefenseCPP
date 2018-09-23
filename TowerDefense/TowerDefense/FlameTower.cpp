#include "FlameTower.h"



FlameTower::FlameTower(float XCoord, float YCoord)
{
	t_Name = "Flametower";
	t_Description = "Ein Turm der Feuer schieﬂt";
	t_Cost = 50;
	t_XCoord = XCoord;
	t_YCoord = YCoord;
	attackCooldown = 3;
	damage = 75;
	FlameTurmTexture.loadFromFile("ArtAssets/Tower/tank_red.png");
	FlameTurmSprite.setTexture(FlameTurmTexture);
	FlameTurmSprite.setOrigin(32, 32);
	FlameTurmSprite.setPosition(t_XCoord, t_YCoord);
}

FlameTower::FlameTower()
{
	t_Description = "Ein Turm der Feuer schieﬂt";
}

int FlameTower::checkForEnemies(vector<DummyEnemy*>* enemyActiveVector)
{
	if (attackCooldown == 0) {
		for (unsigned int i = 0; i < enemyActiveVector->size(); i++) {
			float enemyXCoord = enemyActiveVector->at(i)->getXCoord();
			float enemyYCoord = enemyActiveVector->at(i)->getYCoord();
			//rechts unten
			if ((enemyXCoord > (t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
				&& (enemyYCoord > (t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
				FlameTurmSprite.setRotation(315);
				attackCooldown = 10;
				return i;
				break;
				//rechts 
			}
			else if ((enemyXCoord > (t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
				&& (enemyYCoord > (t_YCoord - 32)) && (enemyYCoord < (t_YCoord + 33))) {
				FlameTurmSprite.setRotation(270);
				attackCooldown = 10;
				//deal damage
				return i;
				break;
				//unten
			}
			else if ((enemyXCoord > (t_XCoord + -32)) && (enemyXCoord < (t_XCoord + 33))
				&& (enemyYCoord > (t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
				FlameTurmSprite.setRotation(0);
				attackCooldown = 10;
				//deal damage
				return i;
				break;
				//links unten 
			}
			else if ((enemyXCoord > (t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
				&& (enemyYCoord > (t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
				FlameTurmSprite.setRotation(45);
				attackCooldown = 10;
				//deal damage
				return i;
				break;
				//rechts oben
			}
			else if ((enemyXCoord > (t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
				&& (enemyYCoord > (t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
				FlameTurmSprite.setRotation(225);
				attackCooldown = 10;
				//deal damage
				return i;
				break;
				//links
			}
			else if ((enemyXCoord > (t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
				&& (enemyYCoord > (t_YCoord - 32)) && (enemyYCoord < (t_YCoord + 33))) {
				FlameTurmSprite.setRotation(90);
				attackCooldown = 10;
				//deal damage
				return i;
				break;;
				//oben
			}
			else if ((enemyXCoord > (t_XCoord - 32)) && (enemyXCoord < (t_XCoord + 33))
				&& (enemyYCoord > (t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
				FlameTurmSprite.setRotation(180);
				attackCooldown = 10;
				return i;
				break;
				//deal damage
				//links oben
			}
			else if ((enemyXCoord > (t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
				&& (enemyYCoord > (t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
				FlameTurmSprite.setRotation(135);
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

void FlameTower::dealDamage()
{
}
