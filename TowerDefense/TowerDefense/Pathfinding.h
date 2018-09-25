#pragma once
#include <vector>
#include "Zellen.h"
#include "Enemy.h"

#include <SFML\Graphics.hpp>

class Path
{
public:
	Path();
	~Path();

	void FindPath(Enemy currentPos, Enemy targetPos);

	// Vector3 NextPathPos();

	void ClearOpenList()
	{
		z_openList.clear();
	}
	void ClearVisitedList()
	{
		z_visitedList.clear();
	}
	void ClearPathToGoal()
	{
		z_pathToGOal;
	}
	bool z_initializedStartGoal;
	bool z_foundGoal;

private:

	void SetStartAndGoal(Zelle start, Zelle goal);

	void PathOpened(int x, int y, float newCost, Zelle *parent);

	Zelle *GetNextZelle();

	void ConinuePath();

	Zelle *z_startZelle;
	Zelle *z_zielZelle;
	std::vector<Zelle*> z_openList;
	std::vector<Zelle*> z_visitedList;
	std::vector<Enemy*> z_pathToGOal;

};
