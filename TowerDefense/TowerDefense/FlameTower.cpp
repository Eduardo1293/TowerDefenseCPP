#include "BasicTower.h"

FlameTower::FlameTower(float XCoord, float YCoord) 
	: BasicTower(XCoord, YCoord, "ArtAssets/Tower/tank_red.png", "Flametower", 
		"Flamenturm mit Area-Schaden", 30, 0, 10)
{
}


//work in progress
vector<int> FlameTower::checkForEnemies(vector<BasicEnemy*>* enemyActiveVector)
{
	if (t_attackCooldown == 0) {

		for (unsigned int i = 0; i < enemyActiveVector->size(); i++) {
			vector<int> enemies;
			enemies.push_back(999);
			float enemyXCoord = enemyActiveVector->at(i)->getXCoord();
			float enemyYCoord = enemyActiveVector->at(i)->getYCoord();
			int priorityLocation;
			//rechts unten
			if ((enemyXCoord >(t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
				&& (enemyYCoord >(t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
				t_BasicTurmSprite.setRotation(315);
				t_attackCooldown = 10;
				priorityLocation = 9;
				enemyActiveVector->at(i)->eSetRelativeLocation(9);
				break;				
			}
			//rechts 
			else if ((enemyXCoord >(t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
				&& (enemyYCoord >(t_YCoord - 32)) && (enemyYCoord < (t_YCoord + 33))) {
				t_BasicTurmSprite.setRotation(270);
				t_attackCooldown = 10;
				priorityLocation = 6;				
			}
			//unten
			else if ((enemyXCoord >(t_XCoord + -32)) && (enemyXCoord < (t_XCoord + 33))
				&& (enemyYCoord >(t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
				t_BasicTurmSprite.setRotation(0);
				t_attackCooldown = 10;
				priorityLocation = 8;			 
			}
			//links unten
			else if ((enemyXCoord >(t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
				&& (enemyYCoord >(t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
				t_BasicTurmSprite.setRotation(45);
				t_attackCooldown = 10;
				priorityLocation = 7;				
			}
			//rechts oben
			else if ((enemyXCoord >(t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
				&& (enemyYCoord >(t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
				t_BasicTurmSprite.setRotation(225);
				t_attackCooldown = 10;
				priorityLocation = 3;				
			}
			//links
			else if ((enemyXCoord >(t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
				&& (enemyYCoord >(t_YCoord - 32)) && (enemyYCoord < (t_YCoord + 33))) {
				t_BasicTurmSprite.setRotation(90);
				t_attackCooldown = 10;
				priorityLocation = 4;				
			}
			//oben
			else if ((enemyXCoord >(t_XCoord - 32)) && (enemyXCoord < (t_XCoord + 33))
				&& (enemyYCoord >(t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
				t_BasicTurmSprite.setRotation(180);
				t_attackCooldown = 10;
				enemies.push_back(i);
				priorityLocation = 2;
			}
			//links oben
			else if ((enemyXCoord >(t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
				&& (enemyYCoord >(t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
				t_BasicTurmSprite.setRotation(135);
				t_attackCooldown = 10;
				priorityLocation = 1;
			}
			if (priorityLocation <= 9)
			{
				for (int i = 0; i < enemyActiveVector->size(); i++)
				{

				}
			}
		}
	}
	else {
		t_attackCooldown -= 1;
	}

}

void FlameTower::dealDamage()
{
}

//FlameTower::FlameTower(float XCoord, float YCoord)
//{
//}
