#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu
{
public:
	Menu();
	~Menu();

	void Run();
	void ShowCredits(bool show, sf::Text Credits);
	void ShowButtons(bool showButtons,sf::Sprite &menuBackgroundSprite, sf::Sprite &StartButtonSprite, sf::Sprite &BestenlisteButtonSprite, sf::Sprite &CreditsButtonSprite, sf::Sprite &ExitButtonSprite);
	void setButtonColor(sf::Sprite &StartButtonSprite, sf::Vector2f &mousePosF, sf::Texture &MenuButton, sf::Color &color, sf::Sprite &BestenlisteButtonSprite, sf::Sprite &CreditsButtonSprite, sf::Sprite &ExitButtonSprite);
	bool isRunning();

private:
	sf::RenderWindow MenuWindow;

	bool running;
	std::string name;

};
#endif