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
}

BasicTower::BasicTower()
{
}

void BasicTower::checkForEnemies() {
}

void BasicTower::dealDamage() {
}


