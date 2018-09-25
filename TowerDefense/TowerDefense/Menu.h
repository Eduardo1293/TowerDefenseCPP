#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu
{
public:
	Menu();
	~Menu();

	void Run();
	void LoadMenuFont(sf::Font &font);
	void LoadMenuTextures(sf::Texture &menuBackgroundTexture, sf::Sprite &menuBackgroundSprite,
		sf::Texture &MenuButton, sf::Sprite &StartButtonSprite, sf::Sprite &BestenlisteButtonSprite,
		sf::Sprite &CreditsButtonSprite, sf::Sprite &ExitButtonSprite);
	void SetCreditButtonText(sf::Text &Credits, sf::Font &font, sf::Color &color);
	void SetStartButtonText(sf::Text &StartButtonText, sf::Font &font, sf::Color &color, float StartButtonWidth, float StartButtonHeight);
	void SetBestenListeButtonText(sf::Text &BestenListeButtonText, sf::Font &font, sf::Color &color,
		float BestenlisteButtonWidth, float BestenlisteButtonHeight);
	void SetCreditButtonText(sf::Text &CreditsButtonText, sf::Font &font, sf::Color &color, float CreditsButtonWidth, float CreditsButtonHeight);
	void SetExitButtonText(sf::Text &ExitButtonText, sf::Font &font, sf::Color &color, float ExitButtonWidth);
	void ShowCredits(bool show, sf::Text Credits);
	void ShowButtons(bool showButtons,sf::Sprite &menuBackgroundSprite,
		sf::Sprite &StartButtonSprite, sf::Sprite &BestenlisteButtonSprite,
		sf::Sprite &CreditsButtonSprite, sf::Sprite &ExitButtonSprite,
		sf::Text &StartButtonText, sf::Text &BestenListeButtonText,
		sf::Text &CreditsButtonText, sf::Text &ExitButtonText);
	void setButtonColor(sf::Sprite &StartButtonSprite, sf::Vector2f &mousePosF,
		sf::Texture &MenuButton, sf::Color &color,
		sf::Sprite &BestenlisteButtonSprite, sf::Sprite &CreditsButtonSprite,
		sf::Sprite &ExitButtonSprite);
	bool isRunning();

private:
	sf::RenderWindow MenuWindow;

	bool running;
	std::string name;

};
#endif