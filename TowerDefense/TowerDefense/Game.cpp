/*
-----SPACE DEFENDER-----

Stefan Reso
Johannes Schmidt
Andre Jelonek       259031

Artassets von Kenney.nl und Itch.io
Musik von
*/


/*
Hier Sachen reinschrieben, die noch gemacht werden müssen!
-eine der distanzen in gamearea ist unnütz, beizeiten aufräumen :D und die namen sind komisch
-sollte bei den neuen türmen der tower nicht innerhalb der if-abfrage erstellt werden?
-musik stoppt nach einem durchlauf

-Projektmappen Einstellungen verallgemeinern: Wenn wir das so abgeben, muss er die einstellungen erst richtig setzten.

-spiel läuft im gameover screen weiter!!!!!!!!!!!!!!!
WICHTIG IM GAMEOVER SCREEN DREHT CPU DURCH  Erledigt X

-tower desriptions funktionieren nicht richtig!
-gewinnscreen?!? game läuft momentan einfach weiter
-Wenn WeakEnemy ins Ziel fährt, stürzt das Spiel ab
Beim bauen von Türmen wird der Turm nicht durchsicht angezeigt
*/



#include "Game.h"
#include <list>
#include <vector>
#include "GameMap.h"
#include "BasicTower.h"
#include "EnemyWaves.h"
#include "Menu.h"
#include "BasicButton.h"
#include "PathFinding.h"
#include "CustomException.h"
#include "EndScreen.h"
#include <iostream>
#include <map>


Game::Game()
{
	sf::Image GameIcon;
	GameIcon.loadFromFile("ArtAssets/gameIcon.png");
	name = "Space Defender";
	App.create(sf::VideoMode(512, 896), name, sf::Style::Close);
	App.setIcon(GameIcon.getSize().x, GameIcon.getSize().y, GameIcon.getPixelsPtr());
	running = true;

}

enum GameState
{
	BuildingPhase,
	GamePhase,
	GameOver,
	Winning
};

//Gamestate für die Phase in der sich der Spieler befindet
GameState gameState = BuildingPhase;

Game::~Game()
{
}

void Game::Run()
{

	//Grundlegende Einstellungen zu Spielbeginn
	App.setFramerateLimit(24);

	float gameTime = 0;
	int gold = 100;
	int runde = 0;
	int timerText = 0;
	int playerLife = 20;
	int punkteZahl = 0;
	int gameTimeEnemyCounter = 1;
	int waveEnemyAddedCounter = 0;
	int buildingPhaseTowerCount = 0;




	//Mechanik für Tower-Auswahl
	enum SelectetTower
	{
		noTower,
		basicTower,
		cannonTower,
		flameTower,
		frostTower,
		lightningTower
	};

	//Hintergrundmusik
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;

	soundBuffer.loadFromFile("ArtAssets/Audio/hintergrundmusik.ogg");

	sound.setBuffer(soundBuffer);
	sound.setVolume(0);

	sound.play();

	//Texturen für halbdurchsichtiger Tower zum Bauen
	sf::Sprite buildTowerSprite;
	sf::Texture basicTowerTexture;
	basicTowerTexture.loadFromFile("ArtAssets/Tower/tank_dark.png");
	buildTowerSprite.setColor(sf::Color(255, 255, 255, 140));
	buildTowerSprite.setOrigin(32, 32);


	//Lade Lifebar-Texturen
	sf::Texture hundredLifeTexture;
	sf::Texture eightyLifeTexture;
	sf::Texture sixtyLifeTexture;
	sf::Texture fortyLifeTexture;
	sf::Texture twentyLifeTexture;
	sf::Texture tenLifeTexture;
	sf::Sprite lifeEnemySprite;
	sf::Color color;
	sf::Font font;

	LoadLifeBarTextures(hundredLifeTexture, eightyLifeTexture,
		sixtyLifeTexture, fortyLifeTexture,
		twentyLifeTexture, tenLifeTexture, lifeEnemySprite);

	//Lade diverse GUI-Texturen und Einstellungen
	sf::Color hoverColer = sf::Color(255, 255, 255, 140);
	LoadGameFont(font);

	BasicButton basicTowerButton = BasicButton(78, 779, "", "ArtAssets/Tower/tank_dark.png", color.White, 0, 0, 0);
	BasicButton cannonTowerButton = BasicButton(151, 779, "", "ArtAssets/Tower/tank_green.png", color.White, 0, 0, 0);
	BasicButton frostTowerButton = BasicButton(224, 779, "", "ArtAssets/Tower/tank_blue.png", color.White, 0, 0, 0);
	BasicButton fireTowerButton = BasicButton(297, 779, "", "ArtAssets/Tower/tank_red.png", color.White, 0, 0, 0);
	BasicButton lightningTowerButton = BasicButton(368, 779, "", "ArtAssets/Tower/tank_sand.png", color.White, 0, 0, 0);
	BasicButton soundOnButton = BasicButton(450, 779, "", "ArtAssets/musicOn.png", color.White, 0, 0, 0);
	BasicButton soundOffButton = BasicButton(450, 820, "", "ArtAssets/musicOff.png", color.White, 0, 0, 0);

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


	//Explosions- und Attacken-Effekte	
	sf::Texture explosionTexture;
	sf::Sprite explosionSprite;
	sf::Texture frostAttackTexture;
	sf::Sprite frostAttackSprite;
	sf::Texture fireAttackTexture;
	sf::Sprite fireAttackSprite;
	sf::Texture lightningAttackTexture;
	sf::Sprite lightningAttackSprite;
	LoadExplosionTextures(explosionTexture, explosionSprite, frostAttackTexture, frostAttackSprite,
		fireAttackTexture, fireAttackSprite, lightningAttackTexture, lightningAttackSprite);

	//Text-Einstellungen
	sf::Text playerText;
	playerText.setFont(font);
	playerText.setFillColor(color.White);
	playerText.setCharacterSize(30);
	playerText.setPosition(120, 600);
	sf::String playerInput;


	//Initialisierung von Spielfeld, Pathfinding und Towermechaniken
	vector<BasicEnemy*> *enemyVector = new vector<BasicEnemy*>();
	vector<BasicEnemy*> *enemyActiveVector = new vector<BasicEnemy*>();

	GameMap *GameMapRef = new GameMap;
	GameMapRef->setGameMap();
	vector<GameArea*> GameAreaVector = GameMapRef->getGameMap();
	vector<int> path, pathXCoord, pathYCoord, pathDirection;
	PathFinding pathFindingRef;

	vector<BasicTower*> *TowerVector = new vector<BasicTower*>();

	vector<sf::Vector3i> towerAnimations;
	vector<int> animationFrameTime;

	//Verschiedene Uhren für die Spielmechaniken	
	sf::Clock buildingphaseClock;
	int buildingphaseCountdown = 20;
	int buildphaseElapsedTimeBuffer = 0;

	sf::Clock enemyClock;
	int enemyClockElapsedTimeBuffer = 0;

	sf::Clock attackClock;
	int attackClockElapsedTimeBuffer = 0;

	sf::Clock enemyMovementClock;
	int movementElapsedBuffer = 0;


	//Game-Loop, läuft solange das Fenster geöffnet bleibt	
	while (App.isOpen())
	{
		App.clear(sf::Color::Black);
		App.draw(backgroundSprite);
		SetInfoText(goldText, gold, rundenText, runde, TimerText, timerText, lebenText, playerLife);
		DrawGameTextures(hudSprite, statusSprite, rundenText,
			goldText, lebenText, basicTowerButton.getSprite(), cannonTowerButton.getSprite(),
			frostTowerButton.getSprite(), fireTowerButton.getSprite(), lightningTowerButton.getSprite(), soundOnButton.getSprite(), soundOffButton.getSprite(),
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

		//Mechaniken für das Auslesen der Maus
		sf::Vector2i localPosition = sf::Mouse::getPosition(App);
		sf::Vector2f mousePosF(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y));


		//Button für Sound On/Off		
		if (soundOnButton.getSprite().getGlobalBounds().contains(mousePosF))
		{
			soundOnButton.setColor(hoverColer);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sound.setVolume(100);
			}
		}
		else
		{
			soundOnButton.setColor(color.White);
		}

		if (soundOffButton.getSprite().getGlobalBounds().contains(mousePosF))
		{
			soundOffButton.setColor(hoverColer);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sound.setVolume(0);
			}
		}
		else
		{
			soundOffButton.setColor(color.White);
		}
		/*

				BUILDINGPHASE

		*/
		if (gameState == BuildingPhase) {
			SelectetTower selectetTower;

			/*
			Buildingphasen-Countdown
			*/
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

			//Können die aus dem Frame-Loop an den Anfang Stefan?
			AttackTower * AttackTowerRef;
			CannonTower * CannonTowerRef;
			FlameTower * FlameTowerRef;
			FrostTower * FrostTowerRef;
			LightningTower * LightningTowerRef;

			//Beende die Buildingphase. Falls kein Weg gefunden wird, lösche die Tower der letzten Phase aus dem Towervector.		
			if (buildingphaseCountdown == 0)
			{
				gameState = GamePhase;
				TimerText.setFillColor(hoverColer);
				buildphaseElapsedTimeBuffer = 0;


				try
				{
					path = pathFindingRef.aStar(GameAreaVector);
				}
				catch (CustomException e)
				{
					//Löscht alle Tower, die in der letzten Buildingphase gebaut wurden.
					for (int i = 0; i < buildingPhaseTowerCount; i++)
					{
						int location = TowerVector->at(TowerVector->size() - 1)->getLocation();

						GameAreaVector.at(location)->setAreaEmpty(true);
						TowerVector->erase(TowerVector->begin() + TowerVector->size() - 1);
					}
					path = pathFindingRef.aStar(GameAreaVector);
				}


				//Hilfsvektoren für die Gegnernavigation				
				pathXCoord.clear(), pathYCoord.clear(), pathDirection.clear();

				for (int i = 0; i < path.size(); i++)
				{
					for (int j = 0; j < GameAreaVector.size(); j++)
					{
						if (path.at(i) == GameAreaVector.at(j)->getID()) {
							pathXCoord.push_back(GameAreaVector.at(j)->getAreaXCoord());
							pathYCoord.push_back(GameAreaVector.at(j)->getAreaYCoord());
						}
					}
				}


				//Hilfsvektoren für die Gegnernavigation, beinhaltet Richtungsinformationen:
				//1=rechts, 2=unten, 3=links, 4=oben				
				for (int i = 0; i < (path.size() - 1); i++)
				{
					if (pathXCoord.at(i) < pathXCoord.at(i + 1))
					{
						pathDirection.push_back(1);
					}
					else if (pathYCoord.at(i) < pathYCoord.at(i + 1))
					{
						pathDirection.push_back(2);
					}
					else if (pathXCoord.at(i) > pathXCoord.at(i + 1))
					{
						pathDirection.push_back(3);
					}
					else if (pathYCoord.at(i) > pathYCoord.at(i + 1))
					{
						pathDirection.push_back(4);
					}
				}
				pathDirection.push_back(2);


				//Fülle den Gegnervektor mit den Gegnern der nächsten Wave	
				buildingPhaseTowerCount = 0;
				*enemyVector = enemyWaves(runde);
				enemyClock.restart();
			}


			//Markiert freie und belegte Felder mit grün bzw. rot.			
			for (int i = 0; i < GameAreaVector.size(); i++) {
				if (GameAreaVector.at(i)->getEmpty()) {
					emptySpaceSprite.setPosition(GameAreaVector.at(i)->getAreaXCoord(), GameAreaVector.at(i)->getAreaYCoord());
					App.draw(emptySpaceSprite);
				}
				else {
					blockedSpaceSprite.setPosition(GameAreaVector.at(i)->getAreaXCoord(), GameAreaVector.at(i)->getAreaYCoord());
					App.draw(blockedSpaceSprite);
				}


				//Funktion um Mausbewegungen auszulesen und eine "Tower-Vorschau" anzuzeigen.				
				if (localPosition.x <= (GameAreaVector.at(i)->getAreaXCoord() + 32) && (localPosition.x >= (GameAreaVector.at(i)->getAreaXCoord() - 31))
					&& (localPosition.y <= (GameAreaVector.at(i)->getAreaYCoord() + 32)) && (localPosition.y >= (GameAreaVector.at(i)->getAreaYCoord() - 31))) {
					buildTowerSprite.setPosition(GameAreaVector.at(i)->getAreaXCoord(), GameAreaVector.at(i)->getAreaYCoord());
					App.draw(buildTowerSprite);
				}


				//Baut beim Mausklick den ausgewählten Tower an der markierten Stelle.				
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (localPosition.x <= (GameAreaVector.at(i)->getAreaXCoord() + 32) && (localPosition.x >= (GameAreaVector.at(i)->getAreaXCoord() - 31))
						&& (localPosition.y <= (GameAreaVector.at(i)->getAreaYCoord() + 32)) && (localPosition.y >= (GameAreaVector.at(i)->getAreaYCoord() - 31))) {

						switch (selectetTower)
						{
						case basicTower:
							AttackTowerRef = new AttackTower((GameAreaVector.at(i)->getAreaXCoord()), GameAreaVector.at(i)->getAreaYCoord(), GameAreaVector.at(i)->getID());
							if (GameAreaVector.at(i)->getEmpty())
							{
								if (gold >= AttackTowerRef->getCost())
								{
									TowerVector->push_back(AttackTowerRef);
									GameAreaVector.at(i)->setAreaEmpty(false);
									gold = gold - AttackTowerRef->getCost();
									buildingPhaseTowerCount++;
								}
							}
							break;

						case cannonTower:
							CannonTowerRef = new CannonTower((GameAreaVector.at(i)->getAreaXCoord()), GameAreaVector.at(i)->getAreaYCoord(), GameAreaVector.at(i)->getID());

							if (GameAreaVector.at(i)->getEmpty())
							{
								if (gold >= CannonTowerRef->getCost())
								{
									TowerVector->push_back(CannonTowerRef);
									GameAreaVector.at(i)->setAreaEmpty(false);
									gold = gold - CannonTowerRef->getCost();
									buildingPhaseTowerCount++;
								}
							}
							break;
						case flameTower:
							FlameTowerRef = new FlameTower((GameAreaVector.at(i)->getAreaXCoord()), GameAreaVector.at(i)->getAreaYCoord(), GameAreaVector.at(i)->getID());
							if (GameAreaVector.at(i)->getEmpty())
							{
								if (gold >= FlameTowerRef->getCost())
								{
									TowerVector->push_back(FlameTowerRef);
									GameAreaVector.at(i)->setAreaEmpty(false);
									gold = gold - FlameTowerRef->getCost();
									buildingPhaseTowerCount++;
								}
							}
							break;
						case frostTower:
							FrostTowerRef = new FrostTower((GameAreaVector.at(i)->getAreaXCoord()), GameAreaVector.at(i)->getAreaYCoord(), GameAreaVector.at(i)->getID());
							if (GameAreaVector.at(i)->getEmpty())
							{
								if (gold >= FrostTowerRef->getCost())
								{
									TowerVector->push_back(FrostTowerRef);
									GameAreaVector.at(i)->setAreaEmpty(false);
									gold = gold - FrostTowerRef->getCost();
									buildingPhaseTowerCount++;
								}
							}
							break;
						case lightningTower:
							LightningTowerRef = new LightningTower((GameAreaVector.at(i)->getAreaXCoord()), GameAreaVector.at(i)->getAreaYCoord(), GameAreaVector.at(i)->getID());
							if (GameAreaVector.at(i)->getEmpty())
							{
								if (gold >= LightningTowerRef->getCost())
								{
									TowerVector->push_back(LightningTowerRef);
									GameAreaVector.at(i)->setAreaEmpty(false);
									gold = gold - LightningTowerRef->getCost();
									buildingPhaseTowerCount++;
								}
							}
							break;
						}
					}
				}

				if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
				{
					for (int i = 0; i < TowerVector->size(); i++)
					{
						for (int j = 0; j < GameAreaVector.size(); j++) {

							if ((localPosition.x <= (GameAreaVector.at(j)->getAreaXCoord() + 32) && (localPosition.x >= (GameAreaVector.at(j)->getAreaXCoord() - 31))
								&& (localPosition.y <= (GameAreaVector.at(j)->getAreaYCoord() + 32)) && (localPosition.y >= (GameAreaVector.at(j)->getAreaYCoord() - 31))))
							{
								if (GameAreaVector.at(j)->getID() == TowerVector->at(i)->getLocation())
								{
									gold = gold + (TowerVector->at(i)->getCost() / 2);
									TowerVector->erase(TowerVector->begin() + i);
									GameAreaVector.at(j)->setAreaEmpty(true);
								}
							}

						}
					}
				}
			}



			if (basicTowerButton.getSprite().getGlobalBounds().contains(mousePosF))
			{
				basicTowerButton.setColor(hoverColer);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					AttackTower AttackTowerNew = AttackTower();
					descriptionText.setString(AttackTowerNew.getDescription());
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
					CannonTower cannonTowerNew = CannonTower();
					descriptionText.setString(cannonTowerNew.getDescription());
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
					FrostTower frostTowerNew = FrostTower();
					descriptionText.setString(frostTowerNew.getDescription());
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
					FlameTower flameTowerNew = FlameTower();
					descriptionText.setString(flameTowerNew.getDescription());
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
					LightningTower lightningTowerNew = LightningTower();
					descriptionText.setString(lightningTowerNew.getDescription());
					lightningTowerButton.setColor(hoverColer);
					selectetTower = lightningTower;

					buildTowerSprite.setTexture(lightningTowerButton.getButtonTexture());
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


			if (enemyVector->empty()) {
				*enemyVector = enemyWaves(runde);
				runde++;
			}

		}

		/*

				GEGNERPHASE

		*/
		else if (gameState == GamePhase)
		{
			// Der Text für die Turm bezeichnung wird während der Gamephase geleert, damit dieser nicht Fest angezeigt wird
			descriptionText.setString("");

			//Enemyclock, schickt jede Sekunde einen Gegner auf die Reise
			sf::Time enemyTime = enemyClock.getElapsedTime();
			if (!enemyVector->empty() && enemyTime.asSeconds() > 1)
			{
				enemyActiveVector->push_back(enemyVector->at(0));
				enemyVector->erase(enemyVector->begin() + 0);
				enemyClock.restart();
			}

			if (enemyActiveVector->empty() && enemyVector->empty()) {
				gameState = BuildingPhase;
				buildingphaseCountdown = 20;
			}


			//Movementclock			
			/*enemyMovementClock.getElapsedTime();
			sf::Time enemyMovementElapsed = enemyMovementClock.getElapsedTime();
			int movementElapsed = enemyMovementElapsed.asMilliseconds();*/


			//Gegner-Lifebar aktualisieren
			for (unsigned int i = 0; i < enemyActiveVector->size(); i++)
			{
				int enemyLifebarX = enemyActiveVector->at(i)->eGetXCoord();
				int enemyLifebarY = enemyActiveVector->at(i)->eGetYCoord();

				UpdateEnemyLifeBar(enemyActiveVector, i, punkteZahl, gold, enemyLifebarX, enemyLifebarY,
					lifeEnemySprite, hundredLifeTexture, eightyLifeTexture,
					sixtyLifeTexture, fortyLifeTexture, twentyLifeTexture,
					tenLifeTexture, punktZahlText);

				lifeEnemySprite.setPosition(enemyLifebarX, (enemyLifebarY - 33));
				//Gegner-Lifebar zeichnen
				App.draw(lifeEnemySprite);
			}

			/*
						Gegnermovement

				Abhängig vom int iNavigationhelper, der Informationen über die aktuelle Postion des
				Gegner im Pfad gibt, wird der Gegner anhand des Pfades weiterbewegt
			*/
			if (!enemyActiveVector->empty())
			{
				for (unsigned int i = 0; i < enemyActiveVector->size(); i++)
				{
					//Überprüft, ob ein Gegner noch von einem Frosttower verlangsamt ist, nachdem der Gegner für
					//24 Frames verlangsamt war "taut" er auf
					int timer = enemyActiveVector->at(i)->eGetFrozenTimer();
					if (timer > 0 && timer < 25)
					{
						enemyActiveVector->at(i)->eSetFrozenTimer(timer + 1);
					}
					if (timer == 25)
					{
						enemyActiveVector->at(i)->eSetMovementSpeed(enemyActiveVector->at(i)->eGetMovementSpeed() + 1);
						enemyActiveVector->at(i)->eSetFrozenTimer(0);
					}

					//Abhängig vom Movementspeed wird der Gegner um mehrere Pixel pro Frame bewegt
					int mSpeed = enemyActiveVector->at(i)->eGetMovementSpeed();
					for (unsigned int j = 0; j < mSpeed; j++)
					{
						if (!enemyActiveVector->empty())
						{
							int enemyX = enemyActiveVector->at(i)->eGetXCoord();
							int enemyY = enemyActiveVector->at(i)->eGetYCoord();
							int iNavigationhelper = enemyActiveVector->at(i)->eGetNavigationHelper();

							/*
										Navigation vom Start auf das erste Spielfeld (iNavigationhelper = -1)
							*/
							if (iNavigationhelper == -1)
							{
								(enemyActiveVector->at(i)->eSetYCoord(enemyY + 1));
								if (enemyY > 159 && enemyActiveVector->at(i)->eGetGlobalLocation() != 0)
								{
									enemyActiveVector->at(i)->eSetGlobalLocation(0);
								}
								if (enemyY >= 191)
								{
									enemyActiveVector->at(i)->eSetYCoord(191);
									enemyActiveVector->at(i)->eSetNavigationHelper(iNavigationhelper + 1);
									if (pathDirection.at(1) = 1)
									{
										enemyActiveVector->at(i)->eSetRotation(270);
									}
									else
									{
										enemyActiveVector->at(i)->eSetRotation(0);
									}
								}
							}

							/*
										Navigation von Feld 0 auf Feld 62, dem Pathfinding folgend (iNavigationhelper zwischen 0 und 61)
							*/
							if (iNavigationhelper >= 0 && iNavigationhelper < (path.size() - 1))
							{
								int iSwitch = pathDirection.at(iNavigationhelper);
								int iSwitchPlusOne = pathDirection.at(iNavigationhelper + 1);

								//Switchcase der anhand der im Vector Pathdirection gespeicherten Richtung, der Gegner in die richtige
								//Richtung bewegt. Sobald der Gegner von einer Area (+/- 1pixel) in eine andere tritt wird außerdem die 
								//GlobalLocation des Gegner für das Tower-Targetting geupdated.
								//Ist der Gegner in der Mitte der nächsten Area angekommen wird außerdem mithilfe eines zweiten Switch-Cases
								//das Gegner-Sprite gedreht.
								switch (iSwitch)
								{
									//Movement nach rechts
								case 1:
									enemyActiveVector->at(i)->eSetXCoord(enemyX + 1);
									//Enemy globallocation updaten, wenn in neuem Feld
									if (enemyActiveVector->at(i)->eGetGlobalLocation() != path.at(iNavigationhelper + 1)
										&& (enemyActiveVector->at(i)->eGetXCoord() >= (pathXCoord.at(iNavigationhelper + 1) - 32)))
									{
										enemyActiveVector->at(i)->eSetGlobalLocation(path.at(iNavigationhelper + 1));
									}
									//Richtung ändern
									if (enemyActiveVector->at(i)->eGetXCoord() >= pathXCoord.at(iNavigationhelper + 1))
									{
										enemyActiveVector->at(i)->eSetXCoord(pathXCoord.at(iNavigationhelper + 1));
										enemyActiveVector->at(i)->eSetNavigationHelper(iNavigationhelper + 1);
										switch (iSwitchPlusOne)
										{
										case 1: enemyActiveVector->at(i)->eSetRotation(270); break;
										case 2: enemyActiveVector->at(i)->eSetRotation(0); break;
										case 3: enemyActiveVector->at(i)->eSetRotation(90); break;
										case 4: enemyActiveVector->at(i)->eSetRotation(180); break;
										}
									};
									break;;

									//Movement nach unten
								case 2:
									enemyActiveVector->at(i)->eSetYCoord(enemyY + 1);
									//Enemy globallocation updaten, wenn in neuem Feld
									if (enemyActiveVector->at(i)->eGetGlobalLocation() != path.at(iNavigationhelper + 1)
										&& (enemyActiveVector->at(i)->eGetYCoord() > (pathYCoord.at(iNavigationhelper + 1) - 32)))
									{
										enemyActiveVector->at(i)->eSetGlobalLocation(path.at(iNavigationhelper + 1));
									}
									//Richtung ändern
									if (enemyActiveVector->at(i)->eGetYCoord() >= pathYCoord.at(iNavigationhelper + 1))
									{
										enemyActiveVector->at(i)->eSetYCoord(pathYCoord.at(iNavigationhelper + 1));
										enemyActiveVector->at(i)->eSetNavigationHelper(iNavigationhelper + 1);
										switch (iSwitchPlusOne)
										{
										case 1: enemyActiveVector->at(i)->eSetRotation(270); break;
										case 2: enemyActiveVector->at(i)->eSetRotation(0); break;
										case 3: enemyActiveVector->at(i)->eSetRotation(90); break;
										case 4: enemyActiveVector->at(i)->eSetRotation(180); break;
										}
									};
									break;

									//Movement nach links
								case 3:
									enemyActiveVector->at(i)->eSetXCoord(enemyX - 1);
									//Enemy globallocation updaten, wenn in neuem Feld
									if (enemyActiveVector->at(i)->eGetGlobalLocation() != path.at(iNavigationhelper + 1)
										&& (enemyActiveVector->at(i)->eGetXCoord() <= (pathXCoord.at(iNavigationhelper + 1) + 32)))
									{
										enemyActiveVector->at(i)->eSetGlobalLocation(path.at(iNavigationhelper + 1));
									}
									//Richtung ändern
									if (enemyActiveVector->at(i)->eGetXCoord() <= pathXCoord.at(iNavigationhelper + 1))
									{
										enemyActiveVector->at(i)->eSetXCoord(pathXCoord.at(iNavigationhelper + 1));
										enemyActiveVector->at(i)->eSetNavigationHelper(iNavigationhelper + 1);
										switch (iSwitchPlusOne)
										{
										case 1: enemyActiveVector->at(i)->eSetRotation(270); break;
										case 2: enemyActiveVector->at(i)->eSetRotation(0); break;
										case 3: enemyActiveVector->at(i)->eSetRotation(90); break;
										case 4: enemyActiveVector->at(i)->eSetRotation(180); break;
										}
									};
									break;

									//Movement nach oben
								case 4:
									enemyActiveVector->at(i)->eSetYCoord(enemyY - 1);
									//Enemy globallocation updaten, wenn in neuem Feld
									if (enemyActiveVector->at(i)->eGetGlobalLocation() != path.at(iNavigationhelper + 1)
										&& (enemyActiveVector->at(i)->eGetYCoord() <= (pathYCoord.at(iNavigationhelper + 1) + 32)))
									{
										enemyActiveVector->at(i)->eSetGlobalLocation(path.at(iNavigationhelper + 1));
									}
									//Richtung ändern
									if (enemyActiveVector->at(i)->eGetYCoord() <= pathYCoord.at(iNavigationhelper + 1))
									{
										enemyActiveVector->at(i)->eSetYCoord(pathYCoord.at(iNavigationhelper + 1));
										enemyActiveVector->at(i)->eSetNavigationHelper(iNavigationhelper + 1);
										switch (iSwitchPlusOne)
										{
										case 1: enemyActiveVector->at(i)->eSetRotation(270); break;
										case 2: enemyActiveVector->at(i)->eSetRotation(0); break;
										case 3: enemyActiveVector->at(i)->eSetRotation(90); break;
										case 4: enemyActiveVector->at(i)->eSetRotation(180); break;
										}
									};
									break;
								}
							}

							/*
										Navigation vom letzten Spielfeld zum Ausgang (iNavigationhelper = 62)
							*/
							if (iNavigationhelper == (path.size() - 1))
							{
								(enemyActiveVector->at(i)->eSetYCoord(enemyY + 1));
								if (enemyY > 734 && enemyActiveVector->at(i)->eGetGlobalLocation() == 62)
								{
									enemyActiveVector->at(i)->eSetGlobalLocation(999);
								}
								if (enemyY >= 750)
								{
									enemyActiveVector->erase((enemyActiveVector->begin() + i));
									playerLife--;
								}
							}
						}
					}
				}
			}
			//Ende Gegnermovement


			//Zeichne die Gegner an den aktualisierten Positionen	
			for (unsigned int i = 0; i < enemyActiveVector->size(); i++)
			{
				if (!enemyActiveVector->empty())
				{
					enemyActiveVector->at(i)->eSetPosition();
					App.draw(enemyActiveVector->at(i)->eGetSprite());
				}
			}


			//Ruft alle 100ms für alle Türme die TowerAttack-Funktion auf. Fügt für die durchgeführten Angriff
			//Animationen zum Animations-Vector hinzu
			sf::Time attackCDTime = attackClock.getElapsedTime();
			if ((attackCDTime.asMilliseconds() + attackClockElapsedTimeBuffer) >= 100)
			{
				(attackClockElapsedTimeBuffer = attackCDTime.asMilliseconds() - 100);
				attackClock.restart();
				//Tower zeichnen
				vector<sf::Vector3i> addTowerAnimations = TowerAttack(TowerVector, enemyActiveVector, explosionSprite, lightningAttackSprite,
					fireAttackSprite, frostAttackSprite);
				for (int i = 0; i < addTowerAnimations.size(); i++)
				{
					animationFrameTime.push_back(0);
				}
				towerAnimations.insert(towerAnimations.end(), addTowerAnimations.begin(), addTowerAnimations.end());
			}

			//Zeichne die Attack-Animationen für jeweils 7 Frames
			for (int i = 0; i < animationFrameTime.size(); i++)
			{
				if (animationFrameTime.at(i) < 7)
				{
					animationFrameTime.at(i) = (animationFrameTime.at(i) + 1);
					sf::Vector3i v = towerAnimations.at(i);

					switch (v.x)
					{
					case 1:
						explosionSprite.setPosition(v.y, v.z);
						App.draw(explosionSprite);
						break;
					case 2:
						explosionSprite.setPosition(v.y, v.z);
						explosionSprite.setScale(0.8, 0.8);
						App.draw(explosionSprite);
						explosionSprite.setScale(0.6, 0.6);
						break;
					case 3:
						frostAttackSprite.setPosition(v.y, v.z);
						App.draw(frostAttackSprite);
						break;
					case 4:
						fireAttackSprite.setPosition(v.y, v.z);
						App.draw(fireAttackSprite);
						break;
					case 5:
						lightningAttackSprite.setPosition(v.y, v.z);
						App.draw(lightningAttackSprite);
						break;
						break;
					}
				}
				//Lösche die "abgelaufenen Animationen"
				if (animationFrameTime.at(i) >= 7)
				{
					animationFrameTime.erase(animationFrameTime.begin() + i);
					towerAnimations.erase(towerAnimations.begin() + i);
				}
			}

			/*/Lösche die "abgelaufenen Animationen"
			//kA, ob oben ein xout geworfen wird, dann das hier wieder einfügen
			for (int i = 0; i < animationFrameTime.size(); i++)
			{
				if (animationFrameTime.at(i) >= 7)
				{
					animationFrameTime.erase(animationFrameTime.begin() + i);
					towerAnimations.erase(towerAnimations.begin() + i);
				}
			}*/

			//Lösche alle Gegner mit Null oder weniger Lebenspunkten
			for (unsigned int i = 0; i < enemyActiveVector->size(); i++)
			{
				if (enemyActiveVector->at(i)->eGetCurrentLife() <= 0) {
					enemyActiveVector->erase((enemyActiveVector->begin() + i));
					punkteZahl += 100;
					gold += 20;
				}
			}

			//Starte die Buildingsphase falls alle Gegner zerstört oder im Ziel sind			
			if (enemyActiveVector->empty() && enemyVector->empty())
			{
				TimerText.setFillColor(color.Black);
				if (enemyActiveVector->empty() && enemyVector->empty())
				{
					gameState = BuildingPhase;
					buildingphaseCountdown = 20;
				}
			}

			//Beende das Spiel mit GameOver-Screen falls der Spieler keine Lebenspunkte mehr hat			
			if (playerLife <= 0)
			{
				TowerVector->clear();
				gameState = GameOver;
			}
		}

		/*

					GAMEOVER

		*/
		if (gameState == GameOver)
		{
			App.close();

			EndScreen screen;

			while (screen.isRunning())
			{
				screen.Run(true);
			}
		}



		if (gameState == Winning)
		{
			App.close();

			EndScreen screen;

			while (screen.isRunning())
			{
				screen.Run(false);
			}
		}


		//Zeichne alles, was immer dargestellt werden soll, oberer Layer.	
		DrawTower(TowerVector);

		//Beendet und zeichnet den aktuellen Frame		
		App.display();
	}
}

void Game::DrawGameTextures(sf::Sprite &hudSprite, sf::Sprite &statusSprite,
	sf::Text &rundenText, sf::Text &goldText, sf::Text &lebenText,
	sf::Sprite &basicTurmImage, sf::Sprite &cannonTurmImage, sf::Sprite &frostTurmImage,
	sf::Sprite &feuerTurmImage, sf::Sprite &lightningTowerImage, sf::Sprite &soundOnButton, sf::Sprite &soundOffButton, sf::Text &TimerText, sf::Text &punktZahlText, sf::Text &descriptionText, sf::Text &punktText)
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
	App.draw(soundOnButton);
	App.draw(soundOffButton);
	App.draw(TimerText);
	App.draw(punktZahlText);
	App.draw(descriptionText);
	App.draw(punktText);
}

// TowerAttack:
// Ruft für alle Türme die checkForEnemies()-Funktion auf.
// Werden angreifbare Gegner gefunden so wird diesen Schaden zugefügt und die Position für die Angriffsanimation
// in den animations-vector geschrieben. Dieser wird am Ende zurückgegeben.
vector<sf::Vector3i> Game::TowerAttack(std::vector<BasicTower *> * BasicTowerVector, std::vector<BasicEnemy *> * enemyActiveVector,
	sf::Sprite &explosionSprite, sf::Sprite &lightningAttackSprite, sf::Sprite &fireAttackSprite, sf::Sprite &frostAttackSprite)
{
	vector<int> targets;
	vector<sf::Vector3i> animations;
	if (!enemyActiveVector->empty())
	{
		for (int i = 0; i < BasicTowerVector->size(); i++)
		{
			//Sucht nach angreifbaren Gegnern und schreibt diese in den targets-Vector
			targets = BasicTowerVector->at(i)->checkForEnemies(enemyActiveVector);
			if (!targets.empty())
			{
				for (int j = 0; j < targets.size(); j++)
				{
					int k = targets.at(j);
					{
						//Fügt den Gegner im targets-Vector Schaden zufügen
						enemyActiveVector->at(k)->takeDamage(BasicTowerVector->at(i)->getDamage());

						//Falls ein Frosttower angreift, verlangsame den Gegner
						int type = BasicTowerVector->at(i)->getType();
						if (type == 3 && enemyActiveVector->at(k)->eGetFrozenTimer() == 0)
						{
							enemyActiveVector->at(k)->eSetMovementSpeed(enemyActiveVector->at(k)->eGetMovementSpeed() - 1);
							enemyActiveVector->at(k)->eSetFrozenTimer(1);
						}

						//Füge die Koordinaten und den Towertyp für die Animationen zum Animationsvector hinzufügen
						sf::Vector3i v1;
						v1.x = type;
						v1.y = enemyActiveVector->at(k)->eGetXCoord();
						v1.z = enemyActiveVector->at(k)->eGetYCoord();
						animations.push_back(v1);
					}
				}
			}
		}
	}
	//Gibt den Vector mit Informationen über die darzustellenden Angriffsanimationen zurück
	return animations;
}

void Game::SetInfoText(sf::Text &goldText, int gold, sf::Text &rundenText, int runde, sf::Text &TimerText, int timerText, sf::Text &lebenText, int playerLife)
{
	goldText.setString(to_string(gold));
	rundenText.setString(to_string(runde));
	TimerText.setString(to_string(timerText));
	lebenText.setString(to_string(playerLife));
}


void Game::LoadExplosionTextures(sf::Texture &explosionTexture, sf::Sprite &explosionSprite, sf::Texture &frostAttackTexture, sf::Sprite &frostAttackSprite,
	sf::Texture &fireAttackTexture, sf::Sprite &fireAttackSprite, sf::Texture &lightningAttackTexture, sf::Sprite &lightningAttackSprite)
{
	explosionTexture.loadFromFile("ArtAssets/SFX/explosion2.png");
	explosionSprite.setTexture(explosionTexture);
	explosionSprite.setOrigin(64, 64);
	explosionSprite.setScale(0.6, 0.6);

	lightningAttackTexture.loadFromFile("ArtAssets/SFX/lightningExplosion.png");
	lightningAttackSprite.setTexture(lightningAttackTexture);
	lightningAttackSprite.setOrigin(64, 64);
	lightningAttackSprite.setScale(0.6, 0.6);

	fireAttackTexture.loadFromFile("ArtAssets/SFX/fire.png");
	fireAttackSprite.setTexture(fireAttackTexture);
	fireAttackSprite.setOrigin(30, 30);

	frostAttackTexture.loadFromFile("ArtAssets/SFX/ice.png");
	frostAttackSprite.setTexture(frostAttackTexture);
	frostAttackSprite.setScale(0.6, 0.6);
	frostAttackSprite.setOrigin(35, 35);
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
	descriptionText.setCharacterSize(25);
	descriptionText.setPosition(80, 850);
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
	TimerText.setCharacterSize(40);
	TimerText.setPosition(25, 780);
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
		std::cout << "Es konnte keine Fontdatei gefunden werden!" << std::endl;
	}
}

void Game::LoadLifeBarTextures(sf::Texture &hundredLifeTexture,
	sf::Texture &eightyLifeTexture, sf::Texture &sixtyLifeTexture,
	sf::Texture &fortyLifeTexture, sf::Texture &twentyLifeTexture, sf::Texture &tenLifeTexture, sf::Sprite &lifeEnemySprite)
{
	hundredLifeTexture.loadFromFile("ArtAssets/Lifebar/100percent.png");

	eightyLifeTexture.loadFromFile("ArtAssets/Lifebar/80percent.png");
	sixtyLifeTexture.loadFromFile("ArtAssets/Lifebar/60percent.png");
	fortyLifeTexture.loadFromFile("ArtAssets/Lifebar/40percent.png");
	twentyLifeTexture.loadFromFile("ArtAssets/Lifebar/20percent.png");
	tenLifeTexture.loadFromFile("ArtAssets/Lifebar/10percent.png");
	lifeEnemySprite.setOrigin(20, 2);
}

void Game::DrawTower(std::vector<BasicTower *> * BasicTowerVector)
{
	for (unsigned int i = 0; i < BasicTowerVector->size(); i++)
	{
		App.draw(BasicTowerVector->at(i)->getSprite());
	}
}

void Game::UpdateEnemyLifeBar(std::vector<BasicEnemy *> * enemyActiveVector,
	int i, int &punkteZahl, int &gold, int &x, int &y, sf::Sprite &lifeEnemySprite,
	sf::Texture &hundredLifeTexture, sf::Texture &eightyLifeTexture, sf::Texture &sixtyLifeTexture,
	sf::Texture &fortyLifeTexture, sf::Texture &twentyLifeTexture, sf::Texture &tenLifeTexture, sf::Text &punktZahlText)
{
	x = enemyActiveVector->at(i)->eGetXCoord();
	y = enemyActiveVector->at(i)->eGetYCoord();
	double lifePercent = (((enemyActiveVector->at(i)->eGetCurrentLife() / enemyActiveVector->at(i)->eGetMaxLife())) * 100);
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

bool Game::isRunning()
{
	return running;
}


