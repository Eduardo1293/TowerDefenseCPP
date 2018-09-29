#ifndef GAMEAREA_H
#define GAMEAREA_H
#include <string>
#include <vector>

using namespace std;

class GameArea {
private :
	bool areaEmpty;
	float areaXCoord;				// PixelKoordinaten der Area
	float areaYCoord;				// PixelKoordinaten der Area
	int a_XID;						// Koordinaten der Area im areagrid
	int	a_YID;						// Koordinaten der Area im areagrid
	int a_ID;						// ID der Area
	GameArea* aParent;				// Pointer zur Parent-Area
	
	float distanceFromStart;		// Lokaler Zielwert der Area
	float distanceToGoal;			// Heuristischer Zielwert der Area
	float wholeDistance;
	bool aVisited;					// wurde die area vom a* schon besucht?

public:
	vector<GameArea*> a_Connected;	// benachbarte areas

	//Kontruktor
	GameArea(bool empty, float xCoord, float yCoord, int xID, int yID, int aID, GameArea *_parent = 0);

	//setter
	inline void setAreaEmpty(bool empty) {
		areaEmpty = empty;
	}

	//getter

	inline bool getEmpty() {
		return areaEmpty;
	}

	inline float getAreaXCoord() {
		return areaXCoord;
	}

	inline float getAreaYCoord() {
		return areaYCoord;
	}

	int getID() {
		return a_ID;
	}

	int getXID() {
		return a_XID;
	}

	int getYID() {
		return a_YID;
	}

	GameArea* getParent() {
		return aParent;
	}

	int getDistanceFromStart() {
		return distanceFromStart;
	}

	int getDistanceToGoal() {
		return distanceToGoal;
	}

	float getWholeDistance()
	{
		return distanceFromStart + distanceToGoal;
	}

	bool getVisited() {
		return aVisited;
	}

	//setter

	void setDistanceFromStart(int newDistanceFromStart) {
		distanceFromStart = newDistanceFromStart;
	}

	void setDistanceToGoal(int newDistanceToGoal) {
		distanceToGoal = newDistanceToGoal;
	}

	void setVisited(bool visited) {
		aVisited = visited;
	}

	void setParent(GameArea *parent) {
		aParent = parent;
	}

	void setWholeDistance(float distance) {
		wholeDistance = distance;
	}
	
	void addConnected(GameArea* connectedArea) {
		a_Connected.push_back(connectedArea);
	}

	// Distanz zwischen der aktuellen Zelle und der Zielzelle
	float manhattanDistance(GameArea *nodeEnd)
	{
		float x = (float)(fabs((float)this->a_XID - nodeEnd->a_XID));
		float y = (float)(fabs((float)this->a_YID - nodeEnd->a_YID));

		return x + y;
	}
};

#endif