#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}


void insertFront(Node** head, Node** tail, int data) {
    Node* temp = createNode(data);
    if (*head == NULL) {
        *head = *tail = temp; 
    } else {
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
    }
}


void insertEnd(Node** head, Node** tail, int data) {
    Node* temp = createNode(data);
    if (*tail == NULL) {
        *head = *tail = temp; 
    } else {
        (*tail)->next = temp;
        temp->prev = *tail;
        *tail = temp;
    }
}


void insertAtPos(Node** head, Node** tail, int data, int pos) {
    Node* temp = createNode(data);
    
    
    if (pos == 1) {
        insertFront(head, tail, data);
        return;
    }

    Node* ptr = *head;
    int count = 1;
    while (ptr != NULL && count < pos - 1) {
        ptr = ptr->next;
        count++;
    }

    if (ptr == NULL) {
        printf("Position out of range.\n");
    } else {
        temp->next = ptr->next;
        temp->prev = ptr;
        
        if (ptr->next != NULL) {
            ptr->next->prev = temp;
        } else {
            *tail = temp; 
        }
        ptr->next = temp;
    }
}


void printList(Node* head) {
    Node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int choice, data, pos;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(&head, &tail, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertEnd(&head, &tail, data);
                break;
            case 3:
                printf("Enter position and data: ");
                scanf("%d %d", &pos, &data);
                insertAtPos(&head, &tail, data, pos);
                break;
            case 4:
                printf("List: ");
                printList(head);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}