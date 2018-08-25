#include "AppStart.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TowerDefense::AppStart form;
	Application::Run(%form);


	//SPIELFELD und WINDOW, das ist nur zu testzwecken hier
	//Muss später in eine eigene Klasse, wenn das Menü funktioniert
	sf::RenderWindow window(sf::VideoMode(512, 896), "Lennard is kacke.exe");

	//vertical sync gegen screen tearing
	window.setVerticalSyncEnabled(true);
	int x = 43;
	int y = 64;

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		// window.draw(...);
		//Background
		sf::Texture backgroundTexture;
		backgroundTexture.loadFromFile("ArtAssets/background.png");
		sf::Sprite backgroundSprite;
		backgroundSprite.setTexture(backgroundTexture);
		backgroundSprite.setPosition(0, 64);
		window.draw(backgroundSprite);

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
		window.draw(emptySpaceSprite);

		emptySpaceSprite.setPosition(97, 224);
		window.draw(emptySpaceSprite);

		emptySpaceSprite.setPosition(161, 224);
		window.draw(emptySpaceSprite);

		blockedSpaceSprite.setPosition(33, 160);
		window.draw(blockedSpaceSprite);

		blockedSpaceSprite.setPosition(97, 160);
		window.draw(blockedSpaceSprite);

		blockedSpaceSprite.setPosition(161, 160);
		window.draw(blockedSpaceSprite);

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
		window.draw(testEnemySprite);

		//testtürme statisch
		testTurmSprite.scale(0.695f, 0.762f);
		testTurmSprite.setTexture(testTurmTexture);
		testTurmSprite.setPosition(43, 233);
		window.draw(testTurmSprite);
		testTurmSprite.setPosition(107, 233);
		window.draw(testTurmSprite);
		testTurmSprite.setPosition(171, 233);
		window.draw(testTurmSprite);
		testTurmSprite.setPosition(235, 233);
		window.draw(testTurmSprite);
		testTurmSprite.setPosition(299, 233);
		window.draw(testTurmSprite);
		testTurmSprite.setPosition(363, 233);
		window.draw(testTurmSprite);
		testTurmSprite.setPosition(235, 361);
		window.draw(testTurmSprite);
		testTurmSprite.setPosition(235, 489);
		window.draw(testTurmSprite);
		testTurmSprite.setPosition(235, 617);
		window.draw(testTurmSprite);
		//window.draw(testTurmSprite);
		// end the current frame
		window.display();
	}
}
