#include "Game.h"
#include <list>
#include <vector>
#include "PlayingField.h"



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
	
	/*for each (PropertyInfo prop in typeof(PlayingField))
	{
		this.playingFieldList.Add(prop)
	}*/


	
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
		sf::Texture backgroundTexture;
		backgroundTexture.loadFromFile("ArtAssets/background.png");
		sf::Sprite backgroundSprite;
		backgroundSprite.setTexture(backgroundTexture);
		backgroundSprite.setPosition(0, 64);
		App.draw(backgroundSprite);

		//Testturm und Testgegner, testgegner ist hardgecodet, dass er einen bestimmten weg abfährt
		sf::Texture testTurmTexture;
		testTurmTexture.loadFromFile("ArtAssets/Tower/tank_dark.png");
		sf::Sprite testTurmSprite;
		sf::Sprite testEnemySprite;
		testEnemySprite.setTexture(testTurmTexture);
		//testEnemySprite.scale(0.695f, 0.762f);

		//test markierungen

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

		//halbdurchsichtiger tower zum bauen
		sf::Sprite buildTowerSprite;
		buildTowerSprite.setTexture(testTurmTexture);
		buildTowerSprite.setColor(sf::Color(255, 255, 255, 140));
		buildTowerSprite.setOrigin(32, 32);

		list<GameArea*> GameAreaList = PlayingField();

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
		}

		//testgegner bewegungskram
		testEnemySprite.setOrigin(32, 32);
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

		//testtürme statisch
		//testTurmSprite.scale(0.695f, 0.762f);
		testTurmSprite.setTexture(testTurmTexture);
		testTurmSprite.setOrigin(32, 32);
		testTurmSprite.setPosition(63, 255);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(127, 255);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(191, 255);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(255, 255);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(319, 255);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(383, 255);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(235, 361);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(235, 489);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(235, 617);
		App.draw(testTurmSprite);
		//window.draw(testTurmSprite);
		// end the current frame
		App.display();
	}
}

bool Game::isRunning()
{
	return running;
}


