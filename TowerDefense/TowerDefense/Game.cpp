#include "Game.h"
#include <list>
#include <vector>
#include "PlayingField.cpp"
#include "BasicTower.h"
#include "EnemyWaves.h"



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
	
	int gameTime = 0;

	vector<DummyEnemy*> *enemyVector = new vector<DummyEnemy*>(); 
	vector<DummyEnemy*> *enemyActiveVector = new vector<DummyEnemy*>();
	*enemyVector = enemyWaves(1);

	int gameTimeEnemyCounter = 1;
	int waveEnemyAddedCounter = 0;
	
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
	vector<BasicTower*> *TowerVector = new vector<BasicTower*>();

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

		//schickt die gegner aus wave1 auf die reise
		//hier ist noch was madig
		sf::Time elapsed1 = clock.getElapsedTime();
		gameTime = elapsed1.asSeconds();
		if (gameTime > gameTimeEnemyCounter && gameTime < (enemyVector->size())+2) {
			enemyActiveVector->push_back(enemyVector->at(waveEnemyAddedCounter));
			gameTimeEnemyCounter = (gameTimeEnemyCounter + 1);
			waveEnemyAddedCounter = (waveEnemyAddedCounter + 1);
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
					BasicTower *Tower = new BasicTower(((*pos)->getAreaXCoord()), (*pos)->getAreaYCoord());
					TowerVector->push_back(Tower);
					(*pos)->setAreaEmpty(false);
				}
			}
		}
		 
		//Tower malen
		for (unsigned int i = 0; i < TowerVector->size(); i++) {
			*enemyActiveVector = TowerVector->at(i)->checkForEnemies(enemyActiveVector);
			App.draw(TowerVector->at(i)->getSprite());
		}
			
		//testgegner bewegungskram
		for (unsigned int i = 0; i < enemyActiveVector->size(); i++) {
			x = enemyActiveVector->at(i)->getXCoord();
			y = enemyActiveVector->at(i)->getYCoord();
			int lifePercent = (enemyActiveVector->at(i)->getCurrentLife() / enemyActiveVector->at(i)->getMaxLife() * 100);
			if (lifePercent > 90) {
				lifeEnemySprite.setTexture(hundredLifeTexture);
			}
			else if (90 > lifePercent && lifePercent > 70) {
				lifeEnemySprite.setTexture(eightyLifeTexture);
			}
			else if (70 > lifePercent && lifePercent > 50) {
				lifeEnemySprite.setTexture(sixtyLifeTexture);
			}
			else if (50 > lifePercent && lifePercent > 30) {
				lifeEnemySprite.setTexture(fortyLifeTexture);
			}
			else if (30 > lifePercent && lifePercent > 10) {
				lifeEnemySprite.setTexture(twentyLifeTexture);
			}
			else if (lifePercent < 10) {
				lifeEnemySprite.setTexture(tenLifeTexture);
			}
			enemyActiveVector->at(i)->eSetPosition();
			if (y > 191 && x < 447 && (enemyActiveVector->at(i)->getCurrentLife()) > 0) {
				enemyActiveVector->at(i)->eSetRotation(270);
				lifeEnemySprite.setPosition(x, (y - 25));
				App.draw(enemyActiveVector->at(i)->getSprite());
				App.draw(lifeEnemySprite);
				(enemyActiveVector->at(i)->eSetXCoord((x + 2)));
			}
			if (y <= 191 && (enemyActiveVector->at(i)->getCurrentLife() > 0)) {
				lifeEnemySprite.setPosition(x, (y - 25));
				App.draw((enemyActiveVector->at(i)->getSprite()));
				App.draw(lifeEnemySprite);
				(enemyActiveVector->at(i)->eSetYCoord((y + 2)));
			}
			if (x >= 447 && y <= 738 && (enemyActiveVector->at(i)->getCurrentLife() > 0)) {
				(enemyActiveVector->at(i)->eSetRotation(0));
				lifeEnemySprite.setPosition(x, (y - 25));
				App.draw((enemyActiveVector->at(i)->getSprite()));
				App.draw(lifeEnemySprite);
				(enemyActiveVector->at(i)->eSetYCoord((y + 2)));
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


