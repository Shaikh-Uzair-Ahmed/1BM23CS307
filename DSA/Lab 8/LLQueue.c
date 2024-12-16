#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* CreateNode(int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

// Enqueue function to insert at the rear of the queue
struct Node* enqueue(struct Node* rear, int x) {
    struct Node* newnode = CreateNode(x);
    if (rear == NULL) {
        return newnode;  // If the queue is empty, new node becomes both front and rear
    }
    rear->next = newnode;  // Attach new node at the rear
    return newnode;        // Return new rear
}

// Dequeue function to remove from the front of the queue
struct Node* dequeue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return NULL;
    }
    struct Node* temp = front;
    front = front->next;  // Move front to the next node
    free(temp);            // Free the old front node
    return front;          // Return new front of the queue
}

// Function to display the queue
void display(struct Node* front) {
    struct Node* ptr = front;
    if (ptr == NULL) {
        printf("Queue is empty\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, item;

    for (;;) {
        printf("\n1: Enqueue\n2: Dequeue\n3: Display Queue\n4: Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter item to be enqueued: ");
            scanf("%d", &item);
            rear = enqueue(rear, item);  // Enqueue operation, rear updated
            if (front == NULL) {
                front = rear;  // If queue was empty, both front and rear will be same
            }
            break;
        case 2:
            front = dequeue(front);  // Dequeue operation, front updated
            if (front == NULL) {
                rear = NULL;  // If the queue is empty, rear will also be NULL
            }
            break;
        case 3:
            display(front);  // Display the current state of the queue
            break;
        case 4:
            exit(0);  // Exit the program
        default:
            printf("Invalid input. Please try again.\n");
            break;
        }
    }
}