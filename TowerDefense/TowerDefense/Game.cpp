#include "Game.h"
#include <list>
#include <vector>
#include "PlayingField.cpp"
#include "BasicTower.h"
#include "DummyEnemy.h"



Game::Game()
{
	name = "Lennard is kacke.exe";
	App.create(sf::VideoMode(512, 896), name, sf::Style::Close);
	running = true;

}

Game::~Game()
{
}

void Game::Run()
{
	sf::Clock clock;
	App.setFramerateLimit(24);
	int x;
	int y;
	DummyEnemy *numberOne = new DummyEnemy(63, 96);
	
	/*DummyEnemy *numberThree = new DummyEnemy(63, 96);
	DummyEnemy *numberFour = new DummyEnemy(63, 96);
	DummyEnemy *numberFive = new DummyEnemy(63, 96);
	DummyEnemy *numberSix = new DummyEnemy(63, 96);
	DummyEnemy *numberSeven = new DummyEnemy(63, 96);*/

	bool enemyTwoAdded = false;
	int gameTime = 0;

	list<DummyEnemy*> EnemyList;

	EnemyList.push_back(numberOne);
	
	/*EnemyList.push_back(numberThree);
	EnemyList.push_back(numberFour);
	EnemyList.push_back(numberFive);
	EnemyList.push_back(numberSix);
	EnemyList.push_back(numberSeven); */

	//Testturm und Testgegner, testgegner ist hardgecodet, dass er einen bestimmten weg abfährt
	sf::Texture testTurmTexture;
	testTurmTexture.loadFromFile("ArtAssets/Tower/tank_dark.png");
	sf::Sprite testTurmSprite;
	sf::Sprite testEnemySprite;
	testEnemySprite.setTexture(testTurmTexture);

	//halbdurchsichtiger tower zum bauen
	sf::Sprite buildTowerSprite;
	buildTowerSprite.setTexture(testTurmTexture);
	buildTowerSprite.setColor(sf::Color(255, 255, 255, 140));
	buildTowerSprite.setOrigin(32, 32);

	//lifebar
	sf::Texture hundredLifeTexture;
	hundredLifeTexture.loadFromFile("ArtAssets/Lifebar/100percent.png");
	sf::Texture ninetyLifeTexture;
	ninetyLifeTexture.loadFromFile("ArtAssets/Lifebar/90percent.png");
	sf::Texture eightyLifeTexture;
	eightyLifeTexture.loadFromFile("ArtAssets/Lifebar/80percent.png");
	sf::Texture seventyLifeTexture;
	seventyLifeTexture.loadFromFile("ArtAssets/Lifebar/70percent.png");
	sf::Texture sixtyLifeTexture;
	sixtyLifeTexture.loadFromFile("ArtAssets/Lifebar/60percent.png");
	sf::Texture fiftyLifeTexture;
	fiftyLifeTexture.loadFromFile("ArtAssets/Lifebar/50percent.png");
	sf::Texture fortyLifeTexture;
	fortyLifeTexture.loadFromFile("ArtAssets/Lifebar/40percent.png");
	sf::Texture thirtyLifeTexture;
	thirtyLifeTexture.loadFromFile("ArtAssets/Lifebar/30percent.png");
	sf::Texture twentyLifeTexture;
	twentyLifeTexture.loadFromFile("ArtAssets/Lifebar/20percent.png");
	sf::Texture tenLifeTexture;
	tenLifeTexture.loadFromFile("ArtAssets/Lifebar/10percent.png");
	sf::Sprite lifeEnemySprite;
	lifeEnemySprite.setTexture(fiftyLifeTexture);
	lifeEnemySprite.setOrigin(20, 2);

	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("ArtAssets/background.png");
	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(0, 64);

	testTurmSprite.setTexture(testTurmTexture);
	testTurmSprite.setOrigin(32, 32);

	sf::Texture emptySpaceTexture;
	sf::Texture blockedSpaceTexture;
	emptySpaceTexture.loadFromFile("ArtAssets/emptyspace.png");
	blockedSpaceTexture.loadFromFile("ArtAssets/blockedspace.png");

	sf::Sprite emptySpaceSprite;
	sf::Sprite blockedSpaceSprite;
	emptySpaceSprite.setTexture(emptySpaceTexture);
	emptySpaceSprite.setColor(sf::Color(255, 255, 255, 128));
	emptySpaceSprite.setOrigin(32, 32);
	blockedSpaceSprite.setTexture(blockedSpaceTexture);
	blockedSpaceSprite.setColor(sf::Color(255, 255, 255, 128));
	blockedSpaceSprite.setOrigin(32, 32);

	testEnemySprite.setOrigin(32, 32);

	/*for each (PropertyInfo prop in typeof(PlayingField))
	{
		this.playingFieldList.Add(prop)
	}*/

	list<GameArea*> GameAreaList = PlayingField();
	list<GameArea*> TowerList;

	// run the program as long as the window is open
	while (App.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (App.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				App.close();
		}

		// clear the window with black color
		App.clear(sf::Color::Black);

		
		//testcode zweiter gegner
		sf::Time elapsed1 = clock.getElapsedTime();
		gameTime = elapsed1.asSeconds();
		if ((gameTime > 1) && (enemyTwoAdded == false)) {
			DummyEnemy *numberTwo = new DummyEnemy(63, 96);
			EnemyList.push_back(numberTwo);
			enemyTwoAdded = true;
		}
		

		// draw everything here...
		// window.draw(...);
		//Background

		App.draw(backgroundSprite);

		sf::Vector2i localPosition = sf::Mouse::getPosition(App);

		for (list<GameArea*>::const_iterator pos = GameAreaList.begin(); pos != GameAreaList.end(); ++pos) {
			if ((*pos)->getEmpty()) {
				emptySpaceSprite.setPosition((*pos)->getAreaXCoord(), (*pos)->getAreaYCoord());
				App.draw(emptySpaceSprite);
			}
			else {
				blockedSpaceSprite.setPosition((*pos)->getAreaXCoord(), (*pos)->getAreaYCoord());
				App.draw(blockedSpaceSprite);
			}

			//mouse-movement auslesen
			if (localPosition.x <= ((*pos)->getAreaXCoord() + 32) && (localPosition.x >= ((*pos)->getAreaXCoord() - 31))
				&& (localPosition.y <= ((*pos)->getAreaYCoord() + 32)) && (localPosition.y >= ((*pos)->getAreaYCoord() - 31))) {
				buildTowerSprite.setPosition((*pos)->getAreaXCoord(), (*pos)->getAreaYCoord());
				App.draw(buildTowerSprite);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (localPosition.x <= ((*pos)->getAreaXCoord() + 32) && (localPosition.x >= ((*pos)->getAreaXCoord() - 31))
					&& (localPosition.y <= ((*pos)->getAreaYCoord() + 32)) && (localPosition.y >= ((*pos)->getAreaYCoord() - 31))) {
					TowerList.push_back(*pos);
					(*pos)->setAreaEmpty(false);
				}
			}
		}
		 
		//Tower malen
		for (list<GameArea*>::const_iterator pos = TowerList.begin(); pos != TowerList.end(); ++pos) {
			testTurmSprite.setPosition((*pos)->getAreaXCoord(), (*pos)->getAreaYCoord());
			App.draw(testTurmSprite);
		}
			
		//testgegner bewegungskram
		for (list<DummyEnemy*>::const_iterator pos = EnemyList.begin(); pos != EnemyList.end(); ++pos) {
			x = ((*pos)->getXCoord());
			y = ((*pos)->getYCoord());
			((*pos)->eSetPosition());
			if (y > 191 && x < 447) {
				((*pos)->eSetRotation(270));
				lifeEnemySprite.setPosition(x, (y - 40));
				App.draw(((*pos)->getSprite()));
				App.draw(lifeEnemySprite);
				((*pos)->eSetXCoord((x + 2)));
			}
			if (y <= 191) {
				lifeEnemySprite.setPosition(x, (y - 40));
				App.draw(((*pos)->getSprite()));
				App.draw(lifeEnemySprite);
				((*pos)->eSetYCoord((y + 2)));
			}
			if (x >= 447 && y <= 600) {
				((*pos)->eSetRotation(0));
				lifeEnemySprite.setPosition(x, (y - 40));
				App.draw(((*pos)->getSprite()));
				App.draw(lifeEnemySprite);
				((*pos)->eSetYCoord((y + 2)));
			}
		}
		

			// end the current frame
			App.display();

	}
}


bool Game::isRunning()
{
	return running;
}


