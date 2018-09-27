#include "BasicButton.h"

#include <iostream>

BasicButton::BasicButton()
{
}

BasicButton::BasicButton(float XCoord, float YCoord, sf::String b_ButtonSrting, string b_TextureLocation, sf::Color b_ButtonTextColor, int b_CharacterSize, int b_AdditionalPositionXCoord, int b_AdditionalPositionYCoord)
{

	if (!b_ButtonTextFont.loadFromFile("ArtAssets/impact.ttf"))
	{
		std::cout << "Es konnte keine Fontdatei geunden werden!" << std::endl;
	}

	b_BasicButtonTexture.loadFromFile(b_TextureLocation);
	b_ButtonSrite.setPosition(XCoord, YCoord);
	b_ButtonSrite.setTexture(b_BasicButtonTexture);
	b_ButtonText.setFont(b_ButtonTextFont);
	b_ButtonText.setString(b_ButtonSrting);
	b_ButtonText.setColor(b_ButtonTextColor);
	b_ButtonText.setCharacterSize(b_CharacterSize);
	b_ButtonText.setPosition((b_ButtonSrite.getLocalBounds().width / 2) - b_AdditionalPositionXCoord, (b_ButtonSrite.getLocalBounds().height / 2) + b_AdditionalPositionYCoord);
}

BasicButton::~BasicButton()
{
}
