#include<stdio.h>
#include<stdlib.h>

int main(){
    int n[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int sumRow = 0;
    int sumColumn = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            sumRow += n[i][j];
            sumColumn += n[j][i];
        }
        printf("Sum of %d row is: %d\n", i+1, sumRow);
        printf("Sum of %d column is: %d\n", i+1, sumColumn);
        sumRow = 0;
        sumColumn = 0;
    }
    return 0;
}