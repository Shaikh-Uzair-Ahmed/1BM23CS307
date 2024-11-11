#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->link = NULL;
    return newNode;
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

// Function to insert at the end of the list
struct Node* insertEnd(struct Node* head, int n) {
    struct Node* temp = createNode(n);

    if (head == NULL) {
        return temp;  // If the list is empty, the new node becomes the head
    } else {
        struct Node* ptr = head;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = temp;  // Add the new node at the end
    }
    return head;
}

// Function to insert at the front of the list
struct Node* insertFront(struct Node* head, int n) {
    struct Node* temp = createNode(n);
    temp->link = head;  // The new node points to the current head
    return temp;         // Return the new node as the new head of the list
}

// Function to delete the front node
struct Node* deleteFront(struct Node* head) {
    if (head == NULL) {
        printf("The list is already empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->link;   // Move head to the next node
    free(temp);          // Free the old head
    return head;
}

// Function to delete the end node
struct Node* deleteEnd(struct Node* head) {
    if (head == NULL) {
        printf("The list is already empty.\n");
        return NULL;
    }
    if (head->link == NULL) { // Only one node in the list
        free(head);
        return NULL;
    }
    struct Node* ptr = head;
    while (ptr->link->link != NULL) {
        ptr = ptr->link;
    }
    free(ptr->link);      // Free the last node
    ptr->link = NULL;     // Set the second last node's link to NULL
    return head;
}

// Function to delete a node at a specified position
struct Node* deleteAtPosition(struct Node* head, int position) {
    struct Node* ptr = head;
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }
    if (position == 1) { // Delete the first node
        head=head->link;
        free(ptr);
        return head;
    }
    for (int i = 1; i < position - 1 && ptr->link != NULL; i++) {
        ptr = ptr->link;
    }
    if (ptr->link == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }
    struct Node* temp = ptr->link;
    ptr->link = temp->link;
    free(temp);           // Free the node at the specified position
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, val, pos;

    while (1) {
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Delete at Position\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                head = insertFront(head, val);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &val);
                head = insertEnd(head, val);
                break;
            case 3:
                head = deleteFront(head);
                break;
            case 4:
                head = deleteEnd(head);
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                head = deleteAtPosition(head, pos);
                break;
            case 6:
                display(head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
