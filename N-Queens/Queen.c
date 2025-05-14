#include <stdio.h>
#include <math.h>

int x[20], count = 1;  // Array to store the positions of the queens

void queens(int k, int n);
int place(int k, int j);

int main() {
    int n, k = 1;
    printf("\nEnter the number of queens to be placed: ");
    scanf("%d", &n);
    queens(k, n);
    return 0;
}

void queens(int k, int n) {
    int j;
    for (j = 1; j <= n; j++) {
        if (place(k, j)) {
            x[k] = j;  // Place the queen in the current position
            if (k == n) {  // If all queens are placed
                printf("\nSolution %d:\n", count);
                count++;
                for (int i = 1; i <= n; i++) {
                    printf("\tRow %d <---> Column %d\n", i, x[i]);
                }
                printf("\n");
            } else {
                queens(k + 1, n);  // Try to place the next queen
            }
        }
    }
}

int place(int k, int j) {
    for (int i = 1; i < k; i++) {
        // Check if the queen is in the same column or on the same diagonal
        if (x[i] == j || abs(x[i] - j) == abs(i - k)) {
            return 0;  // Conflict detected
        }
    }
    return 1;  // No conflict, safe to place the queen
}
