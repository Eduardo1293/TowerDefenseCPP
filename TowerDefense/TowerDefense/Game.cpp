/*
Hier Sachen reinschrieben, die noch gemacht werden müssen!
Problem mit PlayingField beheben.

*/



#include "Game.h"
#include <list>
#include <vector>
//#include "PlayingField.cpp"
#include "GameArea.h"
#include "BasicTower.h"
#include "EnemyWaves.h"
#include "Menu.h"
#include "BasicButton.h"

#include <iostream>


Game::Game()
{
	name = "Lennard is kacke.exe";
	App.create(sf::VideoMode(512, 896), name, sf::Style::Close);
	running = true;

}

//bool für gegnerphase oder bauphase
bool buildingphase = true;

Game::~Game()
{
}

void Game::Run()
{
	sf::Clock clock;
	App.setFramerateLimit(24);
	float x;
	float y;

	float gameTime = 0;
	int gold = 100;
	int runde = 0;
	int timerText = 0;
	int playerLife = 20;
	int punkteZahl = 0;
	int gameTimeEnemyCounter = 1;
	int waveEnemyAddedCounter = 0;



	enum SelectetTower
	{
		noTower,
		basicTower,
		cannonTower,
		flameTower,
		frostTower,
		lightningTower
	};



	vector<BasicEnemy*> *enemyVector = new vector<BasicEnemy*>();
	vector<BasicEnemy*> *enemyActiveVector = new vector<BasicEnemy*>();
	*enemyVector = enemyWaves(1);



	//Testturm und Testgegner
	sf::Sprite testTurmSprite;
	sf::Sprite testEnemySprite;
	sf::Sprite buildTowerSprite;
	sf::Texture basicTowerTexture;
	basicTowerTexture.loadFromFile("ArtAssets/Tower/tank_dark.png");
	//halbdurchsichtiger tower zum bauen	
	buildTowerSprite.setColor(sf::Color(255, 255, 255, 140));
	buildTowerSprite.setOrigin(32, 32);


	//lifebar
	sf::Texture hundredLifeTexture;
	sf::Texture ninetyLifeTexture;
	sf::Texture eightyLifeTexture;
	sf::Texture seventyLifeTexture;
	sf::Texture sixtyLifeTexture;
	sf::Texture fiftyLifeTexture;
	sf::Texture fortyLifeTexture;
	sf::Texture thirtyLifeTexture;
	sf::Texture twentyLifeTexture;
	sf::Texture tenLifeTexture;
	sf::Sprite lifeEnemySprite;
	sf::Color color;
	sf::Font font;

	sf::Color hoverColer = sf::Color(255, 255, 255, 140);

	LoadLifeBarTextures(hundredLifeTexture, ninetyLifeTexture, eightyLifeTexture,
		seventyLifeTexture, sixtyLifeTexture, fiftyLifeTexture, fortyLifeTexture,
		thirtyLifeTexture, twentyLifeTexture, tenLifeTexture, lifeEnemySprite);




	LoadGameFont(font);

	BasicButton basicTowerButton = BasicButton(78, 779, "", "ArtAssets/Tower/tank_green.png", color.White, 0, 0, 0);
	BasicButton cannonTowerButton = BasicButton(151, 779, "", "ArtAssets/Tower/tank_green.png", color.White, 0, 0, 0);
	BasicButton frostTowerButton = BasicButton(224, 779, "", "ArtAssets/Tower/tank_blue.png", color.White, 0, 0, 0);
	BasicButton fireTowerButton = BasicButton(297, 779, "", "ArtAssets/Tower/tank_red.png", color.White, 0, 0, 0);
	BasicButton lightningTowerButton = BasicButton(368, 779, "", "ArtAssets/Tower/tank_sand.png", color.White, 0, 0, 0);

	sf::Text rundenText;
	SetRoundTextProperties(rundenText, font, color);

	sf::Text goldText;
	SetGoldTextProperties(goldText, font, color);


	sf::Text TimerText;
	SetTimerTextProperties(TimerText, font, color);

	sf::Text lebenText;
	SetLifeTextProperties(lebenText, font, playerLife, color);

	sf::Text punktText;
	SetPointTextProperties(punktText, font, color);

	sf::Text punktZahlText;
	SetPointNumberProperties(punktZahlText, font, color, punkteZahl);

	sf::Text descriptionText;
	SetDescriptionTextProperties(descriptionText, font, color);

	sf::Texture statusTexture;
	sf::Texture hudTexture;
	sf::Sprite hudSprite;
	sf::Sprite statusSprite;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Texture emptySpaceTexture;
	sf::Texture blockedSpaceTexture;
	sf::Sprite emptySpaceSprite;
	sf::Sprite blockedSpaceSprite;


	LoadGameFieldTextures(statusTexture, hudTexture, hudSprite, statusSprite,
		backgroundTexture, backgroundSprite, emptySpaceTexture, blockedSpaceTexture,
		emptySpaceSprite, blockedSpaceSprite);

	//explosion
	sf::Texture explosionTexture;
	sf::Sprite explosionSprite;
	LoadExplosionTextures(explosionTexture, explosionSprite);


	sf::Text playerText;
	playerText.setFont(font);
	playerText.setFillColor(color.White);
	playerText.setCharacterSize(30);
	playerText.setPosition(120, 600);
	sf::String playerInput;




	testEnemySprite.setOrigin(32, 32);

	/*for each (PropertyInfo prop in typeof(PlayingField))
	{
		this.playingFieldList.Add(prop)
	}*/

	//HIER HABE ICH WAS GEMACHT
	vector<GameArea*> GameAreaVector;// = PlayingFields();
	vector<BasicTower*> *TowerVector = new vector<BasicTower*>();

	sf::Clock timerClock;

	//phasen-clock
	sf::Clock buildingphaseClock;
	int buildingphaseCountdown = 30;
	int buildphaseElapsedTimeBuffer = 0;

	//attackclock, brauchen wir für tower attacken;
	sf::Clock attackClock;
	int attackClockElapsedTimeBuffer = 0;

	//enemymovementtick
	sf::Clock enemyMovementClock;
	int movementElapsedBuffer = 0;

	// run the program as long as the window is open
	while (App.isOpen())
	{

		App.clear(sf::Color::Black);
		App.draw(backgroundSprite);
		SetInfoText(goldText, gold, rundenText, runde, TimerText, timerText);
		DrawGameTextures(hudSprite, statusSprite, rundenText,
			goldText, lebenText, basicTowerButton.getSprite(), cannonTowerButton.getSprite(),
			frostTowerButton.getSprite(), fireTowerButton.getSprite(), lightningTowerButton.getSprite(),
			TimerText, punktZahlText, descriptionText, punktText);

		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (App.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				App.close();
				running = false;

			default:
				break;
			}
		}

		// clear the window with black color


		// draw everything here...
		// window.draw(...);
		//Background

		//male alles was immer dargestellt wird immer, unterer layer:



		//Gegnerphase / Bauphase unterscheidung hier!
		//manches muss immer dargestellt werden, anderes nur in der entsprechenden phase

		if (buildingphase) {
			SelectetTower selectetTower;
			//buildingkram

			//füge alle tower aus einer phase in eine gesonderte liste

			//nach 30sec ende, deaktiviere alle baufunktionen, 

			sf::Time buildphaseElapsedTime = buildingphaseClock.getElapsedTime();
			if ((buildphaseElapsedTime.asMilliseconds() + buildphaseElapsedTimeBuffer) >= 1000) {
				(buildphaseElapsedTimeBuffer = buildphaseElapsedTime.asMilliseconds() - 1000);
				buildingphaseCountdown -= 1;
				buildingphaseClock.restart();
			}

			timerText = buildingphaseCountdown;
			if (buildingphaseCountdown == 5)
			{
				TimerText.setFillColor(color.Red);

			}
			if (buildingphaseCountdown == 0)
			{
				buildingphase = false;
				TimerText.setFillColor(hoverColer);
				buildphaseElapsedTimeBuffer = 0;
				clock.restart();
			}

			{

				sf::Vector2i localPosition = sf::Mouse::getPosition(App);
				sf::Vector2f mousePosF(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y));
				BasicTower * BasicTowerRef;
				CannonTower * CannonTowerRef;
				FlameTower * FlameTowerRef;

				//freie und belegte felder markieren
				////// hier verbuggt, benutzt noch listen-iterator ist jetzt aber ein vector
				for (int i = 0; i < GameAreaVector.size(); i++) {
					if (GameAreaVector.at(i)->getEmpty()) {
						emptySpaceSprite.setPosition(GameAreaVector.at(i)->getAreaXCoord(), GameAreaVector.at(i)->getAreaYCoord());
						App.draw(emptySpaceSprite);
					}
					else {
						blockedSpaceSprite.setPosition(GameAreaVector.at(i)->getAreaXCoord(), GameAreaVector.at(i)->getAreaYCoord());
						App.draw(blockedSpaceSprite);
					}

					//mouse-movement auslesen
					if (localPosition.x <= (GameAreaVector.at(i)->getAreaXCoord() + 32) && (localPosition.x >= (GameAreaVector.at(i)->getAreaXCoord() - 31))
						&& (localPosition.y <= (GameAreaVector.at(i)->getAreaYCoord() + 32)) && (localPosition.y >= (GameAreaVector.at(i)->getAreaYCoord() - 31))) {
						buildTowerSprite.setPosition(GameAreaVector.at(i)->getAreaXCoord(), GameAreaVector.at(i)->getAreaYCoord());
						App.draw(buildTowerSprite);
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (localPosition.x <= (GameAreaVector.at(i)->getAreaXCoord() + 32) && (localPosition.x >= (GameAreaVector.at(i)->getAreaXCoord() - 31))
							&& (localPosition.y <= (GameAreaVector.at(i)->getAreaYCoord() + 32)) && (localPosition.y >= (GameAreaVector.at(i)->getAreaYCoord() - 31))) {

							switch (selectetTower)
							{
							case basicTower:
								BasicTowerRef = new BasicTower((GameAreaVector.at(i)->getAreaXCoord()), GameAreaVector.at(i)->getAreaYCoord());
								if (GameAreaVector.at(i)->getEmpty())
								{
									if (gold >= BasicTowerRef->getCost())
									{
										TowerVector->push_back(BasicTowerRef);
										GameAreaVector.at(i)->setAreaEmpty(false);
										gold = gold - BasicTowerRef->getCost();
									}
								}
								break;

							case cannonTower:
								CannonTowerRef = new CannonTower((GameAreaVector.at(i)->getAreaXCoord()), GameAreaVector.at(i)->getAreaYCoord());

								if (GameAreaVector.at(i)->getEmpty())
								{
									if (gold >= CannonTowerRef->getCost())
									{
										TowerVector->push_back(CannonTowerRef);
										GameAreaVector.at(i)->setAreaEmpty(false);
										gold = gold - CannonTowerRef->getCost();
									}
								}
								break;
							case flameTower:
								FlameTowerRef = new FlameTower((GameAreaVector.at(i)->getAreaXCoord()), GameAreaVector.at(i)->getAreaYCoord());
								if (GameAreaVector.at(i)->getEmpty())
								{
									if (gold >= FlameTowerRef->getCost())
									{
										TowerVector->push_back(FlameTowerRef);
										GameAreaVector.at(i)->setAreaEmpty(false);
										gold = gold - FlameTowerRef->getCost();
									}
								}
								break;
								//case frostTower:
								//	BasicTower * Tower = new BasicTower((GameAreaVector.at(i))->getAreaXCoord()), GameAreaVector.at(i)->getAreaYCoord());
								//	break;
								//case lightningTower:
								//	BasicTower * Tower = new BasicTower((GameAreaVector.at(i)->getAreaXCoord()), GameAreaVector.at(i)->getAreaYCoord());
								//	break;
								//default:
								//BasicTower * Tower = new BasicTower((GameAreaVector.at(i)->getAreaXCoord()), GameAreaVector.at(i)->getAreaYCoord());
								//break;
							}
						}
					}
				}

				//buttons interface
				if (basicTowerButton.getSprite().getGlobalBounds().contains(mousePosF))
				{
					basicTowerButton.setColor(hoverColer);

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						selectetTower = basicTower;
						buildTowerSprite.setTexture(basicTowerButton.getButtonTexture());
						basicTowerButton.setColor(hoverColer);
					}
				}
				else
				{
					if (selectetTower != basicTower)
					{
						basicTowerButton.setColor(color.White);
					}
				}
				if (cannonTowerButton.getSprite().getGlobalBounds().contains(mousePosF))
				{
					cannonTowerButton.setColor(hoverColer);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						selectetTower = cannonTower;
						
						buildTowerSprite.setTexture(cannonTowerButton.getButtonTexture());
						cannonTowerButton.setColor(hoverColer);
					}
				}
				else
				{
					if (selectetTower != cannonTower)
					{
						cannonTowerButton.setColor(color.White);
					}
				}
				if (frostTowerButton.getSprite().getGlobalBounds().contains(mousePosF))
				{
					frostTowerButton.setColor(hoverColer);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						selectetTower = frostTower;

						buildTowerSprite.setTexture(frostTowerButton.getButtonTexture());
						frostTowerButton.setColor(hoverColer);
					}
				}
				else
				{
					if (selectetTower != frostTower)
					{
						frostTowerButton.setColor(color.White);
					}
				}


				if (fireTowerButton.getSprite().getGlobalBounds().contains(mousePosF))
				{
					fireTowerButton.setColor(hoverColer);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						selectetTower = flameTower;

						buildTowerSprite.setTexture(fireTowerButton.getButtonTexture());
						fireTowerButton.setColor(hoverColer);
					}
				}
				else
				{
					if (selectetTower != flameTower)
					{
						fireTowerButton.setColor(color.White);
					}
				}


				if (lightningTowerButton.getSprite().getGlobalBounds().contains(mousePosF))
				{
					lightningTowerButton.setColor(hoverColer);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						lightningTowerButton.setColor(hoverColer);
						selectetTower = lightningTower;

						buildTowerSprite.setTexture(lightningTowerButton.getButtonTexture()); 
					}
				}
				else
				{
					if (selectetTower != lightningTower)
					{
						lightningTowerButton.setColor(color.White);
					}
				}
			}
		}
		else {

			descriptionText.setString("");
			//enemyphasenkram
			//berechne weg mit a* hier
			//falls a* keinen weg findet, zerstöre alle tower aus der gesonderten liste

			//towermenu durch gegnerwave-anzeige ersetzen fragezeichen?
			//spawne enemies hier	

			//*bumpaffpow ratatatapeng*

			//alle gegner tot oder am ziel:

			//schickt die gegner aus wave1 auf die reise
			//hier ist noch was madig
			sf::Time elapsed1 = clock.getElapsedTime();
			gameTime = elapsed1.asSeconds();
			if (gameTime > gameTimeEnemyCounter && gameTime < (enemyVector->size()) + 2) {
				enemyActiveVector->push_back(enemyVector->at(waveEnemyAddedCounter));
				gameTimeEnemyCounter = (gameTimeEnemyCounter + 1);
				waveEnemyAddedCounter = (waveEnemyAddedCounter + 1);
			}

			sf::Time attackCDTime = attackClock.getElapsedTime();
			if ((attackCDTime.asMilliseconds() + attackClockElapsedTimeBuffer) >= 100) {
				(attackClockElapsedTimeBuffer = attackCDTime.asMilliseconds() - 100);
				attackClock.restart();
				//Tower malen
				TowerAnimation(TowerVector, enemyActiveVector, explosionSprite);
			}


			TimerText.setFillColor(color.Black);
			//buildingphase = true;
		}

		//male alles was immer dargestellt wird immer, oberer layer:

		DrawTower(TowerVector);




		//testgegner bewegungskram
		enemyMovementClock.getElapsedTime();
		sf::Time enemyMovementElapsed = enemyMovementClock.getElapsedTime();
		int movementElapsed = enemyMovementElapsed.asMilliseconds();
		for (unsigned int i = 0; i < enemyActiveVector->size(); i++) {
			UpdateEnemyLifeBar(enemyActiveVector, i, punkteZahl, gold, x,
				y, lifeEnemySprite, hundredLifeTexture, eightyLifeTexture,
				sixtyLifeTexture, fortyLifeTexture, twentyLifeTexture,
				tenLifeTexture, punktZahlText);

			UpdateEnemyMovement(movementElapsed, movementElapsedBuffer,
				enemyMovementClock, enemyActiveVector, i, y, x, lifeEnemySprite, playerLife, lebenText);


			//Hier Knallt es wenn alle Gegner im Ziel sind!!!
			App.draw(enemyActiveVector->at(i)->getSprite());
			App.draw(lifeEnemySprite);


		}

		if (playerLife <= 0)
		{
			ShowGameOverScreen(font, color, backgroundTexture, backgroundSprite, playerInput, playerText);
		}

		// end the current frame
		App.display();

	}
}

void Game::DrawGameTextures(sf::Sprite &hudSprite, sf::Sprite &statusSprite, sf::Text &rundenText, sf::Text &goldText, sf::Text &lebenText, sf::Sprite &basicTurmImage, sf::Sprite &cannonTurmImage, sf::Sprite &frostTurmImage, sf::Sprite &feuerTurmImage, sf::Sprite &lightningTowerImage, sf::Text &TimerText, sf::Text &punktZahlText, sf::Text &descriptionText, sf::Text &punktText)
{
	App.draw(hudSprite);
	App.draw(statusSprite);
	App.draw(rundenText);
	App.draw(goldText);
	App.draw(lebenText);
	App.draw(basicTurmImage);
	App.draw(cannonTurmImage);
	App.draw(frostTurmImage);
	App.draw(feuerTurmImage);
	App.draw(lightningTowerImage);
	App.draw(TimerText);
	App.draw(punktZahlText);
	App.draw(descriptionText);
	App.draw(punktText);
}

void Game::SetInfoText(sf::Text &goldText, int gold, sf::Text &rundenText, int runde, sf::Text &TimerText, int timerText)
{
	goldText.setString(to_string(gold));
	rundenText.setString(to_string(runde));
	TimerText.setString(to_string(timerText));
}

void Game::TowerAnimation(std::vector<BasicTower *> * BasicTowerVector,
	std::vector<BasicEnemy *> * enemyActiveVector, sf::Sprite &explosionSprite)
{
	for (unsigned int i = 0; i < BasicTowerVector->size(); i++) {
		int target = BasicTowerVector->at(i)->checkForEnemies(enemyActiveVector);
		if (target >= 0 && target <= 9 && enemyActiveVector->at(target)->getCurrentLife() > 0) {
			enemyActiveVector->at(target)->takeDamage(BasicTowerVector->at(i)->getDamage());
			explosionSprite.setPosition(enemyActiveVector->at(target)->getXCoord(), enemyActiveVector->at(target)->getYCoord());
			App.draw(explosionSprite);
		}
	}
}

void Game::LoadExplosionTextures(sf::Texture &explosionTexture, sf::Sprite &explosionSprite)
{
	explosionTexture.loadFromFile("ArtAssets/SFX/explosion2.png");
	explosionSprite.setTexture(explosionTexture);
	explosionSprite.setOrigin(64, 64);
	explosionSprite.setScale(0.5, 0.5);
}

void Game::LoadGameFieldTextures(sf::Texture &statusTexture, sf::Texture &hudTexture,
	sf::Sprite &hudSprite, sf::Sprite &statusSprite,
	sf::Texture &backgroundTexture, sf::Sprite &backgroundSprite,
	sf::Texture &emptySpaceTexture, sf::Texture &blockedSpaceTexture,
	sf::Sprite &emptySpaceSprite, sf::Sprite &blockedSpaceSprite)
{
	statusTexture.loadFromFile("ArtAssets/Status.png");
	hudTexture.loadFromFile("ArtAssets/HUD.png");
	hudSprite.setTexture(hudTexture);
	hudSprite.setPosition(0, 768);
	statusSprite.setTexture(statusTexture);
	statusSprite.setPosition(0, 0);
	backgroundTexture.loadFromFile("ArtAssets/Nebula Blue_Background.png");
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(0, 64);
	emptySpaceTexture.loadFromFile("ArtAssets/emptyspace.png");
	blockedSpaceTexture.loadFromFile("ArtAssets/blockedspace.png");
	emptySpaceSprite.setTexture(emptySpaceTexture);
	emptySpaceSprite.setColor(sf::Color(255, 255, 255, 128));
	emptySpaceSprite.setOrigin(32, 32);
	blockedSpaceSprite.setTexture(blockedSpaceTexture);
	blockedSpaceSprite.setColor(sf::Color(255, 255, 255, 128));
	blockedSpaceSprite.setOrigin(32, 32);
}

void Game::SetDescriptionTextProperties(sf::Text &descriptionText, sf::Font &font, sf::Color &color)
{
	descriptionText.setFont(font);
	descriptionText.setFillColor(color.Black);
	descriptionText.setCharacterSize(13);
	descriptionText.setPosition(5, 870);
}

void Game::SetPointNumberProperties(sf::Text &punktZahlText, sf::Font &font, sf::Color &color, int punkteZahl)
{
	punktZahlText.setFont(font);
	punktZahlText.setFillColor(color.Black);
	punktZahlText.setString(to_string(punkteZahl));
	punktZahlText.setCharacterSize(13);
	punktZahlText.setPosition(370, 32);
}

void Game::SetPointTextProperties(sf::Text &punktText, sf::Font &font, sf::Color &color)
{
	punktText.setFont(font);
	punktText.setString("PUNKTE:");
	punktText.setFillColor(color.Black);
	punktText.setCharacterSize(13);
	punktText.setPosition(308, 32);
}

void Game::SetLifeTextProperties(sf::Text &lebenText, sf::Font &font, int playerLife, sf::Color &color)
{
	lebenText.setFont(font);
	lebenText.setString(to_string(playerLife));
	lebenText.setFillColor(color.Black);
	lebenText.setCharacterSize(13);
	lebenText.setPosition(360, 16);
}

void Game::SetTimerTextProperties(sf::Text &TimerText, sf::Font &font, sf::Color &color)
{
	TimerText.setFont(font);
	TimerText.setCharacterSize(30);
	TimerText.setPosition(250, 850);
	TimerText.setFillColor(color.Black);
}

void Game::SetGoldTextProperties(sf::Text &goldText, sf::Font &font, sf::Color &color)
{
	goldText.setFont(font);
	goldText.setFillColor(color.Black);
	goldText.setCharacterSize(13);
	goldText.setPosition(65, 35);
}

void Game::SetRoundTextProperties(sf::Text &rundenText, sf::Font &font, sf::Color &color)
{
	rundenText.setFont(font);
	rundenText.setFillColor(color.Black);
	rundenText.setCharacterSize(13);
	rundenText.setPosition(65, 15);
}

void Game::LoadGameFont(sf::Font &font)
{
	if (!font.loadFromFile("ArtAssets/impact.ttf"))
	{
		std::cout << "Es konnte keine Fontdatei geunden werden!" << std::endl;
	}
}

void Game::LoadLifeBarTextures(sf::Texture &hundredLifeTexture, sf::Texture &ninetyLifeTexture,
	sf::Texture &eightyLifeTexture, sf::Texture &seventyLifeTexture, sf::Texture &sixtyLifeTexture,
	sf::Texture &fiftyLifeTexture, sf::Texture &fortyLifeTexture, sf::Texture &thirtyLifeTexture,
	sf::Texture &twentyLifeTexture, sf::Texture &tenLifeTexture, sf::Sprite &lifeEnemySprite)
{
	hundredLifeTexture.loadFromFile("ArtAssets/Lifebar/100percent.png");
	ninetyLifeTexture.loadFromFile("ArtAssets/Lifebar/90percent.png");
	eightyLifeTexture.loadFromFile("ArtAssets/Lifebar/80percent.png");
	seventyLifeTexture.loadFromFile("ArtAssets/Lifebar/70percent.png");
	sixtyLifeTexture.loadFromFile("ArtAssets/Lifebar/60percent.png");
	fiftyLifeTexture.loadFromFile("ArtAssets/Lifebar/50percent.png");
	fortyLifeTexture.loadFromFile("ArtAssets/Lifebar/40percent.png");
	thirtyLifeTexture.loadFromFile("ArtAssets/Lifebar/30percent.png");
	twentyLifeTexture.loadFromFile("ArtAssets/Lifebar/20percent.png");
	tenLifeTexture.loadFromFile("ArtAssets/Lifebar/10percent.png");

	lifeEnemySprite.setTexture(fiftyLifeTexture);
	lifeEnemySprite.setOrigin(20, 2);
}

void Game::DrawTower(std::vector<BasicTower *> * BasicTowerVector)
{
	for (unsigned int i = 0; i < BasicTowerVector->size(); i++)
	{
		App.draw(BasicTowerVector->at(i)->getSprite());
	}
}

void Game::UpdateEnemyMovement(int movementElapsed, int movementElapsedBuffer,
	sf::Clock &enemyMovementClock, std::vector<BasicEnemy *> * enemyActiveVector,
	int i, float y, float x, sf::Sprite &lifeEnemySprite, int &playerLife, sf::Text &lebenText)
{
	if ((movementElapsed + movementElapsedBuffer) >= 25) {
		enemyMovementClock.restart();
		enemyActiveVector->at(i)->eSetPosition();
		if (y > 191 && x < 447) {
			enemyActiveVector->at(i)->eSetRotation(270);
			lifeEnemySprite.setPosition(x, (y - 25));
			(enemyActiveVector->at(i)->eSetXCoord((x + 2)));
		}
		if (y <= 191) {
			lifeEnemySprite.setPosition(x, (y - 25));
			App.draw((enemyActiveVector->at(i)->getSprite()));
			App.draw(lifeEnemySprite);
			(enemyActiveVector->at(i)->eSetYCoord((y + 2)));
		}
		if (x >= 447 && y <= 738) {
			(enemyActiveVector->at(i)->eSetRotation(0));
			lifeEnemySprite.setPosition(x, (y - 25));
			(enemyActiveVector->at(i)->eSetYCoord((y + 2)));

		}
		if (y > 738) {
			enemyActiveVector->erase(enemyActiveVector->begin() + i);
			playerLife = playerLife--;
			lebenText.setString(to_string(playerLife));
		}
	}
}

void Game::UpdateEnemyLifeBar(std::vector<BasicEnemy *> * enemyActiveVector,
	int i, int &punkteZahl, int &gold, float &x, float &y, sf::Sprite &lifeEnemySprite,
	sf::Texture &hundredLifeTexture, sf::Texture &eightyLifeTexture, sf::Texture &sixtyLifeTexture,
	sf::Texture &fortyLifeTexture, sf::Texture &twentyLifeTexture, sf::Texture &tenLifeTexture, sf::Text &punktZahlText)
{
	if (enemyActiveVector->at(i)->getCurrentLife() == 0) {
		enemyActiveVector->erase((enemyActiveVector->begin() + i));
		punkteZahl += 100;
		gold += 100;
	}
	else {
		x = enemyActiveVector->at(i)->getXCoord();
		y = enemyActiveVector->at(i)->getYCoord();
		double lifePercent = (((enemyActiveVector->at(i)->getCurrentLife() / enemyActiveVector->at(i)->getMaxLife())) * 100);
		if (lifePercent > 90) {
			lifeEnemySprite.setTexture(hundredLifeTexture);
		}
		else if (lifePercent < 90 && lifePercent > 70) {
			lifeEnemySprite.setTexture(eightyLifeTexture);
		}
		else if (lifePercent < 70 && lifePercent > 50) {
			lifeEnemySprite.setTexture(sixtyLifeTexture);
		}
		else if (lifePercent < 50 && lifePercent > 30) {
			lifeEnemySprite.setTexture(fortyLifeTexture);
		}
		else if (lifePercent < 30 && lifePercent > 10) {
			lifeEnemySprite.setTexture(twentyLifeTexture);
		}
		else if (lifePercent < 10) {
			lifeEnemySprite.setTexture(tenLifeTexture);
			punktZahlText.setString(to_string(punkteZahl));
		}
	}
}

void Game::ShowGameOverScreen(sf::Font &font, sf::Color &color, sf::Texture &backgroundTexture, sf::Sprite &backgroundSprite, sf::String &playerInput, sf::Text &playerText)
{
	running = false;

	App.clear();
	sf::Text GameOverText;
	GameOverText.setFont(font);
	GameOverText.setFillColor(color.Red);
	GameOverText.setCharacterSize(50);
	GameOverText.setPosition(145, 400);
	GameOverText.setString("Game Over!");
	backgroundTexture.loadFromFile("ArtAssets/Nebula Red.png");
	backgroundSprite.setTexture(backgroundTexture);


	sf::Texture BackToMenuButton;
	BackToMenuButton.loadFromFile("ArtAssets/Menu/MenuButton.png");
	sf::Sprite BackToMenuButtonSprite;
	BackToMenuButtonSprite.setPosition(105, 500);
	BackToMenuButtonSprite.setTexture(BackToMenuButton);
	float BackToMenuButtonWidth = BackToMenuButtonSprite.getLocalBounds().width;
	float BackToMenuButtonHeight = BackToMenuButtonSprite.getLocalBounds().height;

	sf::Text BackToMenuButtonText;
	BackToMenuButtonText.setFont(font);
	BackToMenuButtonText.setString("Zurück zum Menü");
	BackToMenuButtonText.setFillColor(color.White);
	BackToMenuButtonText.setCharacterSize(38);
	BackToMenuButtonText.setPosition(120, (BackToMenuButtonHeight / 2) + 475);

	App.draw(backgroundSprite);
	App.draw(GameOverText);
	App.draw(BackToMenuButtonSprite);
	App.draw(BackToMenuButtonText);
	sf::Event event;
	while (App.pollEvent(event))
	{
		if (event.type == sf::Event::TextEntered)
		{
			playerInput += event.text.unicode;
			playerText.setString(playerInput);
		}
	}
	App.draw(playerText);


	sf::Vector2i localPosition = sf::Mouse::getPosition(App);
	sf::Vector2f mousePosF(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y));
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (BackToMenuButtonSprite.getGlobalBounds().contains(mousePosF))
		{

			Menu menu;
			App.close();
			menu.Run();
		}
	}

}


bool Game::isRunning()
{
	return running;
}


