#include "PathFinding.h"
#include <SFML/System.hpp>
#include "Game.h"
#include "GameMap.h"
#include "GameArea.h"
#include <list>
#include "CustomException.h"

using namespace std;

//Path berechnen
vector<int> PathFinding::aStar(vector<GameArea*> playingField)
{
	//Alle Gameareas zurücksetzen
	for (int i = 0; i <= 62; i++)
	{
		playingField.at(i)->setVisited(false);
		playingField.at(i)->setDistanceFromStart(999);
		playingField.at(i)->setDistanceToEnd(999);
		playingField.at(i)->setParent(nullptr);
	}

	//Pointer auf die Area, die gerade "untersucht" wird
	GameArea *currentArea = playingField.at(0);

	playingField.at(0)->setDistanceFromStart(0.0f);
	playingField.at(0)->setDistanceToEnd(manhattan(playingField.at(0), playingField.at(62)));

	//Liste aller Felder, die noch nicht besucht wurden
	list<GameArea*> notVisited;
	notVisited.push_back(playingField.at(0));

	while (!notVisited.empty() && currentArea != playingField.at(62))
	{

		//Nicht-besuchte Felder nach Distanz zum Ziel sortieren
		notVisited.sort([](GameArea* const& a, GameArea* const& b)
		{
			return a->getDistanceToEnd() < b->getDistanceToEnd();
		});

		//Wenn die vorderste Area besucht wurde, entferne sie aus der nicht-besucht Liste
		while (!notVisited.empty() && notVisited.front()->getVisited())
		{
			notVisited.pop_front();
		}

		//Breche ab, wenn alle Felder besucht wurden
		if (notVisited.empty())
		{
			break;
		}

		//setze den Pointer auf das erste nicht-gesuchte Feld
		currentArea = notVisited.front();

		//Kennzeichne dieses Feld als "besucht"
		currentArea->setVisited(true);

		for (auto areaConnected : currentArea->a_Connected)
		{
			/*
			Füge alle freien Areas, die sich neben der untersuchten Area befinden zur
			nicht-besucht Liste hinzu
			*/
			if (!areaConnected->getVisited() && areaConnected->getEmpty())
			{
				notVisited.push_back(areaConnected);
			}

			/*
			Berechne den Weg zur Nachbararea über die aktuelle Area
			*/
			int lowerDQuestionMark = currentArea->getDistanceFromStart()
				+ manhattan(currentArea, areaConnected);

			/*
			Vergleiche, ob der Weg vom Start zur Nachbararea über die aktuelle Area kürzer ist,
			als der dort hinterlegte kürzeste Weg. Wenn dies der Fall ist, setze den Area-Pointer
			der Nachbararea auf die untersuchte Area.
			*/
			if (lowerDQuestionMark < areaConnected->getDistanceFromStart())
			{
				areaConnected->setParent(currentArea);
				areaConnected->setDistanceFromStart(lowerDQuestionMark);

				areaConnected->setDistanceToEnd(areaConnected->getDistanceFromStart()
					+ manhattan(areaConnected, playingField.at(62)));
			}
		}
	}

	/*
	Gebe mithilfe der jeweiligen Parent-Pointer die Area-IDs des Pfades zurück
	*/
	vector<int> path;

	int counter = 62;

		while (counter != 0) {
			path.insert(path.begin(), playingField.at(counter)->getID());
			if (playingField.at(counter)->getParent() == NULL)
			{
				throw CustomException("No parent for pathfinding...");
			}
			counter = playingField.at(counter)->getParent()->getID();
		}
	
	
	path.insert(path.begin(), 0);
	return path;
}

//Distanz von Feld zu Feld
int PathFinding::manhattan(GameArea * a, GameArea * b)
{
	int distance = (abs(a->getXID() - b->getXID())
		+ (abs(a->getYID() - b->getYID())));
	return distance;
}
