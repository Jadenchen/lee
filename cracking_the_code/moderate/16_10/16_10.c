#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

typedef struct hashtable {
    int year;
    int cnt;
} hashtable;

void addhash(hashtable *ptHash, int len, int curryear)
{
    int i = 0;
    int find = 0;
    for (i = 0; i < len; i++) {
        if (ptHash[i].year == curryear) {
            find = 1;
            break;
        }
    }
    //printf("i %d  find %d \n", i, find);
  
    if (find) {
        ptHash[i].cnt++;
    } else {
        for (i = 0; i < len; i++) {
            if (ptHash[i].year == 0) {
                ptHash[i].year = curryear;
                ptHash[i].cnt++;
                break;
            }
        }
    }
}

int findmost(hashtable *ptHash, int len)
{
    int max = ptHash[0].cnt;
    int index = 0;
    for (size_t i = 1; i < len; i++) {
        //printf("year %d cnt %d \n", ptHash[i].year, ptHash[i].cnt);
        if (max < ptHash[i].cnt) {
            index = i;
            max = ptHash[i].cnt;
        }
        
    }

    return ptHash[index].year;
}

int cmp(const void *a, const void *b)
{
    hashtable *pa = (hashtable *)a;
    hashtable *pb = (hashtable *)b;

    return pa->year - pb->year;
}

int maximumPopulation(int logs[][2], int logsSize, int* logsColSize)
{
    int size = 120;
    hashtable hash[size];
    int cnt = 0;
    memset(hash, 0, sizeof(hashtable)*size);
    //printf("size %d \n", size);

    for (size_t i = 0; i < logsSize; i++) {
        int curryear = logs[i][0];
        int deathyear = logs[i][1];
        //printf("cur %d dea %d \n", curryear, deathyear); 
        while(curryear < deathyear) {
            addhash(hash, size, curryear);
            curryear++;
        }
    }
    qsort(hash, size, sizeof(hashtable), cmp);
    //! find cnt most
    return findmost(hash, size);
}

int main(void)
{
	int a[3][2] = {{1950,1961}, {1960,1971}, {1970,1981}};
	int logsize = 3;
	int logColSize = 2;
	printf("year %d \n", maximumPopulation(a, logsize, &logColSize));

	return 0;
}
