#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "DummyEnemy.h"
#include "BasicTower.h"
#include "CannonTower.h"
#include "FlameTower.h"

class Game 
{
public:
	Game();
	~Game();

	void Run();
	void TowerAnimation(std::vector<BasicTower *> * BasicTowerVector, std::vector<DummyEnemy *> * enemyActiveVector, sf::Sprite &explosionSprite, std::vector<CannonTower *> * CannonTowerVector, std::vector<FlameTower *> * FlameTowerVector);
	void LoadExplosionTextures(sf::Texture &explosionTexture, sf::Sprite &explosionSprite);
	void LoadGameFieldTextures(sf::Texture &statusTexture, sf::Texture &hudTexture, sf::Sprite &hudSprite, sf::Sprite &statusSprite, sf::Texture &backgroundTexture, sf::Sprite &backgroundSprite, sf::Texture &emptySpaceTexture, sf::Texture &blockedSpaceTexture,sf::Sprite &emptySpaceSprite, sf::Sprite &blockedSpaceSprite);
	void SetDescriptionTextProperties(sf::Text &descriptionText, sf::Font &font, sf::Color &color);
	void SetPointNumberProperties(sf::Text &punktZahlText, sf::Font &font, sf::Color &color, int punkteZahl);
	void SetPointTextProperties(sf::Text &punktText, sf::Font &font, sf::Color &color);
	void SetLifeTextProperties(sf::Text &lebenText, sf::Font &font, int playerLife, sf::Color &color);
	void SetTimerTextProperties(sf::Text &TimerText, sf::Font &font, sf::Color &color);
	void SetGoldTextProperties(sf::Text &goldText, sf::Font &font, sf::Color &color);
	void SetRoundTextProperties(sf::Text &rundenText, sf::Font &font, sf::Color &color);
	void SetLightningTowerProperties(sf::Texture &lightningTurmButton, sf::Sprite &lightningTowerImage);
	void SetFireTowerProperties(sf::Texture &feuerTurmButton, sf::Sprite &feuerTurmImage);
	void SetFrostTowerProperties(sf::Texture &frostTurmButton, sf::Sprite &frostTurmImage);
	void SetCannonTowerProperties(sf::Texture &cannonTurmButton, sf::Sprite &cannonTurmImage);
	void SetBasicTowerProperties(sf::Texture &basicTurmButton, sf::Sprite &basicTurmImage);
	void LoadGameFont(sf::Font &font);
	void LoadLifeBarTextures(sf::Texture &hundredLifeTexture, sf::Texture &ninetyLifeTexture, sf::Texture &eightyLifeTexture, sf::Texture &seventyLifeTexture, sf::Texture &sixtyLifeTexture, sf::Texture &fiftyLifeTexture, sf::Texture &fortyLifeTexture, sf::Texture &thirtyLifeTexture, sf::Texture &twentyLifeTexture, sf::Texture &tenLifeTexture);
	void DrawTower(std::vector<BasicTower *> * BasicTowerVector, std::vector<CannonTower *> * CannonTowerVector, std::vector<FlameTower *> * FeuerTowerVector);
	void UpdateEnemyMovement(int movementElapsed, int movementElapsedBuffer, sf::Clock &enemyMovementClock, std::vector<DummyEnemy *> * enemyActiveVector, int i, float y, float x, sf::Sprite &lifeEnemySprite, int &playerLife, sf::Text &lebenText);
	void UpdateEnemyLifeBar(std::vector<DummyEnemy *> * enemyActiveVector, int i, int &punkteZahl, int &gold, float &x, float &y, sf::Sprite &lifeEnemySprite, sf::Texture &hundredLifeTexture, sf::Texture &eightyLifeTexture, sf::Texture &sixtyLifeTexture, sf::Texture &fortyLifeTexture, sf::Texture &twentyLifeTexture, sf::Texture &tenLifeTexture, sf::Text &punktZahlText);
	void ShowGameOverScreen(sf::Font &font, sf::Color &color, sf::Texture &backgroundTexture, sf::Sprite &backgroundSprite, sf::String &playerInput, sf::Text &playerText);

	bool isRunning();

private:
	sf::RenderWindow App;

	bool running;
	std::string name;

};
#endif