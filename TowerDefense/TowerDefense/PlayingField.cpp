#include "GameArea.h"
#include <list>
class PlayingField {
public:
	vector<GameArea*> getPlayingField() {
		//erste zeile von links nach rechts
		GameArea *AA = new GameArea(false, 63, 191, 1, 1, 0);
		GameArea *BA = new GameArea(true, 127, 191, 2, 1, 1);
		GameArea *CA = new GameArea(true, 191, 191, 3, 1, 2);
		GameArea *DA = new GameArea(true, 255, 191, 4, 1, 3);
		GameArea *EA = new GameArea(true, 319, 191, 5, 1, 4);
		GameArea *FA = new GameArea(true, 383, 191, 6, 1, 5);
		GameArea *GA = new GameArea(true, 447, 191, 7, 1, 6);

		//zweite zeile von links nach rechts
		GameArea *AB = new GameArea(true, 63, 255, 1, 2, 7);
		GameArea *BB = new GameArea(true, 127, 255, 2, 2, 8);
		GameArea *CB = new GameArea(true, 191, 255, 3, 2, 9);
		GameArea *DB = new GameArea(true, 255, 255, 4, 2, 10);
		GameArea *EB = new GameArea(true, 319, 255, 5, 2, 11);
		GameArea *FB = new GameArea(true, 383, 255, 6, 2, 12);
		GameArea *GB = new GameArea(true, 447, 255, 7, 2, 13);

		//dritte zeile von links nach rechts
		GameArea *AC = new GameArea(true, 63, 319, 1, 3, 14);
		GameArea *BC = new GameArea(true, 127, 319, 2, 3, 15);
		GameArea *CC = new GameArea(true, 191, 319, 3, 3, 16);
		GameArea *DC = new GameArea(true, 255, 319, 4, 3, 17);
		GameArea *EC = new GameArea(true, 319, 319, 5, 3, 18);
		GameArea *FC = new GameArea(true, 383, 319, 6, 3, 19);
		GameArea *GC = new GameArea(true, 447, 319, 7, 3, 20);

		//vierte zeile von links nach rechts
		GameArea *AD = new GameArea(true, 63, 383, 1, 4, 21);
		GameArea *BD = new GameArea(true, 127, 383, 2, 4, 22);
		GameArea *CD = new GameArea(true, 191, 383, 3, 4, 23);
		GameArea *DD = new GameArea(true, 255, 383, 4, 4, 24);
		GameArea *ED = new GameArea(true, 319, 383, 5, 4, 25);
		GameArea *FD = new GameArea(true, 383, 383, 6, 4, 26);
		GameArea *GD = new GameArea(true, 447, 383, 7, 4, 27);

		//fuenfte zeile von links nach rechts
		GameArea *AE = new GameArea(true, 63, 447, 1, 5, 28);
		GameArea *BE = new GameArea(true, 127, 447, 2, 5, 29);
		GameArea *CE = new GameArea(true, 191, 447, 3, 5, 30);
		GameArea *DE = new GameArea(true, 255, 447, 4, 5, 31);
		GameArea *EE = new GameArea(true, 319, 447, 5, 5, 32);
		GameArea *FE = new GameArea(true, 383, 447, 6, 5, 33);
		GameArea *GE = new GameArea(true, 447, 447, 7, 5, 34);

		//sechste zeile von links nach rechts
		GameArea *AF = new GameArea(true, 63, 511, 1, 6, 35);
		GameArea *BF = new GameArea(true, 127, 511, 2, 6, 36);
		GameArea *CF = new GameArea(true, 191, 511, 3, 6, 37);
		GameArea *DF = new GameArea(true, 255, 511, 4, 6, 38);
		GameArea *EF = new GameArea(true, 319, 511, 5, 6, 39);
		GameArea *FF = new GameArea(true, 383, 511, 6, 6, 40);
		GameArea *GF = new GameArea(true, 447, 511, 7, 6, 41);

		//siebte zeile von links nach rechts
		GameArea *AG = new GameArea(true, 63, 575, 1, 7, 42);
		GameArea *BG = new GameArea(true, 127, 575, 2, 7, 43);
		GameArea *CG = new GameArea(true, 191, 575, 3, 7, 44);
		GameArea *DG = new GameArea(true, 255, 575, 4, 7, 45);
		GameArea *EG = new GameArea(true, 319, 575, 5, 7, 46);
		GameArea *FG = new GameArea(true, 383, 575, 6, 7, 47);
		GameArea *GG = new GameArea(true, 447, 575, 7, 7, 48);

		//achte zeile von links nach rechts
		GameArea *AH = new GameArea(true, 63, 639, 1, 8, 49);
		GameArea *BH = new GameArea(true, 127, 639, 2, 8, 50);
		GameArea *CH = new GameArea(true, 191, 639, 3, 8, 51);
		GameArea *DH = new GameArea(true, 255, 639, 4, 8, 52);
		GameArea *EH = new GameArea(true, 319, 639, 5, 8, 53);
		GameArea *FH = new GameArea(true, 383, 639, 6, 8, 54);
		GameArea *GH = new GameArea(true, 447, 639, 7, 8, 55);

		//neunte zeile von links nach rechts
		GameArea *AI = new GameArea(true, 63, 703, 1, 9, 56);
		GameArea *BI = new GameArea(true, 127, 703, 2, 9, 57);
		GameArea *CI = new GameArea(true, 191, 703, 3, 9, 58);
		GameArea *DI = new GameArea(true, 255, 703, 4, 9, 59);
		GameArea *EI = new GameArea(true, 319, 703, 5, 9, 60);
		GameArea *FI = new GameArea(true, 383, 703, 6, 9, 61);
		GameArea *GI = new GameArea(false, 447, 703, 7, 9, 62);

		vector<GameArea*> GameAreaVector;

		//erste zeile von links nach rechts
		GameAreaVector.push_back(AA);
		GameAreaVector.push_back(BA);
		GameAreaVector.push_back(CA);
		GameAreaVector.push_back(DA);
		GameAreaVector.push_back(EA);
		GameAreaVector.push_back(FA);
		GameAreaVector.push_back(GA);

		//zweite zeile von links nach rechts
		GameAreaVector.push_back(AB);
		GameAreaVector.push_back(BB);
		GameAreaVector.push_back(CB);
		GameAreaVector.push_back(DB);
		GameAreaVector.push_back(EB);
		GameAreaVector.push_back(FB);
		GameAreaVector.push_back(GB);

		//dritte zeile von links nach rechts
		GameAreaVector.push_back(AC);
		GameAreaVector.push_back(BC);
		GameAreaVector.push_back(CC);
		GameAreaVector.push_back(DC);
		GameAreaVector.push_back(EC);
		GameAreaVector.push_back(FC);
		GameAreaVector.push_back(GC);

		//vierte zeile von links nach rechts
		GameAreaVector.push_back(AD);
		GameAreaVector.push_back(BD);
		GameAreaVector.push_back(CD);
		GameAreaVector.push_back(DD);
		GameAreaVector.push_back(ED);
		GameAreaVector.push_back(FD);
		GameAreaVector.push_back(GD);

		//fuenfte zeile von links nach rechts
		GameAreaVector.push_back(AE);
		GameAreaVector.push_back(BE);
		GameAreaVector.push_back(CE);
		GameAreaVector.push_back(DE);
		GameAreaVector.push_back(EE);
		GameAreaVector.push_back(FE);
		GameAreaVector.push_back(GE);

		//sechste zeile von links nach rechts
		GameAreaVector.push_back(AF);
		GameAreaVector.push_back(BF);
		GameAreaVector.push_back(CF);
		GameAreaVector.push_back(DF);
		GameAreaVector.push_back(EF);
		GameAreaVector.push_back(FF);
		GameAreaVector.push_back(GF);

		//siebte zeile von links nach rechts
		GameAreaVector.push_back(AG);
		GameAreaVector.push_back(BG);
		GameAreaVector.push_back(CG);
		GameAreaVector.push_back(DG);
		GameAreaVector.push_back(EG);
		GameAreaVector.push_back(FG);
		GameAreaVector.push_back(GG);

		//achte zeile von links nach rechts
		GameAreaVector.push_back(AH);
		GameAreaVector.push_back(BH);
		GameAreaVector.push_back(CH);
		GameAreaVector.push_back(DH);
		GameAreaVector.push_back(EH);
		GameAreaVector.push_back(FH);
		GameAreaVector.push_back(GH);

		//neunte zeile von links nach rechts
		GameAreaVector.push_back(AI);
		GameAreaVector.push_back(BI);
		GameAreaVector.push_back(CI);
		GameAreaVector.push_back(DI);
		GameAreaVector.push_back(EI);
		GameAreaVector.push_back(FI);
		GameAreaVector.push_back(GI);

		for (int i = 0; i < 63; i++) {
			//klammern richtig?
			if (GameAreaVector.at(i)->getXID() > 1) {
				GameAreaVector.at(i)->addConnected(GameAreaVector.at((GameAreaVector.at(i)->getID() - 1)));
			}
			if (GameAreaVector.at(i)->getXID() < 7) {
				GameAreaVector.at(i)->addConnected(GameAreaVector.at((GameAreaVector.at(i)->getID() + 1)));
			}
			if (GameAreaVector.at(i)->getYID() > 1) {
				GameAreaVector.at(i)->addConnected(GameAreaVector.at((GameAreaVector.at(i)->getID() - 7)));
			}
			if (GameAreaVector.at(i)->getYID() < 9) {
				GameAreaVector.at(i)->addConnected(GameAreaVector.at((GameAreaVector.at(i)->getID() + 7)));
			}
		}

		//distance zur zielzelle für alle zellen bestimmen.
		for (int i = 0; i < 63; i++) {
			GameAreaVector.at(i)->setWholeDistance((abs(GameAreaVector.at(i)->getXID() - GameAreaVector.at(62)->getXID()))
				+ (abs(GameAreaVector.at(i)->getYID() - GameAreaVector.at(62)->getYID())));
		}

		return GameAreaVector;
	};
};