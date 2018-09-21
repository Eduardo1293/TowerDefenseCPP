#include "Game.h"
#include <list>
#include <vector>
#include "PlayingField.cpp"
#include "BasicTower.h"
#include "EnemyWaves.h"

#include <iostream>


Game::Game()
{
	name = "Lennard is kacke.exe";
	App.create(sf::VideoMode(512, 896), name, sf::Style::Close);
	running = true;

}

bool buildingphase = true;
Game::~Game()
{
}

void Game::Run()
{
	sf::Clock clock;
	App.setFramerateLimit(24);
	int x;
	int y;

	//bool für gegnerphase oder bauphase

	

	int gameTime = 0;

	vector<DummyEnemy*> *enemyVector = new vector<DummyEnemy*>();
	vector<DummyEnemy*> *enemyActiveVector = new vector<DummyEnemy*>();
	*enemyVector = enemyWaves(1);

	int gameTimeEnemyCounter = 1;
	int waveEnemyAddedCounter = 0;

	//Testturm und Testgegner, testgegner ist hardgecodet, dass er einen bestimmten weg abfährt
	sf::Texture testTurmTexture;
	testTurmTexture.loadFromFile("ArtAssets/Tower/tank_dark.png");
	sf::Sprite testTurmSprite;
	sf::Sprite testEnemySprite;
	testEnemySprite.setTexture(testTurmTexture);

	//halbdurchsichtiger tower zum bauen
	sf::Sprite buildTowerSprite;
	buildTowerSprite.setTexture(testTurmTexture);
	buildTowerSprite.setColor(sf::Color(255, 255, 255, 140));
	buildTowerSprite.setOrigin(32, 32);

	//lifebar
	sf::Texture hundredLifeTexture;
	hundredLifeTexture.loadFromFile("ArtAssets/Lifebar/100percent.png");
	sf::Texture ninetyLifeTexture;
	ninetyLifeTexture.loadFromFile("ArtAssets/Lifebar/90percent.png");
	sf::Texture eightyLifeTexture;
	eightyLifeTexture.loadFromFile("ArtAssets/Lifebar/80percent.png");
	sf::Texture seventyLifeTexture;
	seventyLifeTexture.loadFromFile("ArtAssets/Lifebar/70percent.png");
	sf::Texture sixtyLifeTexture;
	sixtyLifeTexture.loadFromFile("ArtAssets/Lifebar/60percent.png");
	sf::Texture fiftyLifeTexture;
	fiftyLifeTexture.loadFromFile("ArtAssets/Lifebar/50percent.png");
	sf::Texture fortyLifeTexture;
	fortyLifeTexture.loadFromFile("ArtAssets/Lifebar/40percent.png");
	sf::Texture thirtyLifeTexture;
	thirtyLifeTexture.loadFromFile("ArtAssets/Lifebar/30percent.png");
	sf::Texture twentyLifeTexture;
	twentyLifeTexture.loadFromFile("ArtAssets/Lifebar/20percent.png");
	sf::Texture tenLifeTexture;
	tenLifeTexture.loadFromFile("ArtAssets/Lifebar/10percent.png");
	sf::Sprite lifeEnemySprite;
	lifeEnemySprite.setTexture(fiftyLifeTexture);
	lifeEnemySprite.setOrigin(20, 2);

	sf::Color color;
	sf::Font font;
	if (!font.loadFromFile("ArtAssets/impact.ttf"))
	{
		std::cout << "Es konnte keine Fontdatei geunden werden!" << std::endl;
	}

	sf::Texture kanonenTurmButton;
	sf::Sprite kanonenTurmImage;

	kanonenTurmButton.loadFromFile("ArtAssets/Tower/tank_dark.png");
	kanonenTurmImage.setPosition(78, 779);

	kanonenTurmImage.setTexture(kanonenTurmButton);
	
	float kanonenTurmButtonWidth = kanonenTurmImage.getLocalBounds().width;
	float kanonenTurmButtonHeight = kanonenTurmImage.getLocalBounds().height;


	//Feuerturmbutton
	sf::Texture feuerTurmButton;
	sf::Sprite feuerTurmImage;

	feuerTurmButton.loadFromFile("ArtAssets/Tower/tank_dark.png");
	feuerTurmImage.setPosition(151, 779);

	feuerTurmImage.setTexture(feuerTurmButton);

	float feuerTurmButtonWidth = feuerTurmImage.getLocalBounds().width;
	float feuerTurmButtonHeight = feuerTurmImage.getLocalBounds().height;


	//Frostturmbutton
	sf::Texture frostTurmButton;
	sf::Sprite frostTurmImage;

	frostTurmButton.loadFromFile("ArtAssets/Tower/tank_dark.png");
	frostTurmImage.setPosition(224, 779);

	frostTurmImage.setTexture(frostTurmButton);

	float frostTurmButtonWidth = frostTurmImage.getLocalBounds().width;
	float frostTurmButtonHeight = frostTurmImage.getLocalBounds().height;

	//Turm 3
	sf::Texture Turm3Button;
	sf::Sprite Turm3Image;

	Turm3Button.loadFromFile("ArtAssets/Tower/tank_dark.png");
	Turm3Image.setPosition(297, 779);

	Turm3Image.setTexture(Turm3Button);

	float Turm3ButtonWidth = Turm3Image.getLocalBounds().width;
	float Turm3ButtonHeight = Turm3Image.getLocalBounds().height;


	//Turm 4
	sf::Texture Turm4Button;
	sf::Sprite Turm4Image;

	Turm4Button.loadFromFile("ArtAssets/Tower/tank_dark.png");
	Turm4Image.setPosition(368, 779);

	Turm4Image.setTexture(Turm4Button);

	float Turm4ButtonWidth = Turm4Image.getLocalBounds().width;
	float Turm4ButtonHeight = Turm4Image.getLocalBounds().height;

	int gold = 20000;
	int runde = 0;
	int timerText = 0;
	int playerLife = 20;
	int punkteZahl = 0;
	sf::Text rundenText;
	rundenText.setFont(font);	
	rundenText.setFillColor(color.Black);
	rundenText.setCharacterSize(13);
	rundenText.setPosition(65, 15);


	sf::Text goldText;
	goldText.setFont(font);
	
	goldText.setFillColor(color.Black);
	goldText.setCharacterSize(13);
	goldText.setPosition(65, 35);


	sf::Text TimerText;
	TimerText.setFont(font);		
	TimerText.setCharacterSize(30);
	TimerText.setPosition(250, 850);
	TimerText.setFillColor(color.Black);

	sf::Text lebenText;
	lebenText.setFont(font);
	lebenText.setString(to_string(playerLife));
	lebenText.setFillColor(color.Black);
	lebenText.setCharacterSize(13);
	lebenText.setPosition(360, 16);

	sf::Text punktText;
	punktText.setFont(font);
	punktText.setString("PUNKTE:");
	punktText.setFillColor(color.Black);
	punktText.setCharacterSize(13);
	punktText.setPosition(308, 32);

	sf::Text punktZahlText;
	punktZahlText.setFont(font);
	punktZahlText.setString(to_string(punkteZahl));
	punktZahlText.setFillColor(color.Black);
	punktZahlText.setCharacterSize(13);
	punktZahlText.setPosition(370, 32);

	sf::Texture statusTexture;
	statusTexture.loadFromFile("ArtAssets/Status.png");

	sf::Texture hudTexture;
	hudTexture.loadFromFile("ArtAssets/HUD.png");

	sf::Sprite hudSprite;
	hudSprite.setTexture(hudTexture);
	hudSprite.setPosition(0, 768);

	sf::Sprite statusSprite;
	statusSprite.setTexture(statusTexture);
	statusSprite.setPosition(0, 0);

	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("ArtAssets/Nebula Blue_Background.png");
	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(0, 64);

	//explosion
	sf::Texture explosionTexture;
	explosionTexture.loadFromFile("ArtAssets/SFX/explosion2.png");
	sf::Sprite explosionSprite;
	explosionSprite.setTexture(explosionTexture);
	explosionSprite.setOrigin(64, 64);
	explosionSprite.setScale(0.5, 0.5);

	testTurmSprite.setTexture(testTurmTexture);
	testTurmSprite.setOrigin(32, 32);

	sf::Texture emptySpaceTexture;
	sf::Texture blockedSpaceTexture;
	emptySpaceTexture.loadFromFile("ArtAssets/emptyspace.png");
	blockedSpaceTexture.loadFromFile("ArtAssets/blockedspace.png");



	sf::Sprite emptySpaceSprite;
	sf::Sprite blockedSpaceSprite;
	emptySpaceSprite.setTexture(emptySpaceTexture);
	emptySpaceSprite.setColor(sf::Color(255, 255, 255, 128));
	emptySpaceSprite.setOrigin(32, 32);
	blockedSpaceSprite.setTexture(blockedSpaceTexture);
	blockedSpaceSprite.setColor(sf::Color(255, 255, 255, 128));
	blockedSpaceSprite.setOrigin(32, 32);

	testEnemySprite.setOrigin(32, 32);

	/*for each (PropertyInfo prop in typeof(PlayingField))
	{
		this.playingFieldList.Add(prop)
	}*/

	list<GameArea*> GameAreaList = PlayingField();
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
		App.clear(sf::Color::Black);

		// draw everything here...
		// window.draw(...);
		//Background

		//male alles was immer dargestellt wird immer, unterer layer:

		App.draw(backgroundSprite); 

		goldText.setString(to_string(gold));
		rundenText.setString(to_string(runde));
		TimerText.setString(to_string(timerText));
		App.draw(hudSprite);
		App.draw(statusSprite);
		App.draw(rundenText);
		App.draw(goldText);
		App.draw(lebenText);
		App.draw(kanonenTurmImage);
		App.draw(feuerTurmImage);
		App.draw(frostTurmImage);
		App.draw(Turm3Image);
		App.draw(Turm4Image);
		App.draw(TimerText);
		App.draw(punktZahlText);
		App.draw(punktText);

		//Gegnerphase / Bauphase unterscheidung hier!
		//manches muss immer dargestellt werden, anderes nur in der entsprechenden phase
		
		if (buildingphase) {						

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
				TimerText.setColor(color.Red);				
				
			}
			if (buildingphaseCountdown == 0)
			{
				buildingphase = false;
				TimerText.setColor(sf::Color(255, 255, 255, 140));
				buildphaseElapsedTimeBuffer = 0;
				clock.restart();
			}

			{
			
		sf::Vector2i localPosition = sf::Mouse::getPosition(App);
		sf::Vector2f mousePosF(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y));
		sf::Event Event;

		//freie und belegte felder markieren
		for (list<GameArea*>::const_iterator pos = GameAreaList.begin(); pos != GameAreaList.end(); ++pos) {

			if ((*pos)->getEmpty()) {
				emptySpaceSprite.setPosition((*pos)->getAreaXCoord(), (*pos)->getAreaYCoord());
				App.draw(emptySpaceSprite);
			}
			else {
				blockedSpaceSprite.setPosition((*pos)->getAreaXCoord(), (*pos)->getAreaYCoord());
				App.draw(blockedSpaceSprite);
			}

			//mouse-movement auslesen
			if (localPosition.x <= ((*pos)->getAreaXCoord() + 32) && (localPosition.x >= ((*pos)->getAreaXCoord() - 31))
				&& (localPosition.y <= ((*pos)->getAreaYCoord() + 32)) && (localPosition.y >= ((*pos)->getAreaYCoord() - 31))) {
				buildTowerSprite.setPosition((*pos)->getAreaXCoord(), (*pos)->getAreaYCoord());
				App.draw(buildTowerSprite);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (localPosition.x <= ((*pos)->getAreaXCoord() + 32) && (localPosition.x >= ((*pos)->getAreaXCoord() - 31))
					&& (localPosition.y <= ((*pos)->getAreaYCoord() + 32)) && (localPosition.y >= ((*pos)->getAreaYCoord() - 31))) {
					BasicTower *Tower = new BasicTower(((*pos)->getAreaXCoord()), (*pos)->getAreaYCoord());
					TowerVector->push_back(Tower);
					(*pos)->setAreaEmpty(false);
					gold = gold - Tower->getCost();
				}
			}
		}


				//buttons interface
				if (kanonenTurmImage.getGlobalBounds().contains(mousePosF))
				{
					kanonenTurmImage.setTexture(kanonenTurmButton);
					kanonenTurmImage.setColor(sf::Color(255, 255, 255, 140));
				}
				else
				{
					kanonenTurmImage.setTexture(kanonenTurmButton);
					kanonenTurmImage.setColor(color.White);
				}
				if (feuerTurmImage.getGlobalBounds().contains(mousePosF))
				{
					feuerTurmImage.setTexture(feuerTurmButton);
					feuerTurmImage.setColor(sf::Color(255, 255, 255, 140));
				}
				else
				{
					feuerTurmImage.setTexture(feuerTurmButton);
					feuerTurmImage.setColor(color.White);
				}
				if (frostTurmImage.getGlobalBounds().contains(mousePosF))
				{
					frostTurmImage.setTexture(frostTurmButton);
					frostTurmImage.setColor(sf::Color(255, 255, 255, 140));
				}
				else
				{
					frostTurmImage.setTexture(frostTurmButton);
					frostTurmImage.setColor(color.White);
				}


				if (Turm3Image.getGlobalBounds().contains(mousePosF))
				{
					Turm3Image.setTexture(Turm3Button);
					Turm3Image.setColor(sf::Color(255, 255, 255, 140));
				}
				else
				{
					Turm3Image.setTexture(Turm3Button);
					Turm3Image.setColor(color.White);
				}


				if (Turm4Image.getGlobalBounds().contains(mousePosF))
				{
					Turm4Image.setTexture(Turm4Button);
					Turm4Image.setColor(sf::Color(255, 255, 255, 140));
				}
				else
				{
					Turm4Image.setTexture(Turm4Button);
					Turm4Image.setColor(color.White);
				}
			}		
		}
		else {
			
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
				for (unsigned int i = 0; i < TowerVector->size(); i++) {
					int target = TowerVector->at(i)->checkForEnemies(enemyActiveVector);
					if (target >= 0 && target <= 9 && enemyActiveVector->at(target)->getCurrentLife() > 0) {
						enemyActiveVector->at(target)->takeDamage(TowerVector->at(i)->getDamage());
						explosionSprite.setPosition(enemyActiveVector->at(target)->getXCoord(), enemyActiveVector->at(target)->getYCoord());
						App.draw(explosionSprite);						
					}
				}
			}
			

			TimerText.setFillColor(color.Black);
			//buildingphase = true;
		}

		//male alles was immer dargestellt wird immer, oberer layer:

		for (unsigned int i = 0; i < TowerVector->size(); i++)
		{
			App.draw(TowerVector->at(i)->getSprite());
		}

		
	

		//testgegner bewegungskram
		enemyMovementClock.getElapsedTime();
		sf::Time enemyMovementElapsed = enemyMovementClock.getElapsedTime();
		int movementElapsed = enemyMovementElapsed.asMilliseconds();		
			for (int i = 0; i < enemyActiveVector->size(); i++) {
				if (enemyActiveVector->at(i)->getCurrentLife() == 0) {
					enemyActiveVector->erase((enemyActiveVector->begin() + i));
					punkteZahl += 100;
					gold += 100;
				}
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
				App.draw(enemyActiveVector->at(i)->getSprite());
				App.draw(lifeEnemySprite);					
		}

		if (playerLife == 0)
		{
			App.clear();
		}


		// end the current frame
		App.display();

	}
}


bool Game::isRunning()
{
	return running;
}


