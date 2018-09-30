#ifndef _GAMEMAP_H_
#define _GAMEMAP_H_

#include "GameArea.h"



class GameMap
{
private:
	vector<GameArea*> GameAreaVector;
public:
	GameMap();
	~GameMap();

	void setGameMap();
	vector<GameArea*> getGameMap();

};

#endif
