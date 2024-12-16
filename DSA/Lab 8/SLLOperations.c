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

// Function to sort the linked list using bubble sort
void sort(struct Node* head) {
    struct Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Function to reverse the linked list and return the new head
struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *nextn = NULL;
    while (curr != NULL) {
        nextn = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextn;
    }
    return prev;  // Return the new head of the reversed list
}

// Function to concatenate two lists
struct Node* Concat(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;  // If the first list is empty, return the second list

    struct Node* temp1 = head1;
    // Traverse to the last node of the first list
    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }
    // Connect the last node of the first list to the second list
    temp1->next = head2;
    return head1;  // Return the concatenated list's head
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    // Create the first list
    struct Node* head = CreateNode(4);
    head->next = CreateNode(2);
    head->next->next = CreateNode(9);
    head->next->next->next = CreateNode(1);

    // Create the second list
    struct Node* head2 = CreateNode(5);
    head2->next = CreateNode(3);
    head2->next->next = CreateNode(8);

    // Display both lists
    display(head);
    display(head2);

    // Sort the first list and display it
    sort(head);
    display(head);

    // Reverse the second list and display it
    head2 = reverse(head2);  // Update head2 with the reversed list
    display(head2);

    // Concatenate the two lists and display the result
    head = Concat(head, head2);
    display(head);

    return 0;
}