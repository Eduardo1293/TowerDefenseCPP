#ifndef GAMEAREA_H
#define GAMEAREA_H
#include <string>
#include <vector>

using namespace std;

class GameArea {
private :
	bool areaEmpty;					// Area bebaut oder nicht?
	int areaXCoord;					// PixelKoordinaten der Area
	int areaYCoord;					// PixelKoordinaten der Area
	int a_XID;						// Koordinaten der Area im areagrid
	int	a_YID;						// Koordinaten der Area im areagrid
	int a_ID;						// ID der Area
	GameArea* aParent;				// Pointer zur Parent-Area	
	int distanceFromStart;			// Lokaler Zielwert der Area
	int distanceToEnd;				// Geschätzter Weg zum Ziel
	bool aVisited;					// wurde die area vom a* schon besucht?

public:
	vector<GameArea*> a_Connected;	// benachbarte areas

	//Kontruktor
	GameArea(bool empty, int xCoord, int yCoord, int xID, int yID, int aID);

	//getter

	inline bool getEmpty() {
		return areaEmpty;
	}

	inline int getAreaXCoord() {
		return areaXCoord;
	}

	inline int getAreaYCoord() {
		return areaYCoord;
	}

	inline int getID() {
		return a_ID;
	}

	inline int getXID() {
		return a_XID;
	}

	inline int getYID() {
		return a_YID;
	}

	GameArea* getParent() {
		return aParent;
	}

	inline int getDistanceFromStart() {
		return distanceFromStart;
	}

	inline int getDistanceToEnd()
	{
		return distanceToEnd;
	}

	inline int getVisited() 
	{
		return aVisited;
	}

	//setter

	inline void setDistanceFromStart(int newDistanceFromStart) {
		distanceFromStart = newDistanceFromStart;
	}

	inline void setVisited(bool visited) {
		aVisited = visited;
	}

	inline void setParent(GameArea *parent) {
		aParent = parent;
	}

	inline void setDistanceToEnd(float distance) {
		distanceToEnd = distance;
	}
	
	inline void addConnected(GameArea* connectedArea) {
		a_Connected.push_back(connectedArea);
	}

	inline void setAreaEmpty(bool empty) {
		areaEmpty = empty;
	}	
};

#endif