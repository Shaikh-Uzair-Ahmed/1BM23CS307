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

void tsp(int city, int count, int costSoFar) {
    if (count == n) {
        if (costSoFar + dist[city][0] < minCost) {
            minCost = costSoFar + dist[city][0];
            path[count - 1] = city;
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
    visited[0] = 1;  // Start from the first city
    path[0] = 0;  // Starting point
    tsp(0, 1, 0);

    printf("Minimum cost: %d\n", minCost);
    printf("Optimal path: ");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", path[i] + 1);
    }
    printf("1\n");

    return 0;
}
