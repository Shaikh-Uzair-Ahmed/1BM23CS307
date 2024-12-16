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


struct Node* push(struct Node*top,int x)
{
    struct Node* newnode = CreateNode(x);
    newnode->next = top;
    top = newnode;
    return newnode;
}

struct Node* pop(struct Node* top)
{
    struct Node* temp;
    temp = top;
    top = top->next;
    free(temp);
    return top;

}

void display(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void main()
{
    struct Node* top = (struct Node*)malloc(sizeof(struct Node));
    top = NULL;
    int choice,item;
    for(;;)
    {
        printf("\n1:push \n2:pop \n3:Display \n4:exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Ënter Item to be Pushed in Stack \n");
            scanf("%d",&item);
            top = push(top,item);
            break;
        case 2:
            if (top == NULL)
            {
                printf("Stack is Empty");
            }
            else
            {
                top =pop(top);
            }
            break;
        case 3:
            display(top);
            break;
        case 4:
            exit(0);
        default:
        printf("Try again invalid input \n");
        break;
        }
    }
}