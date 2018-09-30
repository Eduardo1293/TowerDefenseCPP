#ifndef PLAYINGFIELD_H
#define PLAYINGFIELD_H

#include "GameArea.h"



class PlayingField
{
private:
	vector<GameArea*> GameAreaVector;
public:
	PlayingField();
	~PlayingField();

	void setPlayingField();
	vector<GameArea*> getPlayingField();
	
};

#endif