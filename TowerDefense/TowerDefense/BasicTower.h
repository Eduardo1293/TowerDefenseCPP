#pragma once
#ifndef _BASICTOWER_H_
#define _BASICTOWER_H_

#include <string>

using namespace std;

class BasicTower {

private:
	string t_Name;
	string t_Description;
	int t_Cost;
	int t_XCoord;
	int t_YCoord;
	
public:
	BasicTower(int XCoord, int YCoord);

	//Getter
	inline int getCost() const { return t_Cost; }
	inline int getXCoord() const { return t_XCoord; }
	inline int getYCoord() const { return t_YCoord; }
	
	BasicTower();

	void checkForEnemies();
	void dealDamage();

};

#endif