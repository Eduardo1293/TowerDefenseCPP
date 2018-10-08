#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <SFML/System.hpp>
#include "Game.h"
#include "GameMap.h"
#include "GameArea.h"
#include <list>

class PathFinding {

public:

	vector<int> aStar(vector<GameArea*> playingField);

private:
	float manhattan(GameArea* a, GameArea* b);


};
#endif