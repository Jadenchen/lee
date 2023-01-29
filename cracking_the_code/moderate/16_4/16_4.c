#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

char * tictactoe(int** moves, int movesSize, int* movesColSize)
{
    int tmp[3][3];
    
    int val = 0;
    int x = 0;
    int y = 0;
    char *res = NULL;
    int cntA = 0; //! 1
    int cntB = 0; //! 2
    int cntEmpty = 0;
    int horwin = 0;
    int verwin = 0;
    int corwin = 0;
    for (int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            tmp[i][j] = 0;

    for (int i = 0; i < movesSize; i++) {
        val = (i % 2) ? 1 : 2;
        x = moves[i][0];
        y = moves[i][1];
        tmp[x][y]= val;        
    }   

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", tmp[i][j]);
        }
        printf("\n");
    }

    //! hori
    for (int i = 0; i < 3; i++) {
        cntA = 0;
        cntB = 0;
        if (tmp[i][0] == 1) {
            cntB++;
        } else if (tmp[i][0] == 2)
            cntA++;

        if (tmp[i][1] == 1) {
            cntB++;
        } else if (tmp[i][1] == 2)
            cntA++;

        if (tmp[i][2] == 1) {
            cntB++;
        } else if (tmp[i][2] == 2)
            cntA++;

        if (cntA == 3 || cntB == 3) {
            res = calloc(2, sizeof(char));
            res = (cntA == 3) ? "A" : "B";
        goto LEAVE;
    } 
    }
     
   

    //! ver
    for (int i = 0; i < 3; i++) {

    cntA = 0;
    cntB = 0;
        if (tmp[0][i] == 1) {
            cntB++;
        } else if (tmp[0][i] == 2)
            cntA++;

         if (tmp[1][i] == 1) {
            cntB++;
        } else if (tmp[1][i] == 2)
            cntA++;

        if (tmp[2][i] == 1) {
            cntB++;
        } else if (tmp[2][i] == 2)
            cntA++;
        if (cntA == 3 || cntB == 3) {
            res = calloc(2, sizeof(char));
            res = (cntA == 3) ? "A" : "B";
            goto LEAVE;
        } 
    }
     printf("0 cntA %d cntB %d \n", cntA, cntB);
    

    cntA = 0;
    cntB = 0;
    for (int i = 0; i < 3; i++) {
        if (tmp[i][i] == 1) {
            cntB++;
        } else if (tmp[i][i] == 2)
            cntA++;
    }
    printf("1 cntA %d cntB %d \n", cntA, cntB);
    if (cntA == 3 || cntB == 3) {
        res = calloc(2, sizeof(char));
        res = (cntA == 3) ? "A" : "B";
        goto LEAVE;
    } 

    cntA = 0;
    cntB = 0;
    for (int i = 0; i < 3; i++) {
        if (tmp[i][2 - i] == 1) {
            cntB++;
        } else if (tmp[i][2 - i] == 2)
            cntA++;
    }
    printf("2 cntA %d cntB %d \n", cntA, cntB);
    if (cntA == 3 || cntB == 3) {
        res = calloc(2, sizeof(char));
        res = cntA == 3 ? "A" : "B";
        goto LEAVE;
    } 

    return movesSize == 9 ? "Draw" : "Pending";

LEAVE: 
    return res;
    
}
int main(void)
{
	return 0;
}
