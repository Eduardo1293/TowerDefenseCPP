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
	void DrawTower(std::vector<BasicTower *> * BasicTowerVector, std::vector<CannonTower *> * CannonTowerVector, std::vector<FlameTower *> * FeuerTowerVector);
	void UpdateEnemyMovement(int movementElapsed, int movementElapsedBuffer, sf::Clock &enemyMovementClock, std::vector<DummyEnemy *> * enemyActiveVector, int i, int y, int x, sf::Sprite &lifeEnemySprite, int &playerLife, sf::Text &lebenText);
	void UpdateEnemyLifeBar(std::vector<DummyEnemy *> * enemyActiveVector, int i, int &punkteZahl, int &gold, int &x, int &y, sf::Sprite &lifeEnemySprite, sf::Texture &hundredLifeTexture, sf::Texture &eightyLifeTexture, sf::Texture &sixtyLifeTexture, sf::Texture &fortyLifeTexture, sf::Texture &twentyLifeTexture, sf::Texture &tenLifeTexture, sf::Text &punktZahlText);
	void ShowGameOverScreen(sf::Font &font, sf::Color &color, sf::Texture &backgroundTexture, sf::Sprite &backgroundSprite);

	bool isRunning();

private:
	sf::RenderWindow App;

	bool running;
	std::string name;

};
#endif