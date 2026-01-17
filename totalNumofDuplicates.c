#include<stdio.h>
#include<stdlib.h>

int main(){
    int n[] = {20,20,20,20,30,30,30,10,15, 20,10};
    int size = sizeof(n)/sizeof(n[0]);
    int count = 0;
    for(int i = 0; i<size; i++){
        for(int j = i+1; j<size; j++){
            if(n[i]>n[j]){
                int temp = n[i];
                n[i] = n[j];
                n[j] = temp;
            }
        }
    }

    for(int i=0;i<size;i++){
        if(n[i]==n[i+1]){
            int temp = n[i];
            count +=1;
            while(n[i]==temp && i<size){
                i++;
            }
        }
    }

    printf("Total number of duplicates are: %d\n", count);
    return 0;
}

