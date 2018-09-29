#include "GameArea.h"

GameArea::GameArea(bool empty, float xCoord, float yCoord, int xID, int yID, int aID,
	GameArea *_parent = 0) 
{
	areaEmpty = empty;
	areaXCoord = xCoord;
	areaYCoord = yCoord;
	a_XID = xID;
	a_YID = yID;
	a_ID = aID;
	distanceFromStart = 0;
	distanceToGoal = 0;
	aVisited = false;
}
