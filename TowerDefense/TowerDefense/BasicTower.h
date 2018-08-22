#pragma once
#ifndef _BASICTOWER_H_
#define _BASICTOWER_H_

#include <string>

using namespace std;

class BasicTower {

private:
	string t_Name;
	int t_Cost;
	int t_XCoord;
	int t_YCoord;
	
public:
	BasicTower();

	//Getter
	inline int getCost() const { return t_Cost; }
	inline int getXCoord() const { return t_XCoord; }
	inline int getYCoord() const { return t_YCoord; }
	
	void checkForEnemies();
	void dealDamage();

};

#endif