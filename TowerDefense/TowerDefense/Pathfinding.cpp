//#include "PathFinding.h"
#include <SFML/System.hpp>
#include "Game.h"
#include "GameMap.h"
#include "GameArea.h"
#include <list>

//FML ich geh ins bett, zu 90% fertig
using namespace std;

class PathFinding {

	float manhattan(GameArea* a, GameArea* b) {
		float distance = (abs(a->getXID() - b->getXID())
			+ (abs(a->getYID() - b->getYID())));
		return distance;
	}

public:
	vector<int> aStar(vector<GameArea*> playingField) {
		//alle areas zurücksetzen
		for (int i = 0; i <= 62; i++) {
			playingField.at(i)->setVisited(false);
			playingField.at(i)->setDistanceFromStart(999.9f);
			playingField.at(i)->setWholeDistance(999.9f);
			playingField.at(i)->setParent(nullptr);
		}

		GameArea *currentArea = playingField.at(0);

		playingField.at(0)->setDistanceFromStart(0.0f);
		playingField.at(0)->setWholeDistance(manhattan(playingField.at(0), playingField.at(62)));

		list<GameArea*> notVisited;
		notVisited.push_back(playingField.at(0));
		
		while (!notVisited.empty() && currentArea != playingField.at(62)) {

			//sortieren mit lambda-funktion, thx stackoverflow
			notVisited.sort([] (GameArea* const& a, GameArea* const& b) {
				return a->getWholeDistance() < b->getWholeDistance();
			});

			while (!notVisited.empty() && notVisited.front()->getVisited()) {
				notVisited.pop_front();
			}

			if (notVisited.empty()) {
				break;
			}

			currentArea = notVisited.front();
			currentArea->setVisited(true);

			for (auto areaConnected : currentArea->a_Connected)
			{
				if (!areaConnected->getVisited() && areaConnected->getEmpty()) {
					notVisited.push_back(areaConnected);
				}

				float lowerLQuestionMark = currentArea->getDistanceFromStart()
					+ manhattan(currentArea, areaConnected);

				if (lowerLQuestionMark < areaConnected->getDistanceFromStart())
				{
					areaConnected->setParent(currentArea);
					areaConnected->setDistanceFromStart(lowerLQuestionMark);

					areaConnected->setWholeDistance(areaConnected->getDistanceFromStart()
						+ manhattan(areaConnected, playingField.at(62)));
				}
			}
		}

		//OUTPUT
		vector<int> path;

		int counter = 62;
		while (counter != 0) {
			path.insert(path.begin(), playingField.at(counter)->getID());
			counter = playingField.at(counter)->getParent()->getID();
		}
		path.insert(path.begin(), 0);
		return path;
	}



};



