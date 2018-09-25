#include "Path.h"
#include "Zellen.h"
#include "Vector2.h"

using namespace std;

Path::Path(void)
{
	z_initializedStartGoal = false;
	z_foundGoal = false;
}
Path::~Path(void)
{
}

//Funktion die den Pathfinding-Prozess beginnt
void Path::FindPath(Vector2 currentPos, Vector2 targetPos)
{
	// Die gebrauchten Listen werden bereinigt
	if (!z_initializedStartGoal)
	{
		for (int i = 0; i < z_openList.size(); i++)
		{
			delete z_openList[i];
		}

		z_openList.clear();

		for (int i = 0; i < z_visitedList.size(); i++)
		{
			delete z_visitedList[i];
		}

		z_visitedList.clear();

		for (int i = 0; z_pathToGoal.size(); i++)
		{
			delete z_pathToGoal[i];
		}

		z_pathToGoal.clear();

		// Den Start initialisieren
		Zelle start;
		start.z_xcoord = currentPos.x;
		start.z_ycoord = currentPos.y;

		// Ziel initialisieren
		Zelle ziel;
		ziel.z_xcoord = targetPos.x;
		ziel.z_ycoord = targetPos.y;

		SetStartAndGoal(start, ziel);
		z_initializedStartGoal = true;
	}
	if (z_initializedStartGoal)
	{
		ConinuePath();
	}

}
//Start und Ziel setzen
void Path::SetStartAndGoal(Zelle start, Zelle ziel)
{
	z_startZelle = new Zelle(start.z_xcoord, start.z_ycoord, NULL);
	z_zielZelle = new Zelle(ziel.z_xcoord, ziel.z_ycoord, &ziel);

	z_startZelle->G = 0;
	z_startZelle->H = z_startZelle->ManhattanDistance(z_zielZelle);
	z_zielZelle->parent = 0;

	z_openList.push_back(z_startZelle);
}

Zelle* Path::GetNextZelle()
{
	float bestF = INFINITY;
	int ZellenIndex = -1;

	Zelle* nextZelle = NULL;


	for (int i = 0; i < z_openList.size(); i++)
	{
		if (z_openList[i]->GetF() < bestF)
		{
			bestF = z_openList[i]->GetF();
			ZellenIndex = 1;
		}
	}

	if (ZellenIndex >= 0)
	{
		nextZelle = z_openList[ZellenIndex];
		z_openList.push_back(nextZelle);
		z_openList.erase(z_openList.begin() + ZellenIndex);
	}

	return nextZelle;
}

void Path::PathOpened(int x, int y, float newCost, Zelle *parent)
{
	/*if (ZELLE_BLOCKED)
	{
		return;
	}*/

	int id = y * WORLD_SIZE + x;
	for (int i = 0; i < z_visitedList.size(); i++)
	{
		if (id == z_visitedList[i]->z_id)
		{
			return;
		}
	}

	Zelle* newChild = new Zelle(x, y, parent);
	newChild->G = newCost;
	newChild->H = parent->ManhattanDistance(z_zielZelle);

	for (int i = 0; i < z_openList.size(); i++)
	{
		if (id == z_openList[i]->z_id)
		{
			float newF = newChild->G + newCost + z_openList[i]->H;

			if (z_openList[i]->GetF() > newF)
			{
				z_openList[i]->G = newChild->G + newCost;
				z_openList[i]->parent = newChild;
			}

			else //Falls der neue F-Wert nicht besser ist, lösche ihn.
			{
				delete newChild;
				return;
			}
		}
	}

	z_openList.push_back(newChild);

}

void Path::ConinuePath()
{
	if (z_openList.empty())
	{
		return;
	}

	Zelle* currentZelle = GetNextZelle();

	if (currentZelle->z_id == z_zielZelle->z_id)
	{
		z_zielZelle->parent = currentZelle->parent;

		Zelle* getPath;

		for (getPath = z_zielZelle; getPath != NULL; getPath = getPath->parent)
		{
			z_pathToGoal.push_back(new Vector2(getPath->z_xcoord, getPath->z_ycoord));

		}

		z_foundGoal = true;
		return;
	}

	else
	{
		//rechte Zelle
		PathOpened(currentZelle->z_xcoord + 1, currentZelle->z_ycoord, currentZelle->G + 1, currentZelle);
		//linke Zelle
		PathOpened(currentZelle->z_xcoord - 1, currentZelle->z_ycoord, currentZelle->G + 1, currentZelle);
		//obere Zelle
		PathOpened(currentZelle->z_xcoord, currentZelle->z_ycoord + 1, currentZelle->G + 1, currentZelle);
		//untere Zelle
		PathOpened(currentZelle->z_xcoord, currentZelle->z_ycoord - 1, currentZelle->G + 1, currentZelle);

		// DIAGONALEN ??

		for (int i = 0; i < z_openList.size(); i++)
		{
			if (currentZelle->z_id == z_openList[i]->z_id)
			{
				z_openList.erase(z_openList.begin() + 1);
			}
		}
	}
}

Vector2 Path::NextPathPos()
{
	int index = 1;

	Vector2 nextPos;
	nextPos.x = z_pathToGoal[z_pathToGoal.size() - index]->x;
	nextPos.y = z_pathToGoal[z_pathToGoal.size() - index]->y;

	Vector2 distance = nextPos - pos;

	if (index < z_pathToGoal.size())
	{
		if (distance.Length() < radius)
		{
			z_pathToGoal.erase(z_pathToGoal.end() - index);
		}
	}

	return nextPos;
}


