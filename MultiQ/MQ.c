#include<stdio.h>
#include<stdlib.h>

#define MAX 10
#define MAXNAME 20

int c = 0;

typedef struct{
    int id, AT, BT, TAT, WT, CT;
    char name[MAXNAME];
}Process;

void print_process_data(Process q[], int n) {
    printf("PID\tName\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n", q[i].id,q[i].name, q[i].AT, q[i].BT, q[i].CT, q[i].TAT, q[i].WT);
    }

    int ttat = 0, twt = 0;
    for (int i = 0; i < n; i++) {
        ttat += q[i].TAT;
        twt += q[i].WT;
    }

    double avg_tat = (double)ttat / n;
    double avg_wt = (double)twt / n;

    printf("Average Turn-around time: %lf\n", avg_tat);
    printf("Average Waiting time: %lf\n", avg_wt);
}


void sorted(Process q[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) { 
            if (q[j].AT > q[j + 1].AT || (q[j].AT == q[j + 1].AT && q[j].id > q[j + 1].id)) {
                Process temp = q[j];
                q[j] = q[j + 1];
                q[j + 1] = temp;
            }
        }
    }
}


void FCFS(Process q[], int n){
    for(int i=0; i<n; i++)
    {
        if (i == 0) {
            c = q[i].AT + q[i].BT;
        } else if (c >= q[i].AT) {
            c += q[i].BT;
        } else {
            c = q[i].AT + q[i].BT;
        }
        q[i].CT = c;
    }

    for(int i=0; i<n; i++){
        q[i].TAT = q[i].CT - q[i].AT;
        q[i].WT = q[i].TAT - q[i].BT;
    }

    print_process_data(q, n);
}

void input_process(Process q[], int *n)
{
    printf("Enter Number of Processes : \n");
    scanf("%d", n);  // Fix here

    for (int i = 0; i < *n; i++)  // Use *n instead of n
    {
        printf("\nEnter details for Process %d:\n ", (i+1));
        q[i].id = i+1;
        printf("\nEnter the Mode of Process\n");
        scanf("%s", q[i].name);
        printf("\nEnter Process %d arrival time:\n", (i+1));
        scanf("%d", &q[i].AT);
        printf("\nEnter Process %d burst time: \n", (i+1));
        scanf("%d", &q[i].BT);
    }
}


void main()
{
    Process SysQ[MAX], UserQ[MAX];
    int SystemCount, UserCount;
    
    printf("Enter Details for System Processes : \n");
    input_process(SysQ, &SystemCount);
    printf("Enter Details for User Processes : \n");
    input_process(UserQ, &UserCount);

    sorted(SysQ, SystemCount);
    sorted(UserQ, UserCount); // Fix: Sort UserQ instead of repeating SysQ

    printf("Scheduling System Processes : \n");
    FCFS(SysQ, SystemCount);  // Fix: Call FCFS for SysQ

    printf("Scheduling User Processes : \n");
    FCFS(UserQ, UserCount);
}
