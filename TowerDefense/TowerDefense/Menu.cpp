#include "Menu.h"
#include "Game.h"

#include <iostream>

Menu::Menu()
{
	name = "Tower Defense - Beats by Dad";
	MenuWindow.create(sf::VideoMode(400, 400), name, sf::Style::Close);
	running = true;
}

Menu::~Menu()
{
}

void Menu::Run()
{

	sf::Texture menuBackgroundTexture;
	menuBackgroundTexture.loadFromFile("ArtAssets/Menu/Nebula Blue.png");
	sf::Sprite menuBackgroundSprite;
	menuBackgroundSprite.setTexture(menuBackgroundTexture);
	menuBackgroundSprite.setPosition(0, 0);
	menuBackgroundSprite.scale(0.1, 0.1);

	sf::Texture MenuButton;
	MenuButton.loadFromFile("ArtAssets/Menu/MenuButton.png");

	sf::Sprite StartButtonSprite;
	StartButtonSprite.setPosition(50, 25);
	StartButtonSprite.setTexture(MenuButton);

	sf::Sprite BestenlisteButtonSprite;
	BestenlisteButtonSprite.setPosition(50, 120);
	BestenlisteButtonSprite.setTexture(MenuButton);

	sf::Sprite CreditsButtonSprite;
	CreditsButtonSprite.setPosition(50, 215);
	CreditsButtonSprite.setTexture(MenuButton);

	sf::Sprite ExitButtonSprite;
	ExitButtonSprite.setPosition(50, 310);
	ExitButtonSprite.setTexture(MenuButton);

	sf::Font font;
	if (!font.loadFromFile("ArtAssets/impact.ttf"))
	{
		std::cout << "Es konnte keine Fontdatei geunden werden!" << std::endl;
	}
	sf::Color color;


	sf::Text Credits;
	Credits.setFont(font);
	Credits.setString("Hier Credtis einfügen!");
	Credits.setFillColor(color.White);
	Credits.setCharacterSize(19);
	Credits.setPosition(50, 200);

	float StartButtonWidth = StartButtonSprite.getLocalBounds().width;
	float StartButtonHeight = StartButtonSprite.getLocalBounds().height;

	float BestenlisteButtonWidth = BestenlisteButtonSprite.getLocalBounds().width;
	float BestenlisteButtonHeight = BestenlisteButtonSprite.getLocalBounds().height;

	float CreditsButtonWidth = CreditsButtonSprite.getLocalBounds().width;
	float CreditsButtonHeight = CreditsButtonSprite.getLocalBounds().height;

	float ExitButtonWidth = ExitButtonSprite.getLocalBounds().width;
	float ExitButtonHeight = ExitButtonSprite.getLocalBounds().height;
	bool showButtons = true;
	bool showCredits = false;

	MenuWindow.setFramerateLimit(24);
	while (MenuWindow.isOpen())
	{
		
		sf::Event event;
		

		while (MenuWindow.pollEvent(event))
		{
			switch (event.type)
			{

			case sf::Event::Closed :
				MenuWindow.close();
				running = false;
				break;				
			}
				
		}




		sf::Vector2i localPosition = sf::Mouse::getPosition(MenuWindow);
		sf::Vector2f mousePosF(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y));



		setButtonColor(StartButtonSprite, mousePosF, MenuButton, color, BestenlisteButtonSprite, CreditsButtonSprite, ExitButtonSprite);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
		{
			if (StartButtonSprite.getGlobalBounds().contains(mousePosF))
			{
				MenuWindow.close();
				Game game;
				while (game.isRunning())
				{
					game.Run();					

				}
			}
			if (BestenlisteButtonSprite.getGlobalBounds().contains(mousePosF))
			{
				//Öffnet die Bestenliste
			}
			if (CreditsButtonSprite.getGlobalBounds().contains(mousePosF))
			{
				MenuWindow.clear(sf::Color::Black);
				showButtons = false;
				showCredits = true;
				
			}
			if (ExitButtonSprite.getGlobalBounds().contains(mousePosF))
			{
				MenuWindow.close();
				running = false;
			}
		}

		MenuWindow.clear(sf::Color::Black);

		MenuWindow.draw(menuBackgroundSprite);
		ShowButtons(showButtons, menuBackgroundSprite, StartButtonSprite, BestenlisteButtonSprite, CreditsButtonSprite, ExitButtonSprite);
		ShowCredits(showCredits, Credits);
		
		MenuWindow.display();



	}
}

void Menu::ShowCredits(bool show, sf::Text Credits)
{
	if (show)
	{
		MenuWindow.draw(Credits);
	}
}

void Menu::ShowButtons(bool show, sf::Sprite &menuBackgroundSprite, sf::Sprite &StartButtonSprite, sf::Sprite &BestenlisteButtonSprite, sf::Sprite &CreditsButtonSprite, sf::Sprite &ExitButtonSprite)
{
	if (show)
	{		
		MenuWindow.draw(StartButtonSprite);
		MenuWindow.draw(BestenlisteButtonSprite);
		MenuWindow.draw(CreditsButtonSprite);
		MenuWindow.draw(ExitButtonSprite);
	}

}

void Menu::setButtonColor(sf::Sprite &StartButtonSprite, sf::Vector2f &mousePosF, sf::Texture &MenuButton, sf::Color &color, sf::Sprite &BestenlisteButtonSprite, sf::Sprite &CreditsButtonSprite, sf::Sprite &ExitButtonSprite)
{
	if (StartButtonSprite.getGlobalBounds().contains(mousePosF))
	{
		StartButtonSprite.setColor(sf::Color(255, 255, 255, 140));
	}
	else
	{
		StartButtonSprite.setTexture(MenuButton);
		StartButtonSprite.setColor(color.White);
	}

	if (BestenlisteButtonSprite.getGlobalBounds().contains(mousePosF))
	{
		BestenlisteButtonSprite.setColor(sf::Color(255, 255, 255, 140));
	}
	else
	{
		BestenlisteButtonSprite.setTexture(MenuButton);
		BestenlisteButtonSprite.setColor(color.White);
	}

	if (CreditsButtonSprite.getGlobalBounds().contains(mousePosF))
	{
		CreditsButtonSprite.setColor(sf::Color(255, 255, 255, 140));
	}
	else
	{
		CreditsButtonSprite.setTexture(MenuButton);
		CreditsButtonSprite.setColor(color.White);
	}

	if (ExitButtonSprite.getGlobalBounds().contains(mousePosF))
	{
		ExitButtonSprite.setColor(sf::Color(255, 255, 255, 140));
	}
	else
	{
		ExitButtonSprite.setTexture(MenuButton);
		ExitButtonSprite.setColor(color.White);
	}
}

bool Menu::isRunning()
{
	return running;
}
