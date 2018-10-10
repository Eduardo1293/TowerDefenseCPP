#include "BasicEnemy.h"



BasicEnemy::BasicEnemy(int maxLife, int movSpeed, string textureLocation) {
	eMaxLife = maxLife;
	eCurrentLife = maxLife;
	eXCoord = 63;
	eYCoord = 96;
	eGlobalLocation = 999;
	eMovementSpeed = movSpeed;
	eNavigationHelper = -1;
	eFrozenTimer = 0;
	BasicEnemyTexture.loadFromFile(textureLocation);
	BasicEnemySprite.setTexture(BasicEnemyTexture);
	BasicEnemySprite.setOrigin(32, 32);
}

BasicEnemy::~BasicEnemy()
{
}

void BasicEnemy::eSetRotation(float rotation) {
	BasicEnemySprite.setRotation(rotation);
}

void BasicEnemy::eSetPosition() {
	BasicEnemySprite.setPosition(eXCoord, eYCoord);
}

void BasicEnemy::eSetXCoord(int XCoord) {
	eXCoord = XCoord;
}

void BasicEnemy::eSetYCoord(int YCoord) {
	eYCoord = YCoord;
}

void BasicEnemy::eSetGlobalLocation(int location)
{
	eGlobalLocation = location;
}

void BasicEnemy::eSetMovementSpeed(int speed)
{
	eMovementSpeed = speed;
}

void BasicEnemy::eSetFrozenTimer(int timer)
{
	eFrozenTimer = timer;
}

//Getter
double BasicEnemy::eGetMaxLife()
{
	return eMaxLife;
}

double BasicEnemy::eGetCurrentLife()
{
	return eCurrentLife;
}

int BasicEnemy::eGetXCoord()
{
	return eXCoord;
}

int BasicEnemy::eGetYCoord()
{
	return eYCoord;
}

int BasicEnemy::eGetGlobalLocation()
{
	return eGlobalLocation;
}

int BasicEnemy::eGetFrozenTimer()
{
	return eFrozenTimer;
}

int BasicEnemy::eGetMovementSpeed()
{
	return eMovementSpeed;
}

sf::Sprite BasicEnemy::eGetSprite()
{
	return BasicEnemySprite;
}

void BasicEnemy::takeDamage(int damage) {
	eCurrentLife = (eCurrentLife - damage);
}

void BasicEnemy::eMovement(vector<int> path, vector<int> pathXCoord, vector<int> pathYCoord, vector<int> pathDirection)
{
	//Überprüft, ob ein Gegner noch von einem Frosttower verlangsamt ist, nachdem der Gegner für
	//24 Frames verlangsamt war "taut" er auf
	if (eFrozenTimer > 0 && eFrozenTimer < 25)
	{
		eFrozenTimer++;
	}
	if (eFrozenTimer == 25)
	{
		eMovementSpeed++;
		eFrozenTimer = 0;
	}

	//Abhängig vom Movementspeed wird der Gegner um mehrere Pixel pro Frame bewegt	
	for (unsigned int j = 0; j < eMovementSpeed; j++)
	{

		/*
		Navigation vom Start auf das erste Spielfeld (eNavigationHelper = -1)
		*/
		if (eNavigationHelper == -1)
		{
			eYCoord++;
			if (eYCoord > 159 && eGlobalLocation != 0)
			{
				eGlobalLocation = 0;
			}
			if (eYCoord >= 191)
			{
				eNavigationHelper++;
				if (pathDirection.at(1) = 1)
				{
					eSetRotation(270);
				}
				else
				{
					eSetRotation(0);
				}
			}
		}

		/*
		Navigation von Feld 0 auf Feld 62, dem Pathfinding folgend (eNavigationHelper zwischen 0 und 61)
		*/
		if (eNavigationHelper >= 0 && eNavigationHelper < (path.size() - 1))
		{
			int iSwitch = pathDirection.at(eNavigationHelper);
			int iSwitchPlusOne = pathDirection.at(eNavigationHelper + 1);

			//Switchcase der anhand der im Vector Pathdirection gespeicherten Richtung, der Gegner in die richtige
			//Richtung bewegt. Sobald der Gegner von einer Area  in eine andere tritt wird außerdem die 
			//GlobalLocation des Gegner für das Tower-Targetting geupdated.
			//Ist der Gegner in der Mitte der nächsten Area angekommen wird außerdem mithilfe eines zweiten Switch-Cases
			//das Gegner-Sprite gedreht.
			switch (iSwitch)
			{

			//Movement nach rechts
			case 1:
				eXCoord++;
				//Enemy globallocation updaten, wenn in neuem Feld
				if (eGlobalLocation != path.at(eNavigationHelper + 1)
					&& (eXCoord >= (pathXCoord.at(eNavigationHelper + 1) - 32)))
				{
					eGlobalLocation = path.at(eNavigationHelper + 1);
				}
				//Richtung ändern
				if (eXCoord >= pathXCoord.at(eNavigationHelper + 1))
				{				
					eNavigationHelper++;
					switch (iSwitchPlusOne)
					{
					case 1: eSetRotation(270); break;
					case 2: eSetRotation(0); break;
					case 3: eSetRotation(90); break;
					case 4: eSetRotation(180); break;
					}
				};
				break;;

			//Movement nach unten
			case 2:
				eYCoord++;
				if (eGlobalLocation != path.at(eNavigationHelper + 1)
					&& (eYCoord > (pathYCoord.at(eNavigationHelper + 1) - 32)))
				{
					eGlobalLocation = path.at(eNavigationHelper + 1);
				}
				//Richtung ändern
				if (eYCoord >= pathYCoord.at(eNavigationHelper + 1))
				{
					//eYCoord = pathYCoord.at(eNavigationHelper + 1);
					eNavigationHelper++;
					switch (iSwitchPlusOne)
					{
					case 1: eSetRotation(270); break;
					case 2: eSetRotation(0); break;
					case 3: eSetRotation(90); break;
					case 4: eSetRotation(180); break;
					}
				};
				break;

			//Movement nach links
			case 3:
				eXCoord--;
				//Enemy globallocation updaten, wenn in neuem Feld
				if (eGlobalLocation != path.at(eNavigationHelper + 1)
					&& (eXCoord <= (pathXCoord.at(eNavigationHelper + 1) + 32)))
				{
					eGlobalLocation = path.at(eNavigationHelper + 1);
				}
				//Richtung ändern
				if (eXCoord <= pathXCoord.at(eNavigationHelper + 1))
				{
					eNavigationHelper++;
					switch (iSwitchPlusOne)
					{
					case 1: eSetRotation(270); break;
					case 2: eSetRotation(0); break;
					case 3: eSetRotation(90); break;
					case 4: eSetRotation(180); break;
					}
				};
				break;

			//Movement nach oben
			case 4:
				eYCoord--;
				//Enemy globallocation updaten, wenn in neuem Feld
				if (eGlobalLocation != path.at(eNavigationHelper + 1)
					&& (eYCoord <= (pathYCoord.at(eNavigationHelper + 1) + 32)))
				{
					eGlobalLocation = path.at(eNavigationHelper + 1);
				}
				//Richtung ändern
				if (eYCoord <= pathYCoord.at(eNavigationHelper + 1))
				{
					eNavigationHelper++;
					switch (iSwitchPlusOne)
					{
					case 1: eSetRotation(270); break;
					case 2: eSetRotation(0); break;
					case 3: eSetRotation(90); break;
					case 4: eSetRotation(180); break;
					}
				};
				break;
			}
		}

		/*
		Navigation vom letzten Spielfeld zum Ausgang (eNavigationHelper = 62)
		*/
		if (eNavigationHelper == (path.size() - 1))
		{
			eYCoord++;
			if (eYCoord > 734 && eGlobalLocation == 62)
			{
				eGlobalLocation == 999;
			}
		}

	}
}
//Ende Gegnermovement

BasicEnemy::BasicEnemy()
{
}
