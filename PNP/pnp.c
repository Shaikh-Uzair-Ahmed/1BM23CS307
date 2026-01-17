#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id, AT, BT, TAT, WT, CT, P; 
};

void sorted(struct Process p[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) { 
            if (p[j].AT > p[j + 1].AT || (p[j].AT == p[j + 1].AT && p[j].id > p[j + 1].id)) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void print_process_data(struct Process p[], int n) {
    printf("PID\tAT\tBT\tP\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].AT, p[i].BT, p[i].P, p[i].CT, p[i].TAT, p[i].WT);
    }

    int ttat = 0, twt = 0;
    for (int i = 0; i < n; i++) {
        ttat += p[i].TAT;
        twt += p[i].WT;
    }

    double avg_tat = (double)ttat / n;
    double avg_wt = (double)twt / n;

    printf("Average Turn-around time: %lf\n", avg_tat);
    printf("Average Waiting time: %lf\n", avg_wt);
}

void PNP(struct Process p[], int n) {
    int time = 0, completed = 0;
    int selected[n]; 

    
    for (int i = 0; i < n; i++) {
        selected[i] = 0; 
    }

    while (completed < n) {
        int minPindex = -1;
        int minP = 9999; 

        
        for (int i = 0; i < n; i++) {
            if (p[i].AT <= time && selected[i] == 0) { 
                if (p[i].P < minP || (p[i].P == minP && p[i].AT < p[minPindex].AT)) {
                    minP = p[i].P;
                    minPindex = i;
                }
            }
        }

        
        if (minPindex != -1) {
            
            time += p[minPindex].BT;  
            p[minPindex].CT = time;   
            p[minPindex].TAT = p[minPindex].CT - p[minPindex].AT; 
            p[minPindex].WT = p[minPindex].TAT - p[minPindex].BT; 
            selected[minPindex] = 1;  
            completed++;  
        } else {
            time++;
        }
    }
}

int main() {
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    struct Process p[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter Process %d Arrival Time (AT), Burst Time (BT), and Priority (P): ", i + 1);
        p[i].id = i + 1; 
        scanf("%d %d %d", &p[i].AT, &p[i].BT, &p[i].P);
    }

    sorted(p, n);  
    PNP(p, n);  
    print_process_data(p, n);  

    return 0;
}