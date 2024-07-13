#include <stdio.h>
#include <limits.h>

// Function to implement Floyd's algorithm for all-pairs shortest paths
void floyd(int n, int cost[][n], int D[][n]) {
    int i, j, k;

    // Step 1: Initialize D to be the cost adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            D[i][j] = cost[i][j];
        }
    }

    // Step 2: Apply Floyd's algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                // Update D[i][j] to be the minimum of its current value or the path through k
                if (D[i][k] != INT_MAX && D[k][j] != INT_MAX && D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

// Function to print the computed shortest paths matrix
void printShortestPaths(int n, int D[][n]) {
    printf("Shortest paths between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (D[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", D[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n; // Number of vertices in the graph
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    int cost[n][n]; // Cost adjacency matrix
    printf("Enter the cost adjacency matrix (use 'INF' for infinity):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            {
            scanf("%d", &cost[i][j]);
            }
        }
    // D will hold the shortest path distances between every pair of vertices
    int D[n][n];

    // Call Floyd's algorithm to compute shortest paths
    floyd(n, cost, D);

    // Print the shortest paths matrix
    printShortestPaths(n, D);

    return 0;
}
