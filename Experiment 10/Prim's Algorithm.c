/*Write a C program to find the Minimum Spanning Tree (MST) of a connected, weighted, undirected graph using Prim’s Algorithm.*/

#include <stdio.h>
#include <limits.h>
#define MAX 100
int main() {
    int V;
    int graph[MAX][MAX];
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];
    scanf("%d", &V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[0] = 0;      
    parent[0] = -1;  
    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX;
        int u;
        for (int i = 0; i < V; i++) {
            if (mstSet[i] == 0 && key[i] < min) {
                min = key[i];
                u = i;
            }
        }
        mstSet[u] = 1;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
    return 0;
}
