#include "BasicTower.h"



BasicTower::BasicTower(int XCoord, int YCoord) {
	t_Name = "Basistower";
	t_Description = "Test";
	t_Cost = 10;
	t_XCoord = XCoord;
	t_YCoord = YCoord;
	testTurmTexture.loadFromFile("ArtAssets/Tower/tank_dark.png");
	testTurmSprite.setTexture(testTurmTexture);
	testTurmSprite.setOrigin(32, 32);
	testTurmSprite.setPosition(t_XCoord, t_YCoord);
}

BasicTower::BasicTower()
{
}

void BasicTower::checkForEnemies(vector<DummyEnemy*> *enemyActiveVector) {
	for (unsigned int i = 0; i < enemyActiveVector->size(); i++) {
		int enemyXCoord = enemyActiveVector->at(i)->getXCoord();
		int enemyYCoord = enemyActiveVector->at(i)->getYCoord();
		//rechts unten
		if ((enemyXCoord > (t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
			&& (enemyYCoord > (t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
			testTurmSprite.setRotation(315);
			//deal damage
			break;
		//rechts 
		} else if ((enemyXCoord > (t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
			&& (enemyYCoord > (t_YCoord - 32)) && (enemyYCoord < (t_YCoord + 33))) {
			testTurmSprite.setRotation(270);
			//deal damage
			break;
		//unten
		} else if ((enemyXCoord >(t_XCoord + -32)) && (enemyXCoord < (t_XCoord + 33))
			&& (enemyYCoord >(t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
			testTurmSprite.setRotation(0);
			//deal damage
			break;
		//links unten 
		}
		else if ((enemyXCoord >(t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
			&& (enemyYCoord >(t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
			testTurmSprite.setRotation(45);
			//deal damage
			break;
		//rechts oben
		} else if ((enemyXCoord > (t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
			&& (enemyYCoord >(t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
			testTurmSprite.setRotation(225);
			//deal damage
			break;
		//links
		} else if ((enemyXCoord > (t_XCoord - 96)) && (enemyXCoord < (t_XCoord -32))
			&& (enemyYCoord >(t_YCoord - 32)) && (enemyYCoord < (t_YCoord + 33))) {
			testTurmSprite.setRotation(90);
			//deal damage
			break;
		//oben
		} else if ((enemyXCoord >(t_XCoord - 32)) && (enemyXCoord < (t_XCoord + 33))
			&& (enemyYCoord >(t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
			testTurmSprite.setRotation(180);
			//deal damage
			break;
		//links oben
		} else if ((enemyXCoord >(t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
			&& (enemyYCoord >(t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
			testTurmSprite.setRotation(135);
			//deal damage
			break;		
		}
	}
}

void BasicTower::dealDamage() {
}


