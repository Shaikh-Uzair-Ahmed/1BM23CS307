#include<stdio.h>
#include<stdlib.h>

int main(){
    int n[] = {20,30,10,43,25};
    int size = sizeof(n)/sizeof(n[0]);
    for(int i = 0; i<size; i++){
        for(int j = i+1; j<size; j++){
            if(n[i]>n[j]){
                int temp = n[i];
                n[i] = n[j];
                n[j] = temp;
            }
        }
    }
    printf("Second smallest element is: %d\n", n[1]);
    return 0;
}