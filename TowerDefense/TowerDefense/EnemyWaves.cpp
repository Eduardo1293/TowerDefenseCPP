#include "EnemyWaves.h"
#include <list>
#include <vector>

//Gegnerwaves
vector<BasicEnemy*> enemyWaves(int waveNumber) {
	vector<BasicEnemy*> *enemyWaveVector = new vector<BasicEnemy*>();

	
	
	if (waveNumber == 1) 
	{

		BasicEnemy *numberOne = new WeakestEnemy();
		BasicEnemy *numberTwo = new WeakestEnemy();
		BasicEnemy *numberThree = new WeakestEnemy();
		BasicEnemy *numberFour = new WeakestEnemy();
		BasicEnemy *numberFive = new WeakestEnemy();
		BasicEnemy *numberSix = new WeakestEnemy();
		BasicEnemy *numberSeven = new WeakestEnemy();
		BasicEnemy *numberEight = new StrongEnemy();

		enemyWaveVector->push_back(numberOne);
		enemyWaveVector->push_back(numberTwo);
		enemyWaveVector->push_back(numberThree);
		enemyWaveVector->push_back(numberFour);
		enemyWaveVector->push_back(numberFive);
		enemyWaveVector->push_back(numberSix);
		enemyWaveVector->push_back(numberSeven);
		enemyWaveVector->push_back(numberEight);
	}

	if (waveNumber == 2)
	{
		BasicEnemy *numberOne = new WeakerEnemy();
		BasicEnemy *numberTwo = new WeakerEnemy();
		BasicEnemy *numberThree = new WeakerEnemy();
		BasicEnemy *numberFour = new WeakerEnemy();
		BasicEnemy *numberFive = new WeakerEnemy();
		BasicEnemy *numberSix = new StrongEnemy();
		BasicEnemy *numberSeven = new StrongEnemy();

		enemyWaveVector->push_back(numberOne);
		enemyWaveVector->push_back(numberTwo);
		enemyWaveVector->push_back(numberThree);
		enemyWaveVector->push_back(numberFour);
		enemyWaveVector->push_back(numberFive);
		enemyWaveVector->push_back(numberSix);
		enemyWaveVector->push_back(numberSeven);
	}
		
	if (waveNumber == 3)
	{
		BasicEnemy *numberOne = new FastEnemy();
		BasicEnemy *numberTwo = new FastEnemy();
		BasicEnemy *numberThree = new FastEnemy();
		BasicEnemy *numberFour = new FastEnemy();
		BasicEnemy *numberFive = new FastEnemy();
		BasicEnemy *numberSix = new FastEnemy();
		BasicEnemy *numberSeven = new FastEnemy();

		enemyWaveVector->push_back(numberOne);
		enemyWaveVector->push_back(numberTwo);
		enemyWaveVector->push_back(numberThree);
		enemyWaveVector->push_back(numberFour);
		enemyWaveVector->push_back(numberFive);
		enemyWaveVector->push_back(numberSix);
		enemyWaveVector->push_back(numberSeven);
	}

	if (waveNumber == 4)
	{

		BasicEnemy *numberOne = new WeakEnemy();
		BasicEnemy *numberTwo = new WeakEnemy();
		BasicEnemy *numberThree = new WeakEnemy();
		BasicEnemy *numberFour = new WeakEnemy();
		BasicEnemy *numberFive = new StrongEnemy();
		BasicEnemy *numberSix = new StrongEnemy();
		BasicEnemy *numberSeven = new StrongEnemy();
		BasicEnemy *numberEight = new StrongerEnemy();

		enemyWaveVector->push_back(numberOne);
		enemyWaveVector->push_back(numberTwo);
		enemyWaveVector->push_back(numberThree);
		enemyWaveVector->push_back(numberFour);
		enemyWaveVector->push_back(numberFive);
		enemyWaveVector->push_back(numberSix);
		enemyWaveVector->push_back(numberSeven);
		enemyWaveVector->push_back(numberEight);
	}

	if (waveNumber == 5)
	{

		BasicEnemy *numberOne = new WeakEnemy();
		BasicEnemy *numberTwo = new WeakEnemy();
		BasicEnemy *numberThree = new StrongEnemy();
		BasicEnemy *numberFour = new StrongEnemy();
		BasicEnemy *numberFive = new StrongEnemy();
		BasicEnemy *numberSix = new StrongEnemy();
		BasicEnemy *numberSeven = new StrongerEnemy();
		BasicEnemy *numberEight = new StrongerEnemy();

		enemyWaveVector->push_back(numberOne);
		enemyWaveVector->push_back(numberTwo);
		enemyWaveVector->push_back(numberThree);
		enemyWaveVector->push_back(numberFour);
		enemyWaveVector->push_back(numberFive);
		enemyWaveVector->push_back(numberSix);
		enemyWaveVector->push_back(numberSeven);
		enemyWaveVector->push_back(numberEight);
	}

	if (waveNumber == 6)
	{

		BasicEnemy *numberOne = new FastEnemy();
		BasicEnemy *numberTwo = new FastEnemy();
		BasicEnemy *numberThree = new FastEnemy();
		BasicEnemy *numberFour = new FastEnemy();
		BasicEnemy *numberFive = new FastEnemy();
		BasicEnemy *numberSix = new FastEnemy();
		BasicEnemy *numberSeven = new FastEnemy();
		BasicEnemy *numberEight = new FastEnemy();
		BasicEnemy *numberNine = new FastEnemy();
		BasicEnemy *numberTen = new FastEnemy();
		BasicEnemy *numberEleven = new FastEnemy();

		enemyWaveVector->push_back(numberOne);
		enemyWaveVector->push_back(numberTwo);
		enemyWaveVector->push_back(numberThree);
		enemyWaveVector->push_back(numberFour);
		enemyWaveVector->push_back(numberFive);
		enemyWaveVector->push_back(numberSix);
		enemyWaveVector->push_back(numberSeven);
		enemyWaveVector->push_back(numberEight);
		enemyWaveVector->push_back(numberNine);
		enemyWaveVector->push_back(numberTen);
		enemyWaveVector->push_back(numberEleven);
	}

	if (waveNumber == 7)
	{

		BasicEnemy *numberOne = new StrongEnemy();
		BasicEnemy *numberTwo = new StrongEnemy();
		BasicEnemy *numberThree = new StrongEnemy();
		BasicEnemy *numberFour = new StrongEnemy();
		BasicEnemy *numberFive = new StrongerEnemy();
		BasicEnemy *numberSix = new StrongerEnemy();
		BasicEnemy *numberSeven = new StrongerEnemy();
		BasicEnemy *numberEight = new StrongEnemy();
		BasicEnemy *numberNine = new StrongEnemy();
		BasicEnemy *numberTen = new StrongEnemy();
		BasicEnemy *numberEleven = new StrongerEnemy();

		enemyWaveVector->push_back(numberOne);
		enemyWaveVector->push_back(numberTwo);
		enemyWaveVector->push_back(numberThree);
		enemyWaveVector->push_back(numberFour);
		enemyWaveVector->push_back(numberFive);
		enemyWaveVector->push_back(numberSix);
		enemyWaveVector->push_back(numberSeven);
		enemyWaveVector->push_back(numberEight);
		enemyWaveVector->push_back(numberNine);
		enemyWaveVector->push_back(numberTen);
		enemyWaveVector->push_back(numberEleven);
	}

	if (waveNumber == 8)
	{

		BasicEnemy *numberOne = new StrongEnemy();
		BasicEnemy *numberTwo = new StrongEnemy();
		BasicEnemy *numberThree = new StrongerEnemy();
		BasicEnemy *numberFour = new StrongerEnemy();
		BasicEnemy *numberFive = new StrongerEnemy();
		BasicEnemy *numberSix = new StrongerEnemy();
		BasicEnemy *numberSeven = new StrongerEnemy();
		BasicEnemy *numberEight = new StrongEnemy();
		BasicEnemy *numberNine = new StrongEnemy();
		BasicEnemy *numberTen = new StrongestEnemy();
		BasicEnemy *numberEleven = new StrongestEnemy();

		enemyWaveVector->push_back(numberOne);
		enemyWaveVector->push_back(numberTwo);
		enemyWaveVector->push_back(numberThree);
		enemyWaveVector->push_back(numberFour);
		enemyWaveVector->push_back(numberFive);
		enemyWaveVector->push_back(numberSix);
		enemyWaveVector->push_back(numberSeven);
		enemyWaveVector->push_back(numberEight);
		enemyWaveVector->push_back(numberNine);
		enemyWaveVector->push_back(numberTen);
		enemyWaveVector->push_back(numberEleven);
	}

	if (waveNumber == 9)
	{

		BasicEnemy *numberOne = new StrongestEnemy();
		BasicEnemy *numberTwo = new StrongerEnemy();
		BasicEnemy *numberThree = new StrongestEnemy();
		BasicEnemy *numberFour = new StrongerEnemy();
		BasicEnemy *numberFive = new StrongerEnemy();
		BasicEnemy *numberSix = new StrongestEnemy();
		BasicEnemy *numberSeven = new StrongerEnemy();
		BasicEnemy *numberEight = new StrongerEnemy();
		BasicEnemy *numberNine = new StrongerEnemy();
		BasicEnemy *numberTen = new StrongestEnemy();
		BasicEnemy *numberEleven = new StrongestEnemy();

		enemyWaveVector->push_back(numberOne);
		enemyWaveVector->push_back(numberTwo);
		enemyWaveVector->push_back(numberThree);
		enemyWaveVector->push_back(numberFour);
		enemyWaveVector->push_back(numberFive);
		enemyWaveVector->push_back(numberSix);
		enemyWaveVector->push_back(numberSeven);
		enemyWaveVector->push_back(numberEight);
		enemyWaveVector->push_back(numberNine);
		enemyWaveVector->push_back(numberTen);
		enemyWaveVector->push_back(numberEleven);
	}

	if (waveNumber == 10)
	{

		BasicEnemy *numberOne = new BossEnemy();
		
		enemyWaveVector->push_back(numberOne);
		
	}
	return *enemyWaveVector;
}