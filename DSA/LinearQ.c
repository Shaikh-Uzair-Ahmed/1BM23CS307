#include <stdio.h>
#include <stdlib.h>

#define QUE_SIZE 5

int item, front = 0, rear = -1, q[QUE_SIZE];

void insertrear(int item, int *rear, int q[]) {
    if (*rear == QUE_SIZE - 1) {
        printf("Queue Overflow \n");
        return;
    }
    *rear = *rear + 1;
    q[*rear] = item;
}

int deletefront(int *front, int *rear, int q[]) {
    if (*front > *rear) {
        return -1; 
    }
    return q[(*front)++]; 
}

void displayQ(int front, int rear, int q[]) {
    if (front > rear) {
        printf("Queue is empty \n");
        return;
    }
    printf("Contents of Queue:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d \n", q[i]);
    }
}

int main() {
    int choice;
    for (;;) {
        printf("\n1: Insert rear\n2: Delete front\n3: Display\n4: Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                insertrear(item, &rear, q);
                break;
            case 2:
                item = deletefront(&front, &rear, q);
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