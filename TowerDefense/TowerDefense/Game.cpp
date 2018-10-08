/*
Hier Sachen reinschrieben, die noch gemacht werden müssen!
-Problem mit PlayingField beheben.
-gucken ob clock verwendet wird X
-update movement ist momentan komisch, timer außerhalb der methode überprüfen
-wir benutzen nicht alle life%, life% aufräumen
-eine der distanzen in gamearea ist unnütz, beizeiten aufräumen :D und die namen sind komisch
-sollte bei den neuen türmen der tower nicht innerhalb der if-abfrage erstellt werden?
*/



#include "Game.h"
#include <list>
#include <vector>
#include "GameMap.h"
#include "BasicTower.h"
#include "EnemyWaves.h"
#include "Menu.h"
#include "BasicButton.h"
#include "PathFinding.cpp"
#include "CustomException.h"
#include <iostream>
#include <map>


Game::Game()
{
	sf::Image GameIcon;
	GameIcon.loadFromFile("ArtAssets/gameIcon.png");
	name = "Lennard is kacke.exe";
	App.create(sf::VideoMode(512, 896), name, sf::Style::Close);
	App.setIcon(GameIcon.getSize().x, GameIcon.getSize().y, GameIcon.getPixelsPtr());
	running = true;

}

//bool für gegnerphase oder bauphase
bool buildingphase = true;

Game::~Game()
{
}

void Game::Run()
{

	App.setFramerateLimit(24);
	//float x;
	//float y;

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

	//Hintergrundmusik
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;

	if (!soundBuffer.loadFromFile("ArtAssets/Audio/hintergrundmusik.ogg"))
	{
		cout << "Error" << endl;
	}

	sound.setBuffer(soundBuffer);
	sound.setVolume(0);

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
	sf::Texture eightyLifeTexture;
	sf::Texture sixtyLifeTexture;
	sf::Texture fortyLifeTexture;
	sf::Texture twentyLifeTexture;
	sf::Texture tenLifeTexture;
	sf::Sprite lifeEnemySprite;
	sf::Color color;
	sf::Font font;

	sf::Color hoverColer = sf::Color(255, 255, 255, 140);

	LoadLifeBarTextures(hundredLifeTexture, eightyLifeTexture,
		sixtyLifeTexture, fortyLifeTexture,
		twentyLifeTexture, tenLifeTexture, lifeEnemySprite);




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


	GameMap *GameMapRef = new GameMap;
	GameMapRef->setGameMap();
	vector<GameArea*> GameAreaVector = GameMapRef->getGameMap();

	vector<int> path, pathXCoord, pathYCoord, pathDirection;

	PathFinding pathFindingRef;

	vector<BasicTower*> *TowerVector = new vector<BasicTower*>();

	sf::Clock timerClock;

	//phasen-clock
	sf::Clock buildingphaseClock;
	int buildingphaseCountdown = 10;
	int buildphaseElapsedTimeBuffer = 0;

	//attackclock, brauchen wir für tower attacken;
	sf::Clock enemyClock;
	int enemyClockElapsedTimeBuffer = 0;

	//attackclock, brauchen wir für tower attacken;
	sf::Clock attackClock;
	int attackClockElapsedTimeBuffer = 0;

	//enemymovementtick
	sf::Clock enemyMovementClock;
	int movementElapsedBuffer = 0;

	//Hintergrundmusik wird ausgeführt
	sound.play();
	// run the program as long as the window is open
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
		//Background

		//male alles was immer dargestellt wird immer, unterer layer:



		//Gegnerphase / Bauphase unterscheidung hier!
		//manches muss immer dargestellt werden, anderes nur in der entsprechenden phase
		sf::Vector2i localPosition = sf::Mouse::getPosition(App);
		sf::Vector2f mousePosF(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y));

		/*
		Button für Sound On/Off
		*/
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


		if (buildingphase) {
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

			BasicTower * BasicTowerRef;
			CannonTower * CannonTowerRef;
			FlameTower * FlameTowerRef;


			/*
			Beende die Buildingphase. Falls kein Weg gefunden wird, lösche den letzten Tower im Tower-Vector
			bis ein Weg gefunden wurde.
			*/
			if (buildingphaseCountdown == 0)
			{
				buildingphase = false;
				TimerText.setFillColor(hoverColer);
				buildphaseElapsedTimeBuffer = 0;


				try
				{
					path = pathFindingRef.aStar(GameAreaVector);
				}
				catch (CustomException se)
				{
					cout << se.getFehlermeldung() << endl;
				}

				/*
				Hilfsvektoren für die Gegnernavigation
				*/
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

				/*
				Hilfsvektoren für die Gegnernavigation, beinhaltet Richtungsinformationen:
				1=rechts, 2=unten, 3=links, 4=oben
				*/
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

				/*
				Fülle den Gegnervektor mit den Gegnern der nächsten Wave
				*/
				*enemyVector = enemyWaves(1);
				enemyClock.restart();
			}

			/*
			Markiert freie und belegte Felder mit grün bzw. rot.
			*/
			for (int i = 0; i < GameAreaVector.size(); i++) {
				if (GameAreaVector.at(i)->getEmpty()) {
					emptySpaceSprite.setPosition(GameAreaVector.at(i)->getAreaXCoord(), GameAreaVector.at(i)->getAreaYCoord());
					App.draw(emptySpaceSprite);
				}
				else {
					blockedSpaceSprite.setPosition(GameAreaVector.at(i)->getAreaXCoord(), GameAreaVector.at(i)->getAreaYCoord());
					App.draw(blockedSpaceSprite);
				}

				/*
				Funktion um Mausbewegungen auszulesen und eine "Tower-Vorschau" anzuzeigen.
				*/
				if (localPosition.x <= (GameAreaVector.at(i)->getAreaXCoord() + 32) && (localPosition.x >= (GameAreaVector.at(i)->getAreaXCoord() - 31))
					&& (localPosition.y <= (GameAreaVector.at(i)->getAreaYCoord() + 32)) && (localPosition.y >= (GameAreaVector.at(i)->getAreaYCoord() - 31))) {
					buildTowerSprite.setPosition(GameAreaVector.at(i)->getAreaXCoord(), GameAreaVector.at(i)->getAreaYCoord());
					App.draw(buildTowerSprite);
				}

				/*
				Baut beim Mausklick den ausgewählten Tower an der markierten Stelle.
				*/
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (localPosition.x <= (GameAreaVector.at(i)->getAreaXCoord() + 32) && (localPosition.x >= (GameAreaVector.at(i)->getAreaXCoord() - 31))
						&& (localPosition.y <= (GameAreaVector.at(i)->getAreaYCoord() + 32)) && (localPosition.y >= (GameAreaVector.at(i)->getAreaYCoord() - 31))) {

						switch (selectetTower)
						{
						case basicTower:
							BasicTowerRef = new BasicTower((GameAreaVector.at(i)->getAreaXCoord()), GameAreaVector.at(i)->getAreaYCoord(), GameAreaVector.at(i)->getID());
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
							CannonTowerRef = new CannonTower((GameAreaVector.at(i)->getAreaXCoord()), GameAreaVector.at(i)->getAreaYCoord(), GameAreaVector.at(i)->getID());

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
							FlameTowerRef = new FlameTower((GameAreaVector.at(i)->getAreaXCoord()), GameAreaVector.at(i)->getAreaYCoord(), GameAreaVector.at(i)->getID());
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



			if (basicTowerButton.getSprite().getGlobalBounds().contains(mousePosF))
			{
				basicTowerButton.setColor(hoverColer);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					BasicTower test = BasicTower();
					descriptionText.setString(test.getDescription());
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
					descriptionText.setString(CannonTowerRef->getDescription());
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

			/*
			Beendet die Bauphase sobald der Spieler kein Gold mehr hat.
			*/

			if (gold == 0)
			{
				buildingphaseCountdown = 0;
				buildingphase = false;
			}

			if (enemyVector->empty()) {
				*enemyVector = enemyWaves(runde);
				runde++;
			}

		}

		//Gegnerphase
		else {



			descriptionText.setString("");
			//enemyphasenkram
			//berechne weg mit a* hier


			//towermenu durch gegnerwave-anzeige ersetzen fragezeichen?
			//spawne enemies hier	

			//*bumpaffpow ratatatapeng*

			//alle gegner tot oder am ziel:

			//schickt die gegner aus wave1 auf die reise
			//hier ist noch was madig
			sf::Time enemyTime = enemyClock.getElapsedTime();
			if (!enemyVector->empty() && enemyTime.asSeconds() > 1) {
				enemyActiveVector->push_back(enemyVector->at(0));
				enemyVector->erase(enemyVector->begin() + 0);
				enemyClock.restart();
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
			if (enemyActiveVector->empty() && enemyVector->empty()) {
				buildingphase = true;
				buildingphaseCountdown = 30;
			}

			/*
			Movementclock
			*/
			enemyMovementClock.getElapsedTime();
			sf::Time enemyMovementElapsed = enemyMovementClock.getElapsedTime();
			int movementElapsed = enemyMovementElapsed.asMilliseconds();

			/*
			Gegnermovement
			*/
			if (!enemyActiveVector->empty())
			{
				for (unsigned int i = 0; i < enemyActiveVector->size(); i++)
				{
					int mSpeed = enemyActiveVector->at(i)->eGetMovementSpeed();
					int enemyX = enemyActiveVector->at(i)->eGetXCoord();
					int enemyY = enemyActiveVector->at(i)->eGetYCoord();
					int iNavigationhelper = enemyActiveVector->at(i)->eGetNavigationHelper();

					for (unsigned int j = 0; j < mSpeed; j++)
					{
						UpdateEnemyLifeBar(enemyActiveVector, i, punkteZahl, gold, enemyX, enemyY,
							lifeEnemySprite, hundredLifeTexture, eightyLifeTexture,
							sixtyLifeTexture, fortyLifeTexture, twentyLifeTexture,
							tenLifeTexture, punktZahlText);

						/*
						Navigation vom Start auf das erste Spielfeld
						*/
						if (iNavigationhelper == -1)
						{
							lifeEnemySprite.setPosition(enemyX, (enemyY - 25));
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
						Navigation von Feld 0 auf Feld 62, dem Pathfinding folgend
						*/
						if (iNavigationhelper >= 0 && iNavigationhelper < (path.size() - 1))
						{
							int iSwitch = pathDirection.at(iNavigationhelper);
							int iSwitchPlusOne = pathDirection.at(iNavigationhelper + 1);

							switch (iSwitch) {

								//movement nach rechts
							case 1:
								lifeEnemySprite.setPosition(enemyX, (enemyY - 25));
								enemyActiveVector->at(i)->eSetXCoord(enemyX + 1);
								//enemy globallocation updaten, wenn in neuem feld
								if (enemyActiveVector->at(i)->eGetGlobalLocation() != path.at(iNavigationhelper + 1)
									&& (enemyActiveVector->at(i)->eGetXCoord() >= (pathXCoord.at(iNavigationhelper + 1) - 32)))
								{
									enemyActiveVector->at(i)->eSetGlobalLocation(path.at(iNavigationhelper + 1));
								}
								//richtung ändern
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

								//movement nach unten
							case 2:
								lifeEnemySprite.setPosition(enemyX, (enemyY - 25));
								enemyActiveVector->at(i)->eSetYCoord(enemyY + 1);
								//enemy globallocation updaten, wenn in neuem feld
								if (enemyActiveVector->at(i)->eGetGlobalLocation() != path.at(iNavigationhelper + 1)
									&& (enemyActiveVector->at(i)->eGetYCoord() > (pathXCoord.at(iNavigationhelper + 1) - 32)))
								{
									enemyActiveVector->at(i)->eSetGlobalLocation(path.at(iNavigationhelper + 1));
								}
								//richtung ändern
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

								//movement nach links
							case 3:
								lifeEnemySprite.setPosition(enemyX, (enemyY - 25));
								enemyActiveVector->at(i)->eSetXCoord(enemyX - 1);
								//enemy globallocation updaten, wenn in neuem feld
								if (enemyActiveVector->at(i)->eGetGlobalLocation() != path.at(iNavigationhelper + 1)
									&& (enemyActiveVector->at(i)->eGetXCoord() <= (pathXCoord.at(iNavigationhelper + 1) + 32)))
								{
									enemyActiveVector->at(i)->eSetGlobalLocation(path.at(iNavigationhelper + 1));
								}
								//richtung ändern
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

								//movement nach oben
							case 4:
								lifeEnemySprite.setPosition(enemyX, (enemyY - 25));
								enemyActiveVector->at(i)->eSetYCoord(enemyY - 1);
								//enemy globallocation updaten, wenn in neuem feld
								if (enemyActiveVector->at(i)->eGetGlobalLocation() != path.at(iNavigationhelper + 1)
									&& (enemyActiveVector->at(i)->eGetYCoord() <= (pathYCoord.at(iNavigationhelper + 1) + 32)))
								{
									enemyActiveVector->at(i)->eSetGlobalLocation(path.at(iNavigationhelper + 1));
								}
								//richtung ändern
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

							default: break;

							}
						}

						/*
						Navigation vom letzten Spielfeld zum Ausgang
						*/
						if (iNavigationhelper == (path.size() - 1))
						{
							lifeEnemySprite.setPosition(enemyX, (enemyY - 25));
							(enemyActiveVector->at(i)->eSetYCoord(enemyY + 1));
							if (enemyY > 734 && enemyActiveVector->at(i)->eGetGlobalLocation() == 62)
							{
								enemyActiveVector->at(i)->eSetGlobalLocation(999);
							}
							if (enemyY >= 750)
							{
								enemyActiveVector->erase((enemyActiveVector->begin() + i));
							}
						}

						/*
						Zeichne die Gegner und ihre Lifebar an den aktuellen Positionen
						*/
						if (!enemyActiveVector->empty())
						{
							enemyActiveVector->at(i)->eSetPosition();
							App.draw(enemyActiveVector->at(i)->eGetSprite());
							App.draw(lifeEnemySprite);
						}
						else
						{
							break;
						}
					}
				}
			}

			
			/*
			Starte die Buildingsphase falls alle Gegner zerstört oder im Ziel sind
			*/
			if (enemyActiveVector->empty() && enemyVector->empty())
			{
				TimerText.setFillColor(color.Black);
				if (enemyActiveVector->empty() && enemyVector->empty())
				{
					buildingphase = true;
					buildingphaseCountdown = 30;
				}
			}

			/*
			Beende das Spiel falls der Spieler keine Lebenspunkte mehr hat
			*/
			if (playerLife <= 0)
			{
				ShowGameOverScreen(font, color, backgroundTexture, backgroundSprite, playerInput, playerText);
			}

		}

		/*
		Zeichne alles, was immer dargestellt werden soll, oberer Layer.
		*/
		DrawTower(TowerVector);


		/*
		Beendet und zeichnet den aktuellen Frame
		*/
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

void Game::SetInfoText(sf::Text &goldText, int gold, sf::Text &rundenText, int runde, sf::Text &TimerText, int timerText, sf::Text &lebenText, int playerLife)
{
	goldText.setString(to_string(gold));
	rundenText.setString(to_string(runde));
	TimerText.setString(to_string(timerText));
	lebenText.setString(to_string(playerLife));
}

//irgendwas funktioniert hier nicht, stehe übelst auf dem schlauch
//FUAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACK
void Game::TowerAnimation(std::vector<BasicTower *> * BasicTowerVector,
	std::vector<BasicEnemy *> * enemyActiveVector, sf::Sprite &explosionSprite)
{
	vector<int> targets;
	if (!enemyActiveVector->empty())
	{
		for (int i = 0; i < BasicTowerVector->size(); i++)
		{
			//targets.clear();
			targets = BasicTowerVector->at(i)->checkForEnemies(enemyActiveVector);
			if (!targets.empty())
			{
				for (int j = 0; j < targets.size(); j++)
				{
					int k = targets.at(j);
					if (k != 999)
					{
						//Schaden zufügen
						enemyActiveVector->at(k)->takeDamage(BasicTowerVector->at(i)->getDamage());

						//Angriffs-"SFX"
						int towerType = BasicTowerVector->at(i)->getType();
						switch (towerType)
						{
						//Attacktower
						case 1:
							explosionSprite.setPosition(enemyActiveVector->at(k)->eGetXCoord(), enemyActiveVector->at(k)->eGetYCoord());
							App.draw(explosionSprite);
							break;

						//Cannontower
						case 2:
							explosionSprite.setPosition(enemyActiveVector->at(k)->eGetXCoord(), enemyActiveVector->at(k)->eGetYCoord());
							App.draw(explosionSprite);
							break;
						
						//Frosttower
						case 3:

							//hier noch slow einbauen?!
							break;

						//Flametower
						case 4:


							break;

						//Lightningtower
						case 5:


							break;
						}
					}
				}
			}
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
		std::cout << "Es konnte keine Fontdatei geunden werden!" << std::endl;
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

void Game::UpdateEnemyMovement(int movementElapsed, int movementElapsedBuffer,
	sf::Clock &enemyMovementClock, std::vector<BasicEnemy *> * enemyActiveVector,
	int i, float y, float x, sf::Sprite &lifeEnemySprite, int &playerLife, sf::Text &lebenText,
	vector<GameArea*>& playingfield, vector<int> &path)
{
	GameMap *GameMapRef = new GameMap;
	GameMapRef->setGameMap();
	vector<GameArea*> GameAreaVector = GameMapRef->getGameMap();

	/*if ((movementElapsed + movementElapsedBuffer) >= 25) {
	enemyMovementClock.restart();
	enemyActiveVector->at(i)->eSetPosition();
	*/

	if (!enemyActiveVector->empty())
	{
		if (y < 191) {
			lifeEnemySprite.setPosition(x, (y - 25));
			(enemyActiveVector->at(i)->eSetYCoord((y + 1)));
		}
		if (y >= 703) {
			enemyActiveVector->erase((enemyActiveVector->begin() + i));
			playerLife -= 1;
		}
		if (y >= 191) {
			for (int j = 0; j < (path.size() - 1); j++) {

				int pathXCoord = GameAreaVector.at(path.at(j))->getAreaXCoord();
				int pathPlusOneXCoord = GameAreaVector.at(path.at(j + 1))->getAreaXCoord();
				int pathYCoord = GameAreaVector.at(path.at(j))->getAreaYCoord();
				int pathPlusOneYCoord = GameAreaVector.at(path.at(j + 1))->getAreaYCoord();

				if ((x >= pathXCoord) && (x < pathPlusOneXCoord)
					&& (y == pathYCoord))
				{
					lifeEnemySprite.setPosition(x, (y - 25));
					enemyActiveVector->at(i)->eSetXCoord((x + 1));
					enemyActiveVector->at(i)->eSetRotation(270);
					break;
				}
				if ((x <= pathXCoord) && (x > pathPlusOneXCoord)
					&& (y == pathYCoord))
				{
					lifeEnemySprite.setPosition(x, (y - 25));
					enemyActiveVector->at(i)->eSetXCoord((x - 1));
					enemyActiveVector->at(i)->eSetRotation(90);
					break;
				}
				if ((y >= pathYCoord) && (y < pathPlusOneYCoord)
					&& (x == pathXCoord))
				{
					lifeEnemySprite.setPosition(x, (y - 25));
					enemyActiveVector->at(i)->eSetYCoord((y + 1));
					enemyActiveVector->at(i)->eSetRotation(0);
					break;
				}
				if ((y <= pathYCoord) && (y > pathPlusOneYCoord)
					&& (x == pathXCoord))
				{
					lifeEnemySprite.setPosition(x, (y - 25));
					enemyActiveVector->at(i)->eSetYCoord((y - 1));
					enemyActiveVector->at(i)->eSetRotation(180);
					break;
				}
			}
		}
		if (!enemyActiveVector->empty())
		{
			try
			{
				enemyActiveVector->at(i)->eSetPosition();
			}
			catch (CustomException e)
			{
				cout << e.getFehlermeldung() << endl;
			}

		}
	}
}

void Game::UpdateEnemyLifeBar(std::vector<BasicEnemy *> * enemyActiveVector,
	int i, int &punkteZahl, int &gold, int &x, int &y, sf::Sprite &lifeEnemySprite,
	sf::Texture &hundredLifeTexture, sf::Texture &eightyLifeTexture, sf::Texture &sixtyLifeTexture,
	sf::Texture &fortyLifeTexture, sf::Texture &twentyLifeTexture, sf::Texture &tenLifeTexture, sf::Text &punktZahlText)
{
	if (enemyActiveVector->at(i)->eGetCurrentLife() == 0) {
		enemyActiveVector->erase((enemyActiveVector->begin() + i));
		punkteZahl += 100;
		gold += 100;
	}
	else {
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


