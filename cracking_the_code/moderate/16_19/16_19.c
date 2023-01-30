#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))
#define MAX(x, y) (x) > (y) ? (x) : (y)

#define SIZE (100)
typedef struct queue {
    int data[SIZE];
    int front;
    int end;
} queue;   

void helper(char **grid, int **visited, int i, int j, int gridSize, int gridColSize)
{
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize || visited[i][j] || grid[i][j] == '0')
        return;
    visited[i][j] = 1;
    helper(grid, visited, i - 1, j, gridSize, gridColSize);
    helper(grid, visited, i + 1, j, gridSize, gridColSize);
    helper(grid, visited, i, j - 1, gridSize, gridColSize);
    helper(grid, visited, i, j + 1, gridSize, gridColSize);
}

void push(queue *pq, int data)
{
    int index = pq->front % SIZE;
    pq->data[index] = data;
    pq->front = (pq->front + 1) % SIZE;
}

int pop(queue *pq)
{
    int index = pq->end % SIZE;
    pq->end = (pq->end + 1) % SIZE;
    return pq->data[index];
}

int isEmpty(queue *pq)
{
    return pq->front == pq->end;
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    #if 0
    //DFS 
    int res = 0;
    int **visited = NULL;
    if (gridSize == 0 || *gridColSize == 0) 
        return res;

    visited = (int **)calloc(gridSize, sizeof(int *));
    for (int i = 0; i < gridSize; i++) {
        visited[i] = calloc(*gridColSize, sizeof(int));
    }

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == '0' || visited[i][j])
                continue;
            helper(grid, visited, i, j, gridSize, *gridColSize);
            res++;
        }
    }

    return res;
    #else 

    //! BFS
    int res = 0;
    int **visited = NULL;
    queue data;
    int dirx[4] = {-1, 0, 1, 0};
    int diry[4] = {0, 1, 0, -1};
    
    if (gridSize == 0 || *gridColSize == 0) 
        return res;

    visited = (int **)calloc(gridSize, sizeof(int *));
    for (int i = 0; i < gridSize; i++) {
        visited[i] = calloc(*gridColSize, sizeof(int));
    }

    memset(&data, 0, sizeof(queue));
     for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < (*gridColSize); j++) {
            if (grid[i][j] == '0' || visited[i][j])
                continue;
            //helper(grid, visited, i, j, gridSize, *gridColSize);
            res++;
            push(&data, j + i *(*gridColSize));
            while(!isEmpty(&data)) {
                int index = pop(&data);
                for (int k = 0; k < 4; k++) {
                    int x = index/(*gridColSize) + dirx[k]; 
                    int y = index % (*gridColSize) + diry[k];
                    if (x < 0 || x >= gridSize || y < 0 || y >= *gridColSize || grid[x][y] == '0' || 
                        visited[x][y]) {
                        continue;
                    }
                    visited[x][y] = 1;
                    push(&data, x* (*gridColSize) + y);
                }
            }
            
        }
    }

    return res;
    #endif
}
int main(void)
{
#if 0
	char grid[][10] = {
			{"1","1","1","1","0"}, 
			{"1","1","0","1","0"}, 
			{"1","1","0","0","0"}, 
			{"0","0","0","0","0"}};
	
	int gridSize = 4;
	int gridColSize = 10;
	printf("island num %d \n", numIslands(grid, gridSize, &gridColSize));
#endif
	return 0;
}
