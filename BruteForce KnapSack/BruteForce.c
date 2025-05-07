#include <stdio.h>

int n, W;
int weight[10], value[10];

int knapsack(int idx, int remainingWeight) {
    if (idx == n) return 0; // No items left to process
    if (remainingWeight < 0) return -1; // Invalid capacity
    
    // Case 1: Don't take the current item
    int exclude = knapsack(idx + 1, remainingWeight);
    
    // Case 2: Take the current item
    int include = -1;
    if (remainingWeight >= weight[idx]) {
        include = value[idx] + knapsack(idx + 1, remainingWeight - weight[idx]);
    }

    // Return the maximum value between taking or not taking the current item
    return (exclude > include) ? exclude : include;
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);
    
    printf("Enter weights and values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weight[i], &value[i]);
    }

    int maxValue = knapsack(0, W);
    printf("Maximum value in Knapsack = %d\n", maxValue);

    return 0;
}
