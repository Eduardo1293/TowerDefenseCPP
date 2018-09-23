#ifndef GAMEAREA_H
#define GAMEAREA_H
#include <string>

using namespace std;

class GameArea {
private :
	bool areaEmpty;
	float areaXCoord;
	float areaYCoord;

public:
	//Kontruktor
	GameArea(bool empty, float xCoord, float yCoord);

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
};

#endif