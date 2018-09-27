#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu
{
public:
	Menu();
	~Menu();

	void Run();
	void LoadMenuTextures(sf::Texture &menuBackgroundTexture, sf::Sprite &menuBackgroundSprite);
	bool isRunning();

private:
	sf::RenderWindow MenuWindow;

	bool running;
	std::string name;

};
#endif