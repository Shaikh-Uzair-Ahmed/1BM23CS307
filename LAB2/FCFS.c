#include<stdio.h>

struct FCFS
{   
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void sort(struct FCFS p[], int n){
    int min = p[0].at;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        min=p[i].at;
        for (int j = i; j < n; j++)
        {
            if (p[j].at<min)
            {
                temp = p[i].at;
                p[i].at = p[j].at;
                p[j].at = temp;
                temp = p[j].bt;
                p[j].bt = p[i].bt;
                p[i].bt = temp;
                temp = p[i].pid;
                p[i].pid = p[j].pid;
                p[j].pid = temp;
            }
            
        }
        
    }
    
}


int main(){
    int n,c=0;
    double avg_tat=0.0,ttat=0.0,avg_wt=0.0,twt=0.0;
    printf("Enter Number of Process :");
    scanf("%d",&n);
    struct FCFS p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter details for Process %d:\n ",(i+1));
        p[i].pid = (i+1);
        printf("Enter Process %d arrival time: \n",(i+1));
        scanf("%d",&p[i].at);
        printf("Enter Process %d burst time: \n",(i+1));
        scanf("%d",&p[i].bt);
    }

    sort(p,n);
    for(int i=0;i<n;i++)
    {
        if(c>=p[i].at){
            c+=p[i].bt;
        }else
        {
            c+= p[i].at-p[i-1].ct+p[i].bt;
        }
        p[i].ct = c;
    }

    for(int i=0;i<n;i++){
        p[i].tat= p[i].ct-p[i].at;
    }
    for(int i=0;i<n;i++){
        p[i].wt= p[i].tat-p[i].bt;
    }
    

    printf("FCFS Sheduling: \n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    for (int i = 0; i < n; i++){
        ttat+=p[i].tat;
        twt+=p[i].wt;
    }

    avg_tat = ttat/(double)n;
    avg_wt = twt/(double)n;
    printf("Average Turn Around Time :%lf",avg_tat);
    printf("Average Waiting Time :%lf",avg_wt);


}