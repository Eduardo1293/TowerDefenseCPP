#ifndef PLAYINGFIELD_H
#define PLAYINGFIELD_H

#include "GameArea.h"
#include <list>
list<GameArea*> PlayingField() {
	//erste zeile von links nach rechts
	GameArea *AA = new GameArea(false, 63, 191);
	GameArea *BA = new GameArea(true, 127, 191);
	GameArea *CA = new GameArea(true, 191, 191);
	GameArea *DA = new GameArea(true, 255, 191);
	GameArea *EA = new GameArea(true, 319, 191);
	GameArea *FA = new GameArea(true, 383, 191);
	GameArea *GA = new GameArea(true, 447, 191);

	//zweite zeile von links nach rechts
	GameArea *AB = new GameArea(true, 63, 255);
	GameArea *BB = new GameArea(true, 127, 255);
	GameArea *CB = new GameArea(true, 191, 255);
	GameArea *DB = new GameArea(true, 255, 255);
	GameArea *EB = new GameArea(true, 319, 255);
	GameArea *FB = new GameArea(true, 383, 255);
	GameArea *GB = new GameArea(true, 447, 255);

	//dritte zeile von links nach rechts
	GameArea *AC = new GameArea(true, 63, 319);
	GameArea *BC = new GameArea(true, 127, 319);
	GameArea *CC = new GameArea(true, 191, 319);
	GameArea *DC = new GameArea(true, 255, 319);
	GameArea *EC = new GameArea(true, 319, 319);
	GameArea *FC = new GameArea(true, 383, 319);
	GameArea *GC = new GameArea(true, 447, 319);

	//vierte zeile von links nach rechts
	GameArea *AD = new GameArea(true, 63, 383);
	GameArea *BD = new GameArea(true, 127, 383);
	GameArea *CD = new GameArea(true, 191, 383);
	GameArea *DD = new GameArea(true, 255, 383);
	GameArea *ED = new GameArea(true, 319, 383);
	GameArea *FD = new GameArea(true, 383, 383);
	GameArea *GD = new GameArea(true, 447, 383);

	//fuenfte zeile von links nach rechts
	GameArea *AE = new GameArea(true, 63, 447);
	GameArea *BE = new GameArea(true, 127, 447);
	GameArea *CE = new GameArea(true, 191, 447);
	GameArea *DE = new GameArea(true, 255, 447);
	GameArea *EE = new GameArea(true, 319, 447);
	GameArea *FE = new GameArea(true, 383, 447);
	GameArea *GE = new GameArea(true, 447, 447);

	//sechste zeile von links nach rechts
	GameArea *AF = new GameArea(true, 63, 511);
	GameArea *BF = new GameArea(true, 127, 511);
	GameArea *CF = new GameArea(true, 191, 511);
	GameArea *DF = new GameArea(true, 255, 511);
	GameArea *EF = new GameArea(true, 319, 511);
	GameArea *FF = new GameArea(true, 383, 511);
	GameArea *GF = new GameArea(true, 447, 511);

	//siebte zeile von links nach rechts
	GameArea *AG = new GameArea(true, 63, 575);
	GameArea *BG = new GameArea(true, 127, 575);
	GameArea *CG = new GameArea(true, 191, 575);
	GameArea *DG = new GameArea(true, 255, 575);
	GameArea *EG = new GameArea(true, 319, 575);
	GameArea *FG = new GameArea(true, 383, 575);
	GameArea *GG = new GameArea(true, 447, 575);

	//achte zeile von links nach rechts
	GameArea *AH = new GameArea(true, 63, 639);
	GameArea *BH = new GameArea(true, 127, 639);
	GameArea *CH = new GameArea(true, 191, 639);
	GameArea *DH = new GameArea(true, 255, 639);
	GameArea *EH = new GameArea(true, 319, 639);
	GameArea *FH = new GameArea(true, 383, 639);
	GameArea *GH = new GameArea(true, 447, 639);

	//neunte zeile von links nach rechts
	GameArea *AI = new GameArea(true, 63, 703);
	GameArea *BI = new GameArea(true, 127, 703);
	GameArea *CI = new GameArea(true, 191, 703);
	GameArea *DI = new GameArea(true, 255, 703);
	GameArea *EI = new GameArea(true, 319, 703);
	GameArea *FI = new GameArea(true, 383, 703);
	GameArea *GI = new GameArea(false, 447, 703);

	list<GameArea*> GameAreaList;

	//erste zeile von links nach rechts
	GameAreaList.push_back(AA);
	GameAreaList.push_back(BA);
	GameAreaList.push_back(CA);
	GameAreaList.push_back(DA);
	GameAreaList.push_back(EA);
	GameAreaList.push_back(FA);
	GameAreaList.push_back(GA);

	//zweite zeile von links nach rechts
	GameAreaList.push_back(AB);
	GameAreaList.push_back(BB);
	GameAreaList.push_back(CB);
	GameAreaList.push_back(DB);
	GameAreaList.push_back(EB);
	GameAreaList.push_back(FB);
	GameAreaList.push_back(GB);

	//dritte zeile von links nach rechts
	GameAreaList.push_back(AC);
	GameAreaList.push_back(BC);
	GameAreaList.push_back(CC);
	GameAreaList.push_back(DC);
	GameAreaList.push_back(EC);
	GameAreaList.push_back(FC);
	GameAreaList.push_back(GC);

	//vierte zeile von links nach rechts
	GameAreaList.push_back(AD);
	GameAreaList.push_back(BD);
	GameAreaList.push_back(CD);
	GameAreaList.push_back(DD);
	GameAreaList.push_back(ED);
	GameAreaList.push_back(FD);
	GameAreaList.push_back(GD);

	//fuenfte zeile von links nach rechts
	GameAreaList.push_back(AE);
	GameAreaList.push_back(BE);
	GameAreaList.push_back(CE);
	GameAreaList.push_back(DE);
	GameAreaList.push_back(EE);
	GameAreaList.push_back(FE);
	GameAreaList.push_back(GE);

	//sechste zeile von links nach rechts
	GameAreaList.push_back(AF);
	GameAreaList.push_back(BF);
	GameAreaList.push_back(CF);
	GameAreaList.push_back(DF);
	GameAreaList.push_back(EF);
	GameAreaList.push_back(FF);
	GameAreaList.push_back(GF);

	//siebte zeile von links nach rechts
	GameAreaList.push_back(AG);
	GameAreaList.push_back(BG);
	GameAreaList.push_back(CG);
	GameAreaList.push_back(DG);
	GameAreaList.push_back(EG);
	GameAreaList.push_back(FG);
	GameAreaList.push_back(GG);

	//achte zeile von links nach rechts
	GameAreaList.push_back(AH);
	GameAreaList.push_back(BH);
	GameAreaList.push_back(CH);
	GameAreaList.push_back(DH);
	GameAreaList.push_back(EH);
	GameAreaList.push_back(FH);
	GameAreaList.push_back(GH);

	//neunte zeile von links nach rechts
	GameAreaList.push_back(AI);
	GameAreaList.push_back(BI);
	GameAreaList.push_back(CI);
	GameAreaList.push_back(DI);
	GameAreaList.push_back(EI);
	GameAreaList.push_back(FI);
	GameAreaList.push_back(GI);

	return GameAreaList;
};

#endif