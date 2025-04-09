#include <stdio.h>

int n;
int a[10][10];
int D[10][10];

void write_data() {
    int i, j;
    printf("The Distance matrix is shown below\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d", D[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

void read_data() {
    int i, j;
    printf("Enter the no of nodes\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

}



int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

void Floyd() {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            D[i][j] = a[i][j];
        }
    }
    
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {          
                D[i][j]=min(D[i][j],(D[i][k]+D[k][j]));
            }
        }
    }
}


int main() {
    read_data();
    Floyd();
    write_data();
    return 0;
}