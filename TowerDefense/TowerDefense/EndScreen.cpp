/*
-----SPACE DEFENDER-----

Stefan Reso
Johannes Schmidt
Andre Jelonek       259031
*/

#include "EndScreen.h"
#include "BasicButton.h"
#include "Menu.h"
#include <iostream>

EndScreen::EndScreen()
{
	sf::Image GameIcon;
	GameIcon.loadFromFile("ArtAssets/gameIcon.png");
	name = "Space Defender";
	Window.create(sf::VideoMode(600, 600), name, sf::Style::Close);
	Window.setIcon(GameIcon.getSize().x, GameIcon.getSize().y, GameIcon.getPixelsPtr());
	running = true;
}

EndScreen::~EndScreen()
{
}

//Läd die Lebensanzeige Texturen
void EndScreen::LoadGameFont(sf::Font &font)
{
	if (!font.loadFromFile("ArtAssets/impact.ttf"))
	{
		std::cout << "Es konnte keine Fontdatei gefunden werden!" << std::endl;
	}
}

//Zeigt den Endscreen an, durch den bool gameOver, wird unterschieden ob der GAMEOVER Screen oder der WINNING Screen angezeigt wird
void EndScreen::Run(bool gameOver, int punkteZahl)
{
	sf::Font font;
	string TexturePath = "ArtAssets/Menu/MenuButton.png";
	sf::Texture BackgroundTexture;
	sf::Sprite BackgroundSprite;
	sf::Color color;
	sf::Color hoverColer = sf::Color(255, 255, 255, 140);
	BasicButton ExitButton = BasicButton(150, 500, "EXIT", TexturePath, color.White, 38, -120, 475);
	sf::Text EndScreenText;
	sf::Text points;
	sf::Text PointsText;
	LoadGameFont(font);


	PointsText.setFont(font);
	PointsText.setCharacterSize(80);
	points.setFont(font);
	points.setCharacterSize(80);
	EndScreenText.setFont(font);
	EndScreenText.setCharacterSize(130);
	
	if (gameOver)
	{
		BackgroundTexture.loadFromFile("ArtAssets/Nebula Red.png");
		EndScreenText.setFillColor(color.Red);
		EndScreenText.setString("GAME OVER");
		EndScreenText.setPosition(15, 150);
		points.setFillColor(color.Red);
		PointsText.setFillColor(color.Red);
	}
	else
	{
		BackgroundTexture.loadFromFile("ArtAssets/Nebula Blue.png");
		EndScreenText.setFillColor(color.White);
		EndScreenText.setString("YOU WIN");
		EndScreenText.setPosition(80, 150);
		points.setFillColor(color.White);
		PointsText.setFillColor(color.White);
	}

	PointsText.setPosition(50,350);
	PointsText.setString("Punkte :");
	points.setPosition(360, 350);

	points.setString(to_string(punkteZahl));
	BackgroundSprite.setTexture(BackgroundTexture);
	BackgroundSprite.setPosition(0, 0);

	Window.setFramerateLimit(24);

	while (Window.isOpen())
	{

		sf::Event event;


		while (Window.pollEvent(event))
		{
			switch (event.type)
			{

			case sf::Event::Closed:
				Window.close();
				running = false;
				break;
			}

		}

		sf::Vector2i localPosition = sf::Mouse::getPosition(Window);
		sf::Vector2f mousePosF(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y));

		if (ExitButton.getSprite().getGlobalBounds().contains(mousePosF))
		{
			ExitButton.setColor(hoverColer);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				Window.close();

				Menu game;

				while (game.isRunning())
				{
					game.Run();
				}
				running = false;
			}
		}
		else
		{
			ExitButton.setColor(color.White);
		}

		
		Window.draw(BackgroundSprite);
		Window.draw(ExitButton.getSprite());
		Window.draw(ExitButton.getButtonText());
		Window.draw(EndScreenText);
		Window.draw(PointsText);
		Window.draw(points);
		Window.display();
	}
}


bool EndScreen::isRunning()
{
	return running;
}
