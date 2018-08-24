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
		sf::Texture texture;
		texture.loadFromFile("background.png");
		sf::Sprite sprite;
		sprite.setTexture(texture);
		window.draw(sprite);
		// end the current frame
		window.display();
	}
}
