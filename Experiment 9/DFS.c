/*Write a C program to implement and perform a Depth-First Search (DFS) on a directed graph represented using an adjacency list.
The program should print all vertices reachable from a given starting vertex in the order they are visited by DFS.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

int main() {
    int V, E, u, v, start;
    struct Node* adj[MAX];
    int visited[MAX];

    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode1 = (struct Node*)malloc(sizeof(struct Node));
        newNode1->vertex = v;
        newNode1->next = adj[u];
        adj[u] = newNode1;

        struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
        newNode2->vertex = u;
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    for (int i = 0; i < V; i++) {
        struct Node *p, *q;
        for (p = adj[i]; p != NULL; p = p->next) {
            for (q = p->next; q != NULL; q = q->next) {
                if (p->vertex > q->vertex) {
                    int temp = p->vertex;
                    p->vertex = q->vertex;
                    q->vertex = temp;
                }
            }
        }
    }

    scanf("%d", &start);

    int stack[MAX], top = -1;
    stack[++top] = start;

    while (top != -1) {
        int curr = stack[top--];

        if (!visited[curr]) {
            printf("%d ", curr);
            visited[curr] = 1;
        }

        struct Node* temp = adj[curr];
        int tempArr[MAX], k = 0;

        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                tempArr[k++] = temp->vertex;
            }
            temp = temp->next;
        }

        for (int i = k - 1; i >= 0; i--) {
            if (top < MAX - 1)
                stack[++top] = tempArr[i];
        }
    }

    for (int i = 0; i < V; i++) {
        struct Node* temp = adj[i];
        while (temp != NULL) {
            struct Node* next = temp;
            temp = temp->next;
            free(next);
        }
    }

    return 0;
}
