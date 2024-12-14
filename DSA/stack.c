#include <stdio.h>
#include <stdlib.h>

int top = -1; 


int isEmpty(int arr[]) {
    return top == -1;
}

int isFull(int arr[], int limit) {
    return top == limit - 1;
}

int Top(int arr[]) {
    if (isEmpty(arr)) {
        printf("Stack is empty.\n");
        return -1; 
    }
    return arr[top];
}

void Display(int arr[]) {
    if (isEmpty(arr)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void Push(int value, int arr[], int limit) {
    if (isFull(arr, limit)) {
        printf("Stack is full.\n");
    } else {
        top++;
        arr[top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

void Pop(int arr[]) {
    if (isEmpty(arr)) {
        printf("Stack is empty.\n");
    } else {
        printf("Popped %d from the stack.\n", arr[top]);
        top--;
    }
}

int main() {
    int limit;

    printf("Enter the limit of the stack: ");
    scanf("%d", &limit);

    int arr[limit]; 

    while (1) {
        int choice, value;
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                Push(value, arr, limit);
                break;
            case 2:
                Pop(arr);
                break;
            case 3:
                printf("Top element is: %d\n", Top(arr));
                break;
            case 4:
                Display(arr);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}