#include "Game.h"

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
	App.setVerticalSyncEnabled(true);
	int x = 43;
	int y = 64;

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
		testTurmTexture.loadFromFile("ArtAssets/tank_dark.png");
		sf::Sprite testTurmSprite;
		sf::Sprite testEnemySprite;
		testEnemySprite.setTexture(testTurmTexture);
		testEnemySprite.scale(0.695f, 0.762f);

		//test markierungen

		sf::Texture emptySpaceTexture;
		sf::Texture blockedSpaceTexture;
		emptySpaceTexture.loadFromFile("ArtAssets/emptyspace.png");
		blockedSpaceTexture.loadFromFile("ArtAssets/blockedspace.png");

		sf::Sprite emptySpaceSprite;
		sf::Sprite blockedSpaceSprite;
		emptySpaceSprite.setTexture(emptySpaceTexture);
		emptySpaceSprite.setColor(sf::Color(255, 255, 255, 128));
		blockedSpaceSprite.setTexture(blockedSpaceTexture);
		blockedSpaceSprite.setColor(sf::Color(255, 255, 255, 128));

		emptySpaceSprite.setPosition(33, 224);
		App.draw(emptySpaceSprite);

		emptySpaceSprite.setPosition(97, 224);
		App.draw(emptySpaceSprite);

		emptySpaceSprite.setPosition(161, 224);
		App.draw(emptySpaceSprite);

		blockedSpaceSprite.setPosition(33, 160);
		App.draw(blockedSpaceSprite);

		blockedSpaceSprite.setPosition(97, 160);
		App.draw(blockedSpaceSprite);

		blockedSpaceSprite.setPosition(161, 160);
		App.draw(blockedSpaceSprite);

		//testgegner bewegungskram
		if (y > 173 && y < 215 && x < 424) {
			testEnemySprite.setRotation(270);
		}
		if (y <= 173) {
			y++;
		}
		else if (y > 173 && x < 424) {
			y = 214;
			x++;
		}
		else if (x = 424) {
			testEnemySprite.setRotation(0);
			y = 174;
			x++;
		}
		if (x > 400) {
			y++;
		}
		testEnemySprite.setPosition(x, y);
		App.draw(testEnemySprite);

		//testtürme statisch
		testTurmSprite.scale(0.695f, 0.762f);
		testTurmSprite.setTexture(testTurmTexture);
		testTurmSprite.setPosition(43, 233);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(107, 233);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(171, 233);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(235, 233);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(299, 233);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(363, 233);
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
