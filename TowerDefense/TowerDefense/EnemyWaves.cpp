#include "EnemyWaves.h"
#include <list>
#include <vector>

//Gegnerwaves
vector<BasicEnemy*> enemyWaves(int waveNumber) {
	vector<BasicEnemy*> *enemyWaveVector = new vector<BasicEnemy*>();
	if (waveNumber == 1) {
		BasicEnemy *numberOne = new BasicEnemy(63, 96);
		BasicEnemy *numberTwo = new BasicEnemy(63, 96);
		BasicEnemy *numberThree = new BasicEnemy(63, 96);
		BasicEnemy *numberFour = new BasicEnemy(63, 96);
		BasicEnemy *numberFive = new BasicEnemy(63, 96);
		BasicEnemy *numberSix = new BasicEnemy(63, 96);
		BasicEnemy *numberSeven = new BasicEnemy(63, 96);
		
		enemyWaveVector->push_back(numberOne);
		enemyWaveVector->push_back(numberTwo);
		enemyWaveVector->push_back(numberThree);
		enemyWaveVector->push_back(numberFour);
		enemyWaveVector->push_back(numberFive);
		enemyWaveVector->push_back(numberSix);
		enemyWaveVector->push_back(numberSeven);
	}
	return *enemyWaveVector;
}