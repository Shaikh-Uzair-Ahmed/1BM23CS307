    int n[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int sum = 0;
    for(int i=0; i<3; i++){
        sum += n[i][i];
    }
    printf("Sum of left diagonal elements is: %d\n", sum);