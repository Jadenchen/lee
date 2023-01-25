#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define N (200001)

typedef struct adjnode {
    int vex;
    struct adjnode *next;
} adjnode;

typedef struct graph {
    int numvex;
    adjnode *adj[N];
    int *visited;
} graph;

adjnode *new_adjnode(int vex)
{
    adjnode *new = calloc(1, sizeof(adjnode));
    new->vex = vex;
    return new;
}

graph *init_graph(int num)
{
    graph *new = calloc(1, sizeof(graph));
    new->visited = calloc(num, sizeof(int));
    new->numvex = num;
    for (int i = 0; i < num; i++) {
        adjnode *new_adj = new_adjnode(i);  
        new->adj[i] = new_adj;
    }
    return new;
}

//! bi direction
void add_edge_list(graph *g, int src, int dst)
{
    adjnode *cur = g->adj[src];
    //! add src
    adjnode *dst_node = new_adjnode(dst);
    while(cur->next)
        cur = cur->next;
    cur->next = dst_node;

    //! add dst
    cur = g->adj[dst];
    adjnode *src_node = new_adjnode(src);
    while(cur->next)
        cur = cur->next;
    cur->next = src_node;
}

bool validPath_bfs(int n, int edges[][2], int edgesSize, int* edgesColSize, int source, int destination)
{
    int queue[N];
    int front = 0;
    int end = 0;
    int top = 0;
    graph *g = NULL;
    adjnode *cur = NULL;
    int vex = 0;
    bool find = false;
    if (source == destination)
        return true;
    
    g = init_graph(n);

    for (int i = 0; i < edgesSize; i++) {
        add_edge_list(g, edges[i][0], edges[i][1]);
    }

    memset(queue, 0, sizeof(int)*N);
   
    g->visited[source] = 1;
    queue[front++] = source;

    while(end < front) {
        vex = queue[end++];
        cur = g->adj[vex];
        while(cur) {
            if (g->visited[cur->vex] == 0) {
                g->visited[cur->vex] = 1;
                if (cur->vex == destination) {
                    find = true;
                    break;
                } else {
                    queue[front++] = cur->vex;
                }
            }
            cur = cur->next;
        }
        if (find)
            break;
    }
    return find;
}

bool validPath_dfs(int n, int edges[][2], int edgesSize, int* edgesColSize, int source, int destination)
{
    int stack[N];
    int top = 0;
    graph *g = NULL;
    adjnode *cur = NULL;
    int vex = 0;
    bool find = false;
    if (source == destination)
        return true;
    
    g = init_graph(n);
    for (int i = 0; i < edgesSize; i++) {
        add_edge_list(g, edges[i][0], edges[i][1]);
    }

    memset(stack, 0, sizeof(int)*N);
   
    g->visited[source] = 1;
    stack[top++] = source;
    while(top) {
        vex = stack[--top];
      
        if (vex == destination) {
            find = true;
            break;
        }
        cur = g->adj[vex]; 
        while(cur) {
            if (g->visited[cur->vex] == 0) {
                g->visited[cur->vex] = 1;
                stack[top++] = cur->vex;
            }
            cur = cur->next;
        }
    }

    return find;
}

int main(void)
{
	int a[][2] = {{0,1}, {1,2}, {2,0}};
	int edgesSize = 3;
	int n = 3;
	int edgesColSize = 2;
	int source = 0;
	int destination = 2;
	printf("has path bfs %d \n", validPath_bfs(n, a, edgesSize, &edgesColSize, source, destination)); 
	printf("has path dfs %d \n", validPath_dfs(n, a, edgesSize, &edgesColSize, source, destination)); 
	return 0 ;
}
