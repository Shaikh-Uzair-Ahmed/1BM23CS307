/**
 * A program to implement
 * proportional scheduling
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>

 struct Process {
	int PID;
	int bt;
	int ival;
	int rem_bt;
	int next_release;
	int deadline;
	int weight;
	bool rtr;
};

struct Process *get_processes(int *n) {
	printf("Enter the number of processes : ");
	scanf("%d", n);

	struct Process *arr = calloc(*n, sizeof(struct Process));
	printf("Enter the burst time and intervals : \n");
	
	for(int i = 0; i < *n; i++) {
		arr[i].PID = i + 1;
		printf("PID %d : ", i + 1);
		scanf("%d %d", &arr[i].bt, &arr[i].ival);
		arr[i].rtr = true;
	}

	return arr;
}

 
 void proportional_scheduler(struct Process *arr, int n, int tq) {
     int total_weight = 0;
 
     for (int i = 0; i < n; i++) {
         arr[i].weight = rand() % 100;
         // if (arr[i].weight <= 0) {
         // 	printf("Error: Task PID %d has non-positive weight (%d)\n", arr[i].PID, arr[i].weight);
         // 	return;
         // }
         total_weight += arr[i].weight;
         arr[i].rem_bt = arr[i].bt;
         arr[i].rtr = false;
     }
 
     if (total_weight == 0 || tq <= 0) {
         printf("Error: Invalid total weight (%d) or time quantum (%d)\n", total_weight, tq);
         return;
     }
 
     bool all_rtr = false;
     int time = 0;
 
     while (!all_rtr) {
         all_rtr = true;
 
         for (int i = 0; i < n; i++) {
             if (arr[i].rtr)
                 continue;
 
             all_rtr = false;
 
             int slice = (arr[i].weight * tq) / total_weight;
 
             // Ensure it gets at least 1 unit if needed
             if (slice == 0 && arr[i].rem_bt > 0)
                 slice = 1;
 
             int actual_time = (arr[i].rem_bt < slice) ? arr[i].rem_bt : slice;
 
             printf("PID %d runs from %d to %d\n", arr[i].PID, time, time + actual_time);
 
             arr[i].rem_bt -= actual_time;
             time += actual_time;
 
             if (arr[i].rem_bt == 0)
                 arr[i].rtr = true;
         }
     }
 }
 
 
 int main() {
     int n, tq;
     struct Process *arr = get_processes(&n);
     printf("Enter the time quantum : ");
     scanf("%d", &tq);
     putchar('\n');
     proportional_scheduler(arr, n, tq);
 
     free(arr);
     return 0;
 }