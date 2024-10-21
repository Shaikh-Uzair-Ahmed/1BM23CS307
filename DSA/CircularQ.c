#include <stdio.h>
#include <stdlib.h>

#define N 5

int q[N];

void Enqueue(int item, int *rear,int *front , int q[]) {
    if (((*rear+1)%N) == *front) {
        printf("Queue Overflow \n");
        return;
    }
    if (*front == -1)
    {
        *front = 0;
    }
    
    *rear = ((*rear + 1)%N);
    q[*rear] = item;
}

int Deque(int *front, int *rear, int q[]) {
    if (*front == -1 && *rear == -1) {
        return -1; 
    }
    int temp = q[*front];
    if(*front == *rear){
        *rear = -1;
        *front = -1;
    }
    else{
        *front = ((*front+1)%N);
    }
    return temp; 
}

void displayQ(int front, int rear, int q[]) {
    if (front == -1 &&  rear == -1) {
        printf("Queue is empty \n");
        return;
    }
    printf("Contents of Queue:\n");
    for (int i = front; i != rear; i=(i+1)%N) {
        printf("%d \n", q[i]);
    }
    printf("%d",q[rear]);
}

int main() {
    int choice;
    int rear = -1;
    int front = -1;
    int item;
    for (;;) {
        printf("\n1: Enque\n2: Deque\n3: Display\n4: Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                Enqueue(item, &rear, &front , q);
                break;
            case 2:
                item = Deque(&front, &rear, q);
                if (item == -1)
                    printf("Queue is empty\n");
                else
                    printf("Item deleted = %d \n", item);
                break;
            case 3:
                displayQ(front, rear, q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}