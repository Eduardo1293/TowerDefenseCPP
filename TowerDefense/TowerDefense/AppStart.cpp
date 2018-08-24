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
	sf::RenderWindow window(sf::VideoMode(512, 960), "Lennard is kacke");

	//vertical sync gegen screen tearing
	window.setVerticalSyncEnabled(true);
	int x = 43;
	int y = 0;

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
		window.draw(backgroundSprite);

		//Testturm und Testgegner, testgegner ist hardgecodet, dass er einen bestimmten weg abfährt
		sf::Texture testTurmTexture;
		testTurmTexture.loadFromFile("ArtAssets/tank_dark.png");
		sf::Sprite testTurmSprite;
		sf::Sprite testEnemySprite;
		testEnemySprite.setTexture(testTurmTexture);
		testEnemySprite.scale(0.5f, 0.5f);
		//testgegner bewegungskram
		if (y > 109 && y < 151 && x < 424) {
			testEnemySprite.setRotation(270);
		}
		if (y <= 109) {
			y++;
		}
		else if (y > 109 && x < 424) {
			y = 150;
			x++;
		} 
		else if (x = 424) {
			testEnemySprite.setRotation(0);
			y = 110;
			x++;
		}
		if (x > 400) {
			y++;
		}
		testEnemySprite.setPosition(x, y);
		window.draw(testEnemySprite);

		//testtürme statisch
		testTurmSprite.scale(0.5f, 0.5f);
		testTurmSprite.setTexture(testTurmTexture);
		testTurmSprite.setPosition(43, 169);
		window.draw(testTurmSprite);
		testTurmSprite.setPosition(107, 169);
		window.draw(testTurmSprite);
		testTurmSprite.setPosition(171, 169);
		window.draw(testTurmSprite);
		testTurmSprite.setPosition(235, 169);
		window.draw(testTurmSprite);
		testTurmSprite.setPosition(299, 169);
		window.draw(testTurmSprite);
		testTurmSprite.setPosition(363, 169);
		window.draw(testTurmSprite);
		testTurmSprite.setPosition(235, 297);
		window.draw(testTurmSprite);
		testTurmSprite.setPosition(235, 425);
		window.draw(testTurmSprite);
		testTurmSprite.setPosition(235, 553);
		window.draw(testTurmSprite);
		//window.draw(testTurmSprite);
		// end the current frame
		window.display();
	}
}
