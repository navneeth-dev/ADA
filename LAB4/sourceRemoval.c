#include<stdio.h>
#include<stdlib.h>

#define MAX 100//source removal method

int graph[MAX][MAX];
int visited[MAX];
int indegree[MAX];
int num_nodes;

void initializeGraph() {
    int i, j;
    for (i = 0; i < num_nodes; i++) {
        visited[i] = 0;
        indegree[i] = 0;
        for (j = 0; j < num_nodes; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int from, int to) {
    graph[from][to] = 1;
    indegree[to]++;
}

void topologicalSort() {
    int i, j, k;
    for (i = 0; i < num_nodes; i++) {
        // Find a node with indegree 0
        for (j = 0; j < num_nodes; j++) {
            if (!visited[j] && indegree[j] == 0) {
                visited[j] = 1;
                printf("%d ", j);
                // Remove edges starting from this node
                for (k = 0; k < num_nodes; k++) {
                    if (graph[j][k]) {
                        indegree[k]--;
                    }
                }
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    int num_edges, i, from, to;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    initializeGraph();

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter the edges (from to): \n");
    for (i = 0; i < num_edges; i++) {
        scanf("%d %d", &from, &to);
        addEdge(from, to);
    }

    printf("Topological Sorting Order: ");
    topologicalSort();

    return 0;
}
