#include <stdio.h>
#include <limits.h>

int cost[4][4] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

int n = 4;
int assignment[4];
int minCost = INT_MAX;

void findAssignment(int row, int costMatrix[4][4], int visited[], int currentAssignment[], int currentCost) {
    if (row == n) {
        if (currentCost < minCost) {
            minCost = currentCost;
            for (int i = 0; i < n; i++) {
                assignment[i] = currentAssignment[i];
            }
        }
        return;
    }

    for (int col = 0; col < n; col++) {
        if (!visited[col]) {
            visited[col] = 1;
            currentAssignment[row] = col;
            findAssignment(row + 1, costMatrix, visited, currentAssignment, currentCost + costMatrix[row][col]);
            visited[col] = 0;
        }
    }
}

int main() {
    int visited[4] = {0};
    int currentAssignment[4];
    findAssignment(0, cost, visited, currentAssignment, 0);

    printf("Minimum cost: %d\n", minCost);
    printf("Optimal assignment:\n");
    for (int i = 0; i < n; i++) {
        printf("Task %d -> Worker %d\n", i + 1, assignment[i] + 1);
    }

    return 0;
}
