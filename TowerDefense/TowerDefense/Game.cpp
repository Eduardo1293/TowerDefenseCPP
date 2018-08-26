#include "Game.h"
#include "GameArea.h"
#include <list>
#include <vector>

Game::Game()
{
	name = "Lennard is kacke.exe";
	App.create(sf::VideoMode(512, 896), name, sf::Style::Close);
	running = true;

}

Game::~Game()
{
}

void gameAreas() {
	
}

void Game::Run()
{
	App.setFramerateLimit(24);
	int x = 63;
	int y = 96;
	
	//erste zeile von links nach rechts
	GameArea *AA = new GameArea(false, 63, 191);
	GameArea *BA = new GameArea(true, 127, 191);
	GameArea *CA = new GameArea(true, 191, 191);
	GameArea *DA = new GameArea(true, 255, 191);
	GameArea *EA = new GameArea(true, 319, 191);
	GameArea *FA = new GameArea(true, 383, 191);
	GameArea *GA = new GameArea(true, 447, 191);

	//zweite zeile von links nach rechts
	GameArea *AB = new GameArea(true, 63, 255);
	GameArea *BB = new GameArea(true, 127, 255);
	GameArea *CB = new GameArea(true, 191, 255);
	GameArea *DB = new GameArea(true, 255, 255);
	GameArea *EB = new GameArea(true, 319, 255);
	GameArea *FB = new GameArea(true, 383, 255);
	GameArea *GB = new GameArea(true, 447, 255);

	//dritte zeile von links nach rechts
	GameArea *AC = new GameArea(true, 63, 319);
	GameArea *BC = new GameArea(true, 127, 319);
	GameArea *CC = new GameArea(true, 191, 319);
	GameArea *DC = new GameArea(true, 255, 319);
	GameArea *EC = new GameArea(true, 319, 319);
	GameArea *FC = new GameArea(true, 383, 319);
	GameArea *GC = new GameArea(true, 447, 319);

	//vierte zeile von links nach rechts
	GameArea *AD = new GameArea(true, 63, 383);
	GameArea *BD = new GameArea(true, 127, 383);
	GameArea *CD = new GameArea(true, 191, 383);
	GameArea *DD = new GameArea(true, 255, 383);
	GameArea *ED = new GameArea(true, 319, 383);
	GameArea *FD = new GameArea(true, 383, 383);
	GameArea *GD = new GameArea(true, 447, 383);

	//fuenfte zeile von links nach rechts
	GameArea *AE = new GameArea(true, 63, 447);
	GameArea *BE = new GameArea(true, 127, 447);
	GameArea *CE = new GameArea(true, 191, 447);
	GameArea *DE = new GameArea(true, 255, 447);
	GameArea *EE = new GameArea(true, 319, 447);
	GameArea *FE = new GameArea(true, 383, 447);
	GameArea *GE = new GameArea(true, 447, 447);

	//sechste zeile von links nach rechts
	GameArea *AF = new GameArea(true, 63, 511);
	GameArea *BF = new GameArea(true, 127, 511);
	GameArea *CF = new GameArea(true, 191, 511);
	GameArea *DF = new GameArea(true, 255, 511);
	GameArea *EF = new GameArea(true, 319, 511);
	GameArea *FF = new GameArea(true, 383, 511);
	GameArea *GF = new GameArea(true, 447, 511);

	//siebte zeile von links nach rechts
	GameArea *AG = new GameArea(true, 63, 575);
	GameArea *BG = new GameArea(true, 127, 575);
	GameArea *CG = new GameArea(true, 191, 575);
	GameArea *DG = new GameArea(true, 255, 575);
	GameArea *EG = new GameArea(true, 319, 575);
	GameArea *FG = new GameArea(true, 383, 575);
	GameArea *GG = new GameArea(true, 447, 575);

	//achte zeile von links nach rechts
	GameArea *AH = new GameArea(true, 63, 639);
	GameArea *BH = new GameArea(true, 127, 639);
	GameArea *CH = new GameArea(true, 191, 639);
	GameArea *DH = new GameArea(true, 255, 639);
	GameArea *EH = new GameArea(true, 319, 639);
	GameArea *FH = new GameArea(true, 383, 639);
	GameArea *GH = new GameArea(true, 447, 639);

	//neunte zeile von links nach rechts
	GameArea *AI = new GameArea(true, 63, 703);
	GameArea *BI = new GameArea(true, 127, 703);
	GameArea *CI = new GameArea(true, 191, 703);
	GameArea *DI = new GameArea(true, 255, 703);
	GameArea *EI = new GameArea(true, 319, 703);
	GameArea *FI = new GameArea(true, 383, 703);
	GameArea *GI = new GameArea(false, 447, 703);

	list<GameArea*> PlayingField;

	//erste zeile von links nach rechts
	PlayingField.push_back(AA);
	PlayingField.push_back(BA);
	PlayingField.push_back(CA);
	PlayingField.push_back(DA);
	PlayingField.push_back(EA);
	PlayingField.push_back(FA);
	PlayingField.push_back(GA);

	//zweite zeile von links nach rechts
	PlayingField.push_back(AB);
	PlayingField.push_back(BB);
	PlayingField.push_back(CB);
	PlayingField.push_back(DB);
	PlayingField.push_back(EB);
	PlayingField.push_back(FB);
	PlayingField.push_back(GB);

	//dritte zeile von links nach rechts
	PlayingField.push_back(AC);
	PlayingField.push_back(BC);
	PlayingField.push_back(CC);
	PlayingField.push_back(DC);
	PlayingField.push_back(EC);
	PlayingField.push_back(FC);
	PlayingField.push_back(GC);

	//vierte zeile von links nach rechts
	PlayingField.push_back(AD);
	PlayingField.push_back(BD);
	PlayingField.push_back(CD);
	PlayingField.push_back(DD);
	PlayingField.push_back(ED);
	PlayingField.push_back(FD);
	PlayingField.push_back(GD);

	//fuenfte zeile von links nach rechts
	PlayingField.push_back(AE);
	PlayingField.push_back(BE);
	PlayingField.push_back(CE);
	PlayingField.push_back(DE);
	PlayingField.push_back(EE);
	PlayingField.push_back(FE);
	PlayingField.push_back(GE);

	//sechste zeile von links nach rechts
	PlayingField.push_back(AF);
	PlayingField.push_back(BF);
	PlayingField.push_back(CF);
	PlayingField.push_back(DF);
	PlayingField.push_back(EF);
	PlayingField.push_back(FF);
	PlayingField.push_back(GF);

	//siebte zeile von links nach rechts
	PlayingField.push_back(AG);
	PlayingField.push_back(BG);
	PlayingField.push_back(CG);
	PlayingField.push_back(DG);
	PlayingField.push_back(EG);
	PlayingField.push_back(FG);
	PlayingField.push_back(GG);

	//achte zeile von links nach rechts
	PlayingField.push_back(AH);
	PlayingField.push_back(BH);
	PlayingField.push_back(CH);
	PlayingField.push_back(DH);
	PlayingField.push_back(EH);
	PlayingField.push_back(FH);
	PlayingField.push_back(GH);

	//neunte zeile von links nach rechts
	PlayingField.push_back(AI);
	PlayingField.push_back(BI);
	PlayingField.push_back(CI);
	PlayingField.push_back(DI);
	PlayingField.push_back(EI);
	PlayingField.push_back(FI);
	PlayingField.push_back(GI);

	// run the program as long as the window is open
	while (App.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (App.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				App.close();
		}

		// clear the window with black color
		App.clear(sf::Color::Black);

		// draw everything here...
		// window.draw(...);
		//Background
		sf::Texture backgroundTexture;
		backgroundTexture.loadFromFile("ArtAssets/background.png");
		sf::Sprite backgroundSprite;
		backgroundSprite.setTexture(backgroundTexture);
		backgroundSprite.setPosition(0, 64);
		App.draw(backgroundSprite);

		//Testturm und Testgegner, testgegner ist hardgecodet, dass er einen bestimmten weg abfährt
		sf::Texture testTurmTexture;
		testTurmTexture.loadFromFile("ArtAssets/Tower/tank_dark.png");
		sf::Sprite testTurmSprite;
		sf::Sprite testEnemySprite;
		testEnemySprite.setTexture(testTurmTexture);
		//testEnemySprite.scale(0.695f, 0.762f);

		//test markierungen

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


		for (list<GameArea*>::const_iterator pos = PlayingField.begin(); pos != PlayingField.end(); ++pos) {
			if ((*pos)->getEmpty()) {
				emptySpaceSprite.setPosition((*pos)->getAreaXCoord(), (*pos)->getAreaYCoord());
				App.draw(emptySpaceSprite);
			}
			else {
				blockedSpaceSprite.setPosition((*pos)->getAreaXCoord(), (*pos)->getAreaYCoord());
				App.draw(blockedSpaceSprite);
			}
		}

		//testgegner bewegungskram
		testEnemySprite.setOrigin(32, 32);
		if (y > 191 && x < 447) {
			testEnemySprite.setRotation(270);
			testEnemySprite.setPosition(x, y);
			App.draw(testEnemySprite);
			x = x + 2;
		}
		if (y <= 191) {
			testEnemySprite.setPosition(x, y);
			App.draw(testEnemySprite);
			y = y + 2;			
		}
		if (x >= 447 && y <= 600) {
			testEnemySprite.setRotation(0);
			testEnemySprite.setPosition(x, y);
			App.draw(testEnemySprite);
			y = y + 2;			
		}		

		//testtürme statisch
		//testTurmSprite.scale(0.695f, 0.762f);
		testTurmSprite.setTexture(testTurmTexture);
		testTurmSprite.setOrigin(32, 32);
		testTurmSprite.setPosition(63, 255);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(127, 255);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(191, 255);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(255, 255);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(319, 255);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(383, 255);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(235, 361);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(235, 489);
		App.draw(testTurmSprite);
		testTurmSprite.setPosition(235, 617);
		App.draw(testTurmSprite);
		//window.draw(testTurmSprite);
		// end the current frame
		App.display();
	}
}

bool Game::isRunning()
{
	return running;
}


