#include "EnemyWaves.h"
#include <list>
#include <vector>

//Gegnerwaves
vector<DummyEnemy*> enemyWaves(int waveNumber) {
	vector<DummyEnemy*> *enemyWaveVector = new vector<DummyEnemy*>();
	if (waveNumber == 1) {
		DummyEnemy *numberOne = new DummyEnemy(63, 96);
		DummyEnemy *numberTwo = new DummyEnemy(63, 96);
		DummyEnemy *numberThree = new DummyEnemy(63, 96);
		DummyEnemy *numberFour = new DummyEnemy(63, 96);
		DummyEnemy *numberFive = new DummyEnemy(63, 96);
		DummyEnemy *numberSix = new DummyEnemy(63, 96);
		DummyEnemy *numberSeven = new DummyEnemy(63, 96);
		
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