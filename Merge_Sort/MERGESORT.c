#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *a; 

void mergeSort(int a[], int low, int high);
void merge(int a[], int low, int high, int mid);

int main() {
    int n;
    printf("Enter Number of Elements");  
    scanf("%d", &n);  
    a = (int*)malloc(sizeof(int) * n); 
    
    
    for (int i = 0; i < n; ++i) {
        a[i]=rand();
    }

    
    clock_t start = clock(); 
    mergeSort(a, 0, n - 1);  
    clock_t end = clock();  

 
    double t = ((double)(end - start)) / CLOCKS_PER_SEC;  
    
   
    printf("Sorted Array\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);  
    }
    printf("\n");
    
    
    printf("%.30f\n", t); 
    
    
    free(a);

    return 0;
}


void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;  
        mergeSort(a, low, mid);  
        mergeSort(a, mid + 1, high);  
        merge(a, low, high, mid);  
    }
}


void merge(int a[], int low, int high, int mid) {
    int *tmp = (int*)malloc((high - low + 1) * sizeof(int));  
    int i = low, j = mid + 1, k = 0;

    
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        tmp[k++] = a[i++];
    }

  
    while (j <= high) {
        tmp[k++] = a[j++];
    }


    for (int i = 0; i < (high - low + 1); ++i) {
        a[low + i] = tmp[i];
    }

    free(tmp);
}
