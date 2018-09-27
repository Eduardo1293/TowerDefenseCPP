#include "Menu.h"
#include "Game.h"
#include "BasicButton.h";

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
	string TexturePath = "ArtAssets/Menu/MenuButton.png";
	sf::Texture menuBackgroundTexture;
	sf::Sprite menuBackgroundSprite;

	sf::Color color;

	BasicButton StartButton = BasicButton(50, 25, "START", TexturePath, color.White, 38,0,0);
	BasicButton BestenlisteButton = BasicButton(50, 120, "BESTENLISTE", TexturePath, color.White, 38, 45, 95);
	BasicButton CreditsButton = BasicButton(50, 215, "CREDITS", TexturePath, color.White, 38,10,190);
	BasicButton ExitButton = BasicButton(50, 310, "EXIT", TexturePath, color.White, 38, -20,285);
	BasicButton ZurückButton = BasicButton(50, 320, "BACK", TexturePath, color.White, 38, -10, 295);

	

	LoadMenuTextures(menuBackgroundTexture, menuBackgroundSprite);



	sf::Text Credits;


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
		
		MenuWindow.clear(sf::Color::Black);
		
		MenuWindow.draw(menuBackgroundSprite);

		if (!showCredits)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (StartButton.getSprite().getGlobalBounds().contains(mousePosF))
				{
					MenuWindow.close();
					Game game;
					while (game.isRunning())
					{
						game.Run();

					}
					running = false;
				}
				if (BestenlisteButton.getSprite().getGlobalBounds().contains(mousePosF))
				{
					//Öffnet die Bestenliste
				}
				if (CreditsButton.getSprite().getGlobalBounds().contains(mousePosF))
				{
					MenuWindow.clear(sf::Color::Black);
					showButtons = false;
					showCredits = true;

				}
				if (ExitButton.getSprite().getGlobalBounds().contains(mousePosF))
				{
					MenuWindow.close();
					running = false;
				}
			}
			MenuWindow.draw(StartButton.getSprite());
			MenuWindow.draw(BestenlisteButton.getSprite());
			MenuWindow.draw(CreditsButton.getSprite());
			MenuWindow.draw(ExitButton.getSprite());

			MenuWindow.draw(StartButton.getButtonText());
			MenuWindow.draw(BestenlisteButton.getButtonText());
			MenuWindow.draw(CreditsButton.getButtonText());
			MenuWindow.draw(ExitButton.getButtonText());
		}
		else
		{
			menuBackgroundTexture.loadFromFile("ArtAssets/Menu/Credits.png");
			menuBackgroundSprite.setTexture(menuBackgroundTexture);
			MenuWindow.draw(ZurückButton.getSprite()); 
			MenuWindow.draw(ZurückButton.getButtonText());
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (ZurückButton.getSprite().getGlobalBounds().contains(mousePosF))
				{
					showCredits = false;
				}
			}
		}
		MenuWindow.display();



	}
}


void Menu::LoadMenuTextures(sf::Texture &menuBackgroundTexture,	sf::Sprite &menuBackgroundSprite)
{
	menuBackgroundTexture.loadFromFile("ArtAssets/Menu/Nebula Blue.png");
	menuBackgroundSprite.setTexture(menuBackgroundTexture);
	menuBackgroundSprite.setPosition(0, 0);
}


bool Menu::isRunning()
{
	return running;
}
