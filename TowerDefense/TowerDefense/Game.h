#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "BasicEnemy.h"
#include "BasicTower.h"
#include "GameMap.h"
#include "GameArea.h"

class Game 
{
public:
	Game();
	~Game();

	void Run();
	void DrawGameTextures(sf::Sprite &hudSprite, sf::Sprite &statusSprite, sf::Text &rundenText, sf::Text &goldText, sf::Text &lebenText, sf::Sprite &basicTurmImage,
		sf::Sprite &cannonTurmImage, sf::Sprite &frostTurmImage, sf::Sprite &feuerTurmImage, sf::Sprite &lightningTowerImage, sf::Sprite &soundOnButton, sf::Sprite &soundOffButton,
		sf::Text &TimerText, sf::Text &punktZahlText, sf::Text &descriptionText, sf::Text &punktText);
	void SetInfoText(sf::Text &goldText, int gold, sf::Text &rundenText, int runde, sf::Text &TimerText, int timerText, sf::Text &lebenText, int playerLife);
	void TowerAnimation(std::vector<BasicTower *> * BasicTowerVector, std::vector<BasicEnemy *> * enemyActiveVector,
		sf::Sprite &explosionSprite);
	void LoadExplosionTextures(sf::Texture &explosionTexture, sf::Sprite &explosionSprite);
	void LoadGameFieldTextures(sf::Texture &statusTexture, sf::Texture &hudTexture, sf::Sprite &hudSprite,
		sf::Sprite &statusSprite, sf::Texture &backgroundTexture, sf::Sprite &backgroundSprite,
		sf::Texture &emptySpaceTexture, sf::Texture &blockedSpaceTexture,sf::Sprite &emptySpaceSprite, sf::Sprite &blockedSpaceSprite);

	void SetDescriptionTextProperties(sf::Text &descriptionText, sf::Font &font, sf::Color &color);
	void SetPointNumberProperties(sf::Text &punktZahlText, sf::Font &font, sf::Color &color, int punkteZahl);
	void SetPointTextProperties(sf::Text &punktText, sf::Font &font, sf::Color &color);
	void SetLifeTextProperties(sf::Text &lebenText, sf::Font &font, int playerLife, sf::Color &color);
	void SetTimerTextProperties(sf::Text &TimerText, sf::Font &font, sf::Color &color);
	void SetGoldTextProperties(sf::Text &goldText, sf::Font &font, sf::Color &color);
	void SetRoundTextProperties(sf::Text &rundenText, sf::Font &font, sf::Color &color);
	void LoadGameFont(sf::Font &font);
	void LoadLifeBarTextures(sf::Texture &hundredLifeTexture, sf::Texture &eightyLifeTexture,
		sf::Texture &sixtyLifeTexture, sf::Texture &fortyLifeTexture,
		sf::Texture &twentyLifeTexture, sf::Texture &tenLifeTexture, sf::Sprite &lifeEnemySprite);
	void DrawTower(std::vector<BasicTower *> * BasicTowerVector);
	void UpdateEnemyMovement(int movementElapsed, int movementElapsedBuffer,
		sf::Clock &enemyMovementClock, std::vector<BasicEnemy *> * enemyActiveVector,
		int i, float y, float x, sf::Sprite &lifeEnemySprite, int &playerLife, sf::Text &lebenText,
		vector<GameArea*>& playingField, vector<int> &path);
	void UpdateEnemyLifeBar(std::vector<BasicEnemy *> * enemyActiveVector, int i, int &punkteZahl,
		int &gold, int &x, int &y, sf::Sprite &lifeEnemySprite, sf::Texture &hundredLifeTexture,
		sf::Texture &eightyLifeTexture, sf::Texture &sixtyLifeTexture, sf::Texture &fortyLifeTexture,
		sf::Texture &twentyLifeTexture, sf::Texture &tenLifeTexture, sf::Text &punktZahlText);
	void ShowGameOverScreen(sf::Font &font, sf::Color &color, sf::Texture &backgroundTexture, sf::Sprite &backgroundSprite, sf::String &playerInput, sf::Text &playerText);

	bool isRunning();

private:
	sf::RenderWindow App;

	bool running;
	std::string name;

};
#endif