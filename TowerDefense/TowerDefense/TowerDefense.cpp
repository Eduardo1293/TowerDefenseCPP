#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int test() {
	{
		sf::RenderWindow window(sf::VideoMode(512, 960), "Lennard is kacke");

		//vertical sync gegen screen tearing
		window.setVerticalSyncEnabled(true);

		//Background
		window.clear();
		sf::Texture texture;
		texture.loadFromFile("background.png");
		sf::Sprite sprite;
		sprite.setTexture(texture);
		window.draw(sprite);

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
		}
		//Hic sunt dracones

		return 0;
	}
}