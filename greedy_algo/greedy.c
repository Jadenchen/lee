#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "greedy.h"

bool lemonadeChange(int* bills, int billsSize)
{
	bool enought = true;
	const int lemon = 5;
	int fivecnts = 0;
	for (int i = 0; i < billsSize; i++) {
		if (bills[i] == 5) {
			fivecnts++;
		} else {
			int left = bills[i] - lemon;
			int j = 0;
			for (j = 1; j <= fivecnts; j++) {
				left = left - lemon;
				if (left == 0) {
					fivecnts = fivecnts - j;
					break;
				}
			}
			if (left) {
				enought = false;
				break;
			}
		}
	}

	return enought;
}
