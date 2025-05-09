#include <stdio.h>
#include <limits.h>

int n = 4;

int dist[4][4] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int visited[4];
int minCost = INT_MAX;
int path[4];
int bestPath[4];

void tsp(int city, int count, int costSoFar) {
    if (count == n) {
        int totalCost = costSoFar + dist[city][0];
        if (totalCost < minCost) {
            minCost = totalCost;
            for (int i = 0; i < n; i++) {
                bestPath[i] = path[i];
            }
        }
        return;
    }

    for (int nextCity = 0; nextCity < n; nextCity++) {
        if (!visited[nextCity]) {
            visited[nextCity] = 1;
            path[count] = nextCity;
            tsp(nextCity, count + 1, costSoFar + dist[city][nextCity]);
            visited[nextCity] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < n; i++) visited[i] = 0;

    visited[0] = 1;
    path[0] = 0;
    tsp(0, 1, 0);

    printf("Minimum cost: %d\n", minCost);
    printf("Optimal path: ");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", bestPath[i] + 1);
    }
    printf("1\n"); // Return to starting city

    return 0;
}
