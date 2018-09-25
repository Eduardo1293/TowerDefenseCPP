//#include <SFML/System.hpp>
//#include "Pathfinding.h"
//#include "Zellen.h"
//#include "Game.h"
//
//using namespace std;
//
//Path::Path(void)
//{
//	z_initializedStartGoal = false;
//	z_foundGoal = false;
//}
//Path::~Path(void)
//{
//}
//
////Funktion die den Pathfinding-Prozess beginnt
//void Path::FindPath(Vector2 currentPos, Vector2 targetPos)
//{
//	// Die gebrauchten Listen werden bereinigt
//	if (!z_initializedStartGoal)
//	{
//		for (int i = 0; i < z_openList.size(); i++)
//		{
//			delete z_openList[i];
//		}
//
//		z_openList.clear();
//
//		for (int i = 0; i < z_visitedList.size(); i++)
//		{
//			delete z_visitedList[i];
//		}
//
//		z_visitedList.clear();
//
//		for (int i = 0; z_pathToGoal.size(); i++)
//		{
//			delete z_pathToGoal[i];
//		}
//
//		z_pathToGoal.clear();
//
//		// Den Start initialisieren
//		Zelle start;
//		start.z_xcoord = currentPos.x;
//		start.z_ycoord = currentPos.y;
//
//		// Ziel initialisieren
//		Zelle ziel;
//		ziel.z_xcoord = targetPos.x;
//		ziel.z_ycoord = targetPos.y;
//
//		SetStartAndGoal(start, ziel);
//		z_initializedStartGoal = true;
//	}
//	if (z_initializedStartGoal)
//	{
//		ConinuePath();
//	}
//
//}
////Start und Ziel setzen
//void Path::SetStartAndGoal(Zelle start, Zelle ziel)
//{
//	z_startZelle = new Zelle(start.z_xcoord, start.z_ycoord, NULL);
//	z_zielZelle = new Zelle(ziel.z_xcoord, ziel.z_ycoord, &ziel);
//
//	z_startZelle->G = 0;
//	z_startZelle->H = z_startZelle->ManhattanDistance(z_zielZelle);
//	z_zielZelle->parent = 0;
//
//	z_openList.push_back(z_startZelle);
//}
//
//Zelle* Path::GetNextZelle()
//{
//	float bestF = INFINITY;
//	int ZellenIndex = -1;
//
//	Zelle* nextZelle = NULL;
//
//
//	for (int i = 0; i < z_openList.size(); i++)
//	{
//		if (z_openList[i]->GetF() < bestF)
//		{
//			bestF = z_openList[i]->GetF();
//			ZellenIndex = 1;
//		}
//	}
//
//	if (ZellenIndex >= 0)
//	{
//		nextZelle = z_openList[ZellenIndex];
//		z_openList.push_back(nextZelle);
//		z_openList.erase(z_openList.begin() + ZellenIndex);
//	}
//
//	return nextZelle;
//}
//
//void Path::PathOpened(int x, int y, float newCost, Zelle *parent)
//{
//	/*if (ZELLE_BLOCKED)
//	{
//	return;
//	}*/
//
//	int id = y * world_size + x;
//	for (int i = 0; i < z_visitedlist.size(); i++)
//	{
//		if (id == z_visitedlist[i]->z_id)
//		{
//			return;
//		}
//	}
//
//	zelle* newchild = new zelle(x, y, parent);
//	newchild->g = newcost;
//	newchild->h = parent->manhattandistance(z_zielzelle);
//
//	for (int i = 0; i < z_openlist.size(); i++)
//	{
//		if (id == z_openlist[i]->z_id)
//		{
//			float newf = newchild->g + newcost + z_openlist[i]->h;
//
//			if (z_openlist[i]->getf() > newf)
//			{
//				z_openlist[i]->g = newchild->g + newcost;
//				z_openlist[i]->parent = newchild;
//			}
//
//			else //falls der neue f-wert nicht besser ist, lösche ihn.
//			{
//				delete newchild;
//				return;
//			}
//		}
//	}
//
//	z_openlist.push_back(newchild);
//
//}
//
//void path::coninuepath()
//{
//	if (z_openlist.empty())
//	{
//		return;
//	}
//
//	zelle* currentzelle = getnextzelle();
//
//	if (currentzelle->z_id == z_zielzelle->z_id)
//	{
//		z_zielzelle->parent = currentzelle->parent;
//
//		zelle* getpath;
//
//		for (getpath = z_zielzelle; getpath != null; getpath = getpath->parent)
//		{
//			//das brauchen wir
//			z_pathtogoal.push_back(new vector2(getpath->z_xcoord, getpath->z_ycoord));
//
//		}
//
//		z_foundgoal = true;
//		return;
//	}
//
//	else
//	{
//		//rechte zelle
//		pathopened(currentzelle->z_xcoord + 1, currentzelle->z_ycoord, currentzelle->g + 1, currentzelle);
//		//linke zelle
//		pathopened(currentzelle->z_xcoord - 1, currentzelle->z_ycoord, currentzelle->g + 1, currentzelle);
//		//obere zelle
//		pathopened(currentzelle->z_xcoord, currentzelle->z_ycoord + 1, currentzelle->g + 1, currentzelle);
//		//untere zelle
//		pathopened(currentzelle->z_xcoord, currentzelle->z_ycoord - 1, currentzelle->g + 1, currentzelle);
//
//		// diagonalen ??
//
//		for (int i = 0; i < z_openlist.size(); i++)
//		{
//			if (currentzelle->z_id == z_openlist[i]->z_id)
//			{
//				z_openlist.erase(z_openlist.begin() + 1);
//			}
//		}
//	}
//}
//
//vector2 path::nextpathpos()
//{
//	int index = 1;
//
//	vector2 nextpos;
//	nextpos.x = z_pathtogoal[z_pathtogoal.size() - index]->x;
//	nextpos.y = z_pathtogoal[z_pathtogoal.size() - index]->y;
//
//	vector2 distance = nextpos - pos;
//
//	if (index < z_pathtogoal.size())
//	{
//		if (distance.length() < radius)
//		{
//			z_pathtogoal.erase(z_pathtogoal.end() - index);
//		}
//	}
//
//	return nextpos;
//}