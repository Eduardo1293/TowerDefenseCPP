#ifndef GAMEAREA_H
#define GAMEAREA_H
#include <string>

using namespace std;

class GameArea {
private :
	bool areaEmpty;
	int areaXCoord;
	int areaYCoord;

public:
	//Kontruktor
	GameArea(bool empty, int xCoord, int yCoord);

	//setter
	inline void setAreaEmpty(bool empty) {
		areaEmpty = empty;
	}

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
};

#endif