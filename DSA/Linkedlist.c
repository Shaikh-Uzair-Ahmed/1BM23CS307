#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->link = NULL;
    return newNode;
}

void display(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

void insertEnd(struct Node** head, int n) {
    struct Node* temp = createNode(n);
    if (*head == NULL) {
        *head = temp;  // If the list is empty, the new node becomes the head
    } else {
        struct Node* ptr = *head;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = temp;  // Add the new node at the end
    }
}

void insertFront(struct Node** head, int n) {
    struct Node* temp = createNode(n);
    temp->link = *head;
    *head = temp;  // The new node becomes the head of the list
}

int main() {
    struct Node* head = NULL;
    int choice, val;

    while (1) {
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                insertFront(&head, val);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &val);
                insertEnd(&head, val);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}