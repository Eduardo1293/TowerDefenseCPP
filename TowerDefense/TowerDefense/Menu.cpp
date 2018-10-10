#include "Menu.h"
#include "Game.h"
#include "BasicButton.h";
#include "GameMap.h"
#include <iostream>

Menu::Menu()
{
	sf::Image GameIcon;
	GameIcon.loadFromFile("ArtAssets/gameIcon.png");
	name = "Space Defender";
	MenuWindow.create(sf::VideoMode(400, 400), name, sf::Style::Close);
	MenuWindow.setIcon(GameIcon.getSize().x, GameIcon.getSize().y, GameIcon.getPixelsPtr());
	running = true;
}

Menu::~Menu()
{
}

void Menu::Run()
{
	int gameVolume = 3;
	string TexturePath = "ArtAssets/Menu/MenuButton.png";
	sf::Texture menuBackgroundTexture;
	sf::Sprite menuBackgroundSprite;

	sf::Color color;
	sf::Color hoverColer = sf::Color(255, 255, 255, 140);

	BasicButton StartButton = BasicButton(50, 25, "START", TexturePath, color.White, 38, 0, 0);
	BasicButton AnleitungsButton = BasicButton(50, 120, "ANLEITUNG", TexturePath, color.White, 38, 38, 95);
	BasicButton CreditsButton = BasicButton(50, 215, "CREDITS", TexturePath, color.White, 38, 10, 190);
	BasicButton ExitButton = BasicButton(50, 310, "EXIT", TexturePath, color.White, 38, -20, 285);
	BasicButton ZurückButton = BasicButton(50, 320, "BACK", TexturePath, color.White, 38, -10, 295);

	sf::SoundBuffer soundBuffer;
	sf::Sound sound;

	soundBuffer.loadFromFile("ArtAssets/Audio/menuMusik.ogg");

	sound.setBuffer(soundBuffer);
	sound.setVolume(gameVolume);

	sound.setLoop(true);
	sound.play();

	LoadMenuTextures(menuBackgroundTexture, menuBackgroundSprite);



	sf::Text Credits;


	bool showButtons = true;
	bool showCredits = false;
	bool showAnleitung = false;

	MenuWindow.setFramerateLimit(24);
	
	while (MenuWindow.isOpen())
	{

		sf::Event event;


		while (MenuWindow.pollEvent(event))
		{
			switch (event.type)
			{

			case sf::Event::Closed:
				sound.stop();
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
			menuBackgroundSprite.setScale(0.1, 0.1);
			{
				if (StartButton.getSprite().getGlobalBounds().contains(mousePosF))
				{
					StartButton.setColor(hoverColer);

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						sound.stop();
						MenuWindow.close();
						Game game;
						while (game.isRunning())
						{
							game.Run();

						}
						running = false;
					}
				}
				else
				{
					StartButton.setColor(color.White);
				}

				if (AnleitungsButton.getSprite().getGlobalBounds().contains(mousePosF))
				{
					AnleitungsButton.setColor(hoverColer);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						showAnleitung = true;
						showButtons = false;
						showCredits = true;
						MenuWindow.clear(sf::Color::Black);
					}
				}
				else
				{
					AnleitungsButton.setColor(color.White);
				}
				if (CreditsButton.getSprite().getGlobalBounds().contains(mousePosF))
				{
					CreditsButton.setColor(hoverColer);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						MenuWindow.clear(sf::Color::Black);
						showButtons = false;
						showCredits = true;
					}

				}
				else
				{
					CreditsButton.setColor(color.White);
				}
				if (ExitButton.getSprite().getGlobalBounds().contains(mousePosF))
				{
					ExitButton.setColor(hoverColer);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !showCredits)
					{
						running = false;
						MenuWindow.close();
						
					}
				}
				else
				{
					ExitButton.setColor(color.White);
				}

				MenuWindow.draw(StartButton.getSprite());
				MenuWindow.draw(AnleitungsButton.getSprite());
				MenuWindow.draw(CreditsButton.getSprite());
				MenuWindow.draw(ExitButton.getSprite());

				MenuWindow.draw(StartButton.getButtonText());
				MenuWindow.draw(AnleitungsButton.getButtonText());
				MenuWindow.draw(CreditsButton.getButtonText());
				MenuWindow.draw(ExitButton.getButtonText());
			}
		}
		else
		{
			menuBackgroundSprite.setScale(1, 1);
			if (showAnleitung)
			{
				menuBackgroundTexture.loadFromFile("ArtAssets/Menu/Anleitung.png");
			}
			else
			{
				menuBackgroundTexture.loadFromFile("ArtAssets/Menu/Credits.png");
			}

			menuBackgroundSprite.setTexture(menuBackgroundTexture);
			MenuWindow.draw(ZurückButton.getSprite());
			MenuWindow.draw(ZurückButton.getButtonText());
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (ZurückButton.getSprite().getGlobalBounds().contains(mousePosF))
				{
					LoadMenuTextures(menuBackgroundTexture, menuBackgroundSprite);
					showCredits = false;
					showAnleitung = false;
				}
			}
		}
		MenuWindow.display();



		}
	}


	void Menu::LoadMenuTextures(sf::Texture &menuBackgroundTexture, sf::Sprite &menuBackgroundSprite)
	{
		menuBackgroundTexture.loadFromFile("ArtAssets/Menu/Nebula Blue.png");
		menuBackgroundSprite.setTexture(menuBackgroundTexture);
		menuBackgroundSprite.setPosition(0, 0);
		menuBackgroundSprite.setScale(0.1, 0.1);
	}


	bool Menu::isRunning()
	{
		return running;
	}
