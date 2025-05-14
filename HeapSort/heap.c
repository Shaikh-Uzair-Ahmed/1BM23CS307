#include <stdio.h>
#include <time.h>

void heapify(int a[], int n, int i) {
    int largest = i;  
    int left = 2*i + 1;
    int right = 2*i + 2;
    int temp;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    int temp;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

int main() {
    int n, a[20], ch = 1;
    clock_t start, end;

    while (ch) {
        printf("\nEnter the number of elements to sort: ");
        scanf("%d", &n);

        printf("Enter the elements to sort: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        start = clock();
        heapSort(a, n);
        end = clock();

        printf("\nThe sorted list of elements is:\n");
        for (int i = 0; i < n; i++) {
            printf("%d\n", a[i]);
        }

        printf("\nTime taken is %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        printf("Do you wish to run again (0/1)? ");
        scanf("%d", &ch);
    }

    return 0;
}

