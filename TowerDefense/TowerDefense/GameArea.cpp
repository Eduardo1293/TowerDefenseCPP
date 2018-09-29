#include "GameArea.h"

GameArea::GameArea(bool empty, float xCoord, float yCoord, int xID, int yID, int aID) 
{
	areaEmpty = empty;
	areaXCoord = xCoord;
	areaYCoord = yCoord;
	a_XID = xID;
	a_YID = yID;
	a_ID = aID;
	aParent = nullptr;
	distanceFromStart = 0;
	distanceToGoal = 0;
	aVisited = false;
	
}
