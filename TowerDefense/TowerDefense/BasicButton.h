#pragma once
#ifndef _BASICBUTTON_H_
#define _BASICBUTTON_H_

#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class BasicButton 
{
private:
	sf::Texture b_BasicButtonTexture;
	sf::Text b_ButtonText;	
	sf::Color b_ButtonColor;
	sf::Font b_ButtonTextFont;

protected:
	float b_XCoord;
	float b_YCoord;
	sf::Sprite b_ButtonSrite;

public:
	BasicButton();
	BasicButton(float XCoord, float YCoord, sf::String b_ButtonSrting, string b_TextureLocation, sf::Color b_ButtonTextColor, int b_CharacterSize, int b_AdditionalPositionXCoord, int b_AdditionalPositionYCoord);

	
	~BasicButton();

	inline sf::Sprite getSprite() const { return b_ButtonSrite; };
	inline sf::Text getButtonText() const { return b_ButtonText; };
	inline sf::Texture getButtonTexture() { return b_BasicButtonTexture; };
	inline void setColor(sf::Color color) { b_ButtonSrite.setColor(color); };

};


#endif // !_BASICBUTTON_H_
