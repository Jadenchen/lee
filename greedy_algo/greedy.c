#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "greedy.h"

bool lemonadeChange(int* bills, int billsSize)
{
	bool enought = true;
	//const int lemon = 5;
	int fivecnts = 0;
	int tencnts = 0;
	for (int i = 0; i < billsSize; i++) {
		if (bills[i] == 5) {
			fivecnts++;
		} else if (bills[i] == 10) {
			if (fivecnts) {
				fivecnts--;
				tencnts++;
			} else {
				enought = false;
				break;
			}
		} else if (bills[i] == 20) {
			if (tencnts && fivecnts) {
				tencnts--;
				fivecnts--;
			} else if (fivecnts >= 3) {
				fivecnts = fivecnts - 3;
			} else {
				enought = false;
				break;
			}
		}
	}
	return enought;
}
