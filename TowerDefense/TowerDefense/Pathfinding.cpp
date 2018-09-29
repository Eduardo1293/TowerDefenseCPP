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

	vector<int> aStar(vector<GameArea*> playingField) {
		//alle areas zurücksetzen
		for (int i = 0; i <= 62; i++) {
			playingField.at(i)->setVisited(false);
			playingField.at(i)->setDistanceFromStart(999.9f);
			// ????? kA ob benötigt, zu müde playingField.at(i)->setDistanceToGoal(999.9f);
			playingField.at(i)->setParent(nullptr);
		}

		GameArea *currentArea = playingField.at(0);

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

				float lowerLQuestionMark = manhattan(currentArea, areaConnected);

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
		
		return path;
	}



};



