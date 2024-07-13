#include <stdio.h>

#define MAX 9999 // Infinity value for initial comparisons

void prims(int n, int cost[n][n]) {
    int i, j, u, min, sum = 0, source, K = 0;
    int S[n], d[n], P[n], T[n-1][2]; // T will store the edges of MST

    // Step 1: Find a source vertex with minimum edge going out
    min = MAX;
    source = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (cost[i][j] != 0 && cost[i][j] < min) {
                min = cost[i][j];
                source = i;
            }
        }
    }

    // Step 2: Initialization
    for (i = 0; i < n; i++) {
        S[i] = 0; // Not yet included in MST
        d[i] = cost[source][i]; // Initialize distances with cost from source
        P[i] = source; // Parent of each vertex initially is the source
    }

    // Step 3: Add source to S (visited set)
    S[source] = 1;

    // Step 4: Find MST edges
    for (i = 1; i < n; i++) {
        // Find u such that d[u] is minimum and u is not in S
        min = MAX;
        u = -1;
        for (j = 0; j < n; j++) {
            if (S[j] == 0 && d[j] <= min) {
                min = d[j];
                u = j;
            }
        }

        // Add edge to MST
        T[K][0] = u;
        T[K][1] = P[u];
        K++;

        // Add cost of edge to MST sum
        sum += cost[u][P[u]];

        // Add u to S (visited set)
        S[u] = 1;

        // Update d[] and P[] for adjacent vertices not in S
        for (j = 0; j < n; j++) {
            if (S[j] == 0 && cost[u][j] < d[j]) {
                d[j] = cost[u][j];
                P[j] = u;
            }
        }
    }

    // Step 5: Check if MST exists
    if (sum >= MAX) {
        printf("Spanning tree does not exist.\n");
    } else {
        printf("Spanning tree exists and MST is:\n");
        for (i = 0; i < n-1; i++) {
            printf("%d - %d\n", T[i][0], T[i][1]);
        }
        printf("The cost of spanning tree (MST) is %d\n", sum);
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];
    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    prims(n, cost);

    return 0;
}
