#include <stdio.h>

void main() {
    int i, j, n, v, k, min, u, c[20][20], s[20], d[20];
    

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:");
    printf("\n(Enter 999 for no edge)\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("\nEnter the source vertex: ");
    scanf("%d", &v);

    // Initialize distances and visited set
    for (i = 1; i <= n; i++) {
        s[i] = 0;
        d[i] = c[v][i];
    }

    d[v] = 0;
    s[v] = 1;

    for (k = 2; k <= n; k++) {
        min = 999;

        // Find the minimum distance vertex from the set of vertices not yet processed
        for (i = 1; i <= n; i++) {
            if ((s[i] == 0) && (d[i] < min)) {
                min = d[i];
                u = i;
            }
        }

        s[u] = 1;

        // Update distance value of the adjacent vertices
        for (i = 1; i <= n; i++) {
            if (s[i] == 0) {
                if (d[i] > (d[u] + c[u][i])) {
                    d[i] = d[u] + c[u][i];
                }
            }
        }
    }

    printf("\nThe shortest distances from vertex %d are:\n", v);
    for (i = 1; i <= n; i++) {
        printf("%d --> %d = %d\n", v, i, d[i]);
    }

}
