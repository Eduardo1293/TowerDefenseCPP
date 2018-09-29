//#include "PathFinding.h"
#include <SFML/System.hpp>
#include "Game.h"
#include "PlayingField.cpp"
#include "GameArea.h"

//FML ich geh ins bett, zu 90% fertig
using namespace std;

class PathFinding {

	float manhattan(GameArea* a, GameArea* b) {
		float distance = (abs(a->getXID() - b->getXID())
			+ (abs(a->getYID() - b->getYID())));
		return distance;
	}

	vector<int> aStar(vector<GameArea*> PlayingField) {
		//alle areas zurücksetzen
		for (int i = 0; i <= 62; i++) {
			PlayingField.at(i)->setVisited(false);
			PlayingField.at(i)->setDistanceFromStart(999.9f);
			// ????? kA ob benötigt, zu müde PlayingField.at(i)->setDistanceToGoal(999.9f);
			PlayingField.at(i)->setParent(nullptr);
		}

		GameArea *currentArea = PlayingField.at(0);

		list<GameArea*> notVisited;
		notVisited.push_back(PlayingField.at(0));
		
		while (!notVisited.empty() && currentArea != PlayingField.at(62)) {

			//sortieren mit lambda-funktion, thx stackoverflow
			sort(notVisited.begin(), notVisited.end(), [] (GameArea* a, GameArea* b) {
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

				float lowerLQuestionMark = manhattan(currentArea, areaConnected);

				if (lowerLQuestionMark < areaConnected->getDistanceFromStart())
				{
					areaConnected->setParent(currentArea);
					areaConnected->setDistanceFromStart(lowerLQuestionMark);

					areaConnected->setWholeDistance(areaConnected->getDistanceFromStart()
						+ manhattan(areaConnected, PlayingField.at(62)));
				}
			}
		}

		//OUTPUT
		vector<int> path;

		int counter = 62;
		while (counter != 0) {
			path.insert(path.begin(), PlayingField.at(counter)->getID());
			counter = PlayingField.at(counter)->getParent()->getID();
		}
		
		return path;
	}



};



