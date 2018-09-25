#pragma once
#include <math.h>

#define WORLD_SIZE 64
// Eine Zelle konstruieren und ihr Werte zuteilen
struct Zelle
{

public:
	int z_xcoord, z_ycoord;	// Koordinaten der Zellen
	int z_id;				// Identität der Zelle
	Zelle* parent;			// Pointer zur Parent-Zelle
	float G;				// Lokaler Zielwert der Zelle
	float H;				// Heuristischer Zielwert der Zelle

							//Kontruktoren 
	Zelle() : parent(0)
	{
	}
	Zelle(int x, int y, Zelle *_parent = NULL) : z_xcoord(x), z_ycoord(y), parent(_parent), z_id(y * WORLD_SIZE + y), G(0), H(0)
	{
	}

	// F ist die Summe des heuristischen und lokalen Wert und bestimmt die Kosten der Zelle
	float GetF()
	{
		return G + H;
	}

	// Distantz zwischen der aktuellen Zelle und der Zielzelle
	float ManhattanDistance(Zelle *nodeEnd)
	{
		float x = (float)(fabs((float)this->z_xcoord - nodeEnd->z_xcoord));
		float y = (float)(fabs((float)this->z_ycoord - nodeEnd->z_ycoord));
	}
};