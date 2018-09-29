#pragma once
#include <math.h>

#define WORLD_SIZE 64
// Eine Zelle konstruieren und ihr Werte zuteilen
struct Area
{

public:
	int a_XCoord, a_YCoord;	// Koordinaten der Zellen
	int a_ID;				// ID der Zelle
	Area* parent;			// Pointer zur Parent-Zelle
	float G;				// Lokaler Zielwert der Zelle
	float H;				// Heuristischer Zielwert der Zelle

							//Kontruktoren 
	Area() : parent(0)
	{
	}
	Area(int x, int y, Area *_parent = 0) 
	{
		a_XCoord = x;
		a_YCoord = y;
		parent = _parent;
		a_ID = (y * WORLD_SIZE + y);
		G = 0;
		H = 0;

	}

	// F ist die Summe des heuristischen und lokalen Wert und bestimmt die Kosten der Zelle
	float GetF()
	{
		return G + H;
	}

	// Distantz zwischen der aktuellen Zelle und der Zielzelle
	float ManhattanDistance(Area *nodeEnd)
	{
		float x = (float)(fabs((float)this->a_XCoord - nodeEnd->a_XCoord));
		float y = (float)(fabs((float)this->a_YCoord - nodeEnd->a_YCoord));

		return x + y;
	}
};