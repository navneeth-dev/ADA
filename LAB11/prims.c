#include <stdio.h>
#include <limits.h>

#define MAX 100

void primsAlgorithm(int costMatrix[MAX][MAX], int numVertices);

int main() {
    int numVertices, costMatrix[MAX][MAX];

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    // Input cost adjacency matrix
    printf("Enter cost adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &costMatrix[i][j]);
            if (costMatrix[i][j] == 0) {
                costMatrix[i][j] = INT_MAX; // Treat 0 as no edge
            }
        }
    }

    // Execute Prim's Algorithm
    primsAlgorithm(costMatrix, numVertices);

    return 0;
}

void primsAlgorithm(int costMatrix[MAX][MAX], int numVertices) {
    int selected[MAX] = {0};     // Array to track selected vertices
    int minCost[MAX];            // Array to store the minimum cost to connect to MST
    int parent[MAX];             // Array to store the parent vertex in MST
    int mstEdges[MAX][2];        // Array to store edges in the MST
    int totalCost = 0, edgeCount = 0;

    // Initialize the minimum cost array and parent array for the source vertex
    minCost[0] = 0; // Starting from vertex 0
    for (int i = 1; i < numVertices; i++) {
        minCost[i] = costMatrix[0][i];
        parent[i] = 0;
    }
    selected[0] = 1; // Mark the source vertex as selected

    // Main loop to find the MST
    for (int i = 1; i < numVertices; i++) {
        int min = INT_MAX, u = -1;

        // Find the minimum cost vertex that is not yet included in MST
        for (int j = 0; j < numVertices; j++) {
            if (!selected[j] && minCost[j] < min) {
                min = minCost[j];
                u = j;
            }
        }

        if (u == -1) break; // If no vertex found, break out of the loop

        // Include the chosen vertex in MST
        selected[u] = 1;
        mstEdges[edgeCount][0] = u;
        mstEdges[edgeCount][1] = parent[u];
        edgeCount++;
        totalCost += costMatrix[u][parent[u]];

        // Update the minimum cost and parent arrays
        for (int j = 0; j < numVertices; j++) {
            if (!selected[j] && costMatrix[u][j] < minCost[j]) {
                minCost[j] = costMatrix[u][j];
                parent[j] = u;
            }
        }
    }

    // Check if MST exists
    if (totalCost >= INT_MAX) {
        printf("Spanning tree does not exist\n");
    } else {
        // Output the MST edges and total cost
        printf("MST is:\n");
        for (int i = 0; i < edgeCount; i++) {
            printf("(%d, %d) ", mstEdges[i][0] + 1, mstEdges[i][1] + 1); // 1-based indexing for output
        }
        printf("\nThe cost of MST is %d\n", totalCost);
    }
}
