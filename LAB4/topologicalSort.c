#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int num_nodes;

void initializeGraph() {
    int i, j;
    for (i = 0; i < num_nodes; i++) {
        visited[i] = 0;
        stack[i] = -1;
        for (j = 0; j < num_nodes; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int from, int to) {
    graph[from][to] = 1;
}

void dfs(int node) {
    int i;
    visited[node] = 1;
    for (i = 0; i < num_nodes; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }
    stack[++top] = node;
}

void topologicalSort() {
    int i;
    for (i = 0; i < num_nodes; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    printf("Topological Sorting Order: ");
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int num_edges, i, from, to;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_nodes);
    initializeGraph();

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter the edges (from to): \n");
    for (i = 0; i < num_edges; i++) {
        scanf("%d %d", &from, &to);
        addEdge(from, to);
    }

    topologicalSort();

    return 0;
}
