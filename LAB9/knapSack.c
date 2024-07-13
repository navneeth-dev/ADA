#include <stdio.h>

// Define the number of objects
#define N 4

// Function to compute the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the Knapsack problem using Dynamic Programming
void knapsack(int W, int weights[], int profits[]) {
    // Initialize DP table
    int dp[N + 1][W + 1];

    // Initialize DP table with 0s
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Maximum profit will be found in dp[N][W]
    int maxProfit = dp[N][W];
    printf("Maximum Profit: %d\n", maxProfit);

    // Finding which items are included
    int w = W;
    printf("Objects selected in the knapsack:\n");
    for (int i = N; i > 0 && maxProfit > 0; i--) {
        if (maxProfit == dp[i - 1][w])
            continue; // Item i was not included
        else {
            // Item i was included
            printf("Object %d (Weight = %d, Profit = %d)\n", i, weights[i - 1], profits[i - 1]);
            maxProfit -= profits[i - 1];
            w -= weights[i - 1];
        }
    }
}

int main() {
    // Given weights and profits of the objects
    int weights[] = {1, 2, 3, 4};
    int profits[] = {10, 12, 15, 20};

    // Knapsack capacity
    int W = 5;

    // Solve the knapsack problem
    knapsack(W, weights, profits);

    return 0;
}
