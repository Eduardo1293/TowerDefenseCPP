#include "BasicTower.h"



BasicTower::BasicTower(float XCoord, float YCoord) {
	t_Name = "Basistower";
	t_Description = "Test";
	t_Cost = 1;
	t_XCoord = XCoord;
	t_YCoord = YCoord;
	t_attackCooldown = 0;
	t_damage = 10;
	t_BasicTurmTexture.loadFromFile("ArtAssets/Tower/tank_dark.png");
	t_BasicTurmSprite.setTexture(t_BasicTurmTexture);
	t_BasicTurmSprite.setOrigin(32, 32);
	t_BasicTurmSprite.setPosition(t_XCoord, t_YCoord);
}

BasicTower::BasicTower(float xCoord, float yCoord, string textureLocation, string name, string description, int cost, int attackCooldown, int damage)
{
	t_Name = textureLocation;
	t_Description = description;
	t_Cost = cost;
	t_XCoord = xCoord;
	t_YCoord = yCoord;
	t_attackCooldown = attackCooldown;
	t_damage = damage;
	t_BasicTurmTexture.loadFromFile(textureLocation);
	t_BasicTurmSprite.setTexture(t_BasicTurmTexture);
	t_BasicTurmSprite.setOrigin(32, 32);
	t_BasicTurmSprite.setPosition(t_XCoord, t_YCoord);
}

BasicTower::~BasicTower()
{
}

BasicTower::BasicTower()
{
	t_Description = "Der Basisturm, er macht 10 Schaden";
}

vector<int> BasicTower::checkForEnemies(vector<BasicEnemy*> *enemyActiveVector) {
	if (t_attackCooldown == 0) {
		
		for (unsigned int i = 0; i < enemyActiveVector->size(); i++) {
			vector<int> enemies;
			enemies.push_back(999);
			float enemyXCoord = enemyActiveVector->at(i)->getXCoord();
			float enemyYCoord = enemyActiveVector->at(i)->getYCoord();
			//rechts unten
			if ((enemyXCoord > (t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
				&& (enemyYCoord > (t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
				t_BasicTurmSprite.setRotation(315);
				t_attackCooldown = 10;
				enemies.push_back(i);
				return enemies;
				break;
				//rechts 
			}
			else if ((enemyXCoord > (t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
				&& (enemyYCoord > (t_YCoord - 32)) && (enemyYCoord < (t_YCoord + 33))) {
				t_BasicTurmSprite.setRotation(270);
				t_attackCooldown = 10;
				//deal damage
				enemies.push_back(i);
				return enemies;
				break;
				//unten
			}
			else if ((enemyXCoord > (t_XCoord + -32)) && (enemyXCoord < (t_XCoord + 33))
				&& (enemyYCoord > (t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
				t_BasicTurmSprite.setRotation(0);
				t_attackCooldown = 10;
				//deal damage
				enemies.push_back(i);
				return enemies;
				break;
				//links unten 
			}
			else if ((enemyXCoord > (t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
				&& (enemyYCoord > (t_YCoord + 32)) && (enemyYCoord < (t_YCoord + 97))) {
				t_BasicTurmSprite.setRotation(45);
				t_attackCooldown = 10;
				//deal damage
				enemies.push_back(i);
				return enemies;
				break;
				//rechts oben
			}
			else if ((enemyXCoord > (t_XCoord + 32)) && (enemyXCoord < (t_XCoord + 97))
				&& (enemyYCoord > (t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
				t_BasicTurmSprite.setRotation(225);
				t_attackCooldown = 10;
				//deal damage
				enemies.push_back(i);
				return enemies;
				break;
				//links
			}
			else if ((enemyXCoord > (t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
				&& (enemyYCoord > (t_YCoord - 32)) && (enemyYCoord < (t_YCoord + 33))) {
				t_BasicTurmSprite.setRotation(90);
				t_attackCooldown = 10;
				//deal damage
				enemies.push_back(i);
				return enemies;
				break;
				//oben
			}
			else if ((enemyXCoord > (t_XCoord - 32)) && (enemyXCoord < (t_XCoord + 33))
				&& (enemyYCoord > (t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
				t_BasicTurmSprite.setRotation(180);
				t_attackCooldown = 10;
				enemies.push_back(i);
				return enemies;
				break;
				//deal damage
			//links oben
			}
			else if ((enemyXCoord > (t_XCoord - 96)) && (enemyXCoord < (t_XCoord - 32))
				&& (enemyYCoord > (t_YCoord - 96)) && (enemyYCoord < (t_YCoord - 32))) {
				t_BasicTurmSprite.setRotation(135);
				t_attackCooldown = 10;
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
		t_attackCooldown -= 1;
	}
	
}

void BasicTower::dealDamage() {
}


