#include "Game.h"
#include <list>
#include <vector>
#include "PlayingField.cpp"



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
	App.setFramerateLimit(24);
	int x = 63;
	int y = 96;

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
			
			if (y > 191 && x < 447) {
				testEnemySprite.setRotation(270);
				testEnemySprite.setPosition(x, y);
				App.draw(testEnemySprite);
				x = x + 2;
			}
			if (y <= 191) {
				testEnemySprite.setPosition(x, y);
				App.draw(testEnemySprite);
				y = y + 2;
			}
			if (x >= 447 && y <= 600) {
				testEnemySprite.setRotation(0);
				testEnemySprite.setPosition(x, y);
				App.draw(testEnemySprite);
				y = y + 2;
			}

			// end the current frame
			App.display();
	}
}


bool Game::isRunning()
{
	return running;
}


