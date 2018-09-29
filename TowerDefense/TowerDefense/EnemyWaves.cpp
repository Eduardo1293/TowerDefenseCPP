#include "EnemyWaves.h"
#include <list>
#include <vector>

//Gegnerwaves
vector<BasicEnemy*> enemyWaves(int waveNumber) {
	vector<BasicEnemy*> *enemyWaveVector = new vector<BasicEnemy*>();
	int xCoord = 63;
	int yCoord = 96;
	if (waveNumber == 1) 
	{
		int maxLife = 100;
		int currentLife = maxLife;
		string textureLocation = "ArtAssets/Enemies/enemyBlack1.png";
		BasicEnemy *numberOne = new BasicEnemy(xCoord, yCoord, maxLife, currentLife, textureLocation);
		BasicEnemy *numberTwo = new BasicEnemy(xCoord, yCoord, maxLife, currentLife, textureLocation);
		BasicEnemy *numberThree = new BasicEnemy(xCoord, yCoord, maxLife, currentLife, textureLocation);
		BasicEnemy *numberFour = new BasicEnemy(xCoord, yCoord, maxLife, currentLife, textureLocation);
		BasicEnemy *numberFive = new BasicEnemy(xCoord, yCoord, maxLife, currentLife, textureLocation);
		BasicEnemy *numberSix = new BasicEnemy(xCoord, yCoord, maxLife, currentLife, textureLocation);
		BasicEnemy *numberSeven = new BasicEnemy(xCoord, yCoord, maxLife, currentLife, textureLocation);
		
		enemyWaveVector->push_back(numberOne);
		enemyWaveVector->push_back(numberTwo);
		enemyWaveVector->push_back(numberThree);
		enemyWaveVector->push_back(numberFour);
		enemyWaveVector->push_back(numberFive);
		enemyWaveVector->push_back(numberSix);
		enemyWaveVector->push_back(numberSeven);
	}
	if (waveNumber == 2)
	{		
	}
	return *enemyWaveVector;
}