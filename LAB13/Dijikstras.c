#include <stdio.h>
#define MAX 9999 // Infinity value assumed

void dijkstras(int c[][100], int n, int src);

int main() {
    int n, src, i, j;
    int c[100][100]; // Assuming a maximum size for the cost matrix

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("Enter the source node (1 to %d): ", n);
    scanf("%d", &src);

    dijkstras(c, n, src);

    return 0;
}

void dijkstras(int c[][100], int n, int src) {
    int dist[100], vis[100];
    int count, min, u, i, j;

    // Initialization
    for (j = 1; j <= n; j++) {
        dist[j] = c[src][j];
        vis[j] = 0;
    }

    dist[src] = 0;
    vis[src] = 1;
    count = 1;

    // Main loop
    while (count != n) {
        min = MAX;

        // Find the minimum distance vertex from the set of vertices not yet processed
        for (j = 1; j <= n; j++) {
            if (dist[j] < min && vis[j] != 1) {
                min = dist[j];
                u = j;
            }
        }

        vis[u] = 1;
        count++;

        // Update dist value of the adjacent vertices of the picked vertex
        for (j = 1; j <= n; j++) {
            if (min + c[u][j] < dist[j] && vis[j] != 1) {
                dist[j] = min + c[u][j];
            }
        }
    }

    // Output shortest distances
    printf("Shortest distances from node %d:\n", src);
    for (j = 1; j <= n; j++) {
        printf("Distance to node %d from node %d: %d\n", j, src, dist[j]);
    }
}
