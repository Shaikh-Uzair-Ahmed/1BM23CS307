#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    int value;
    printf("Enter value:");
    scanf("%d",&value);
    node->data=value;
    node->left=node->right=NULL;
    return node;
}

void insert(struct Node* root,struct Node* temp){
    if(temp->data<root->data){
        if(root->left!=NULL){
            insert(root->left,temp);
        }
        else{
            root->left=temp;
        }
    }

    if(temp->data>root->data){
        if(root->right!=NULL){
            insert(root->right,temp);
        }
        else{
            root->right=temp;
        }
    }
}

void preorder(struct Node* root){
    if(root!=NULL){
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

void postorder(struct Node* root){
    if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
    }
}

void inorder(struct Node* root){
    if(root!=NULL){
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
    }
}

int main(){
    char ch;
    struct Node* root=NULL;

    do{
        struct Node*temp=createNode();
        if(root==NULL){
            root=temp;
        }
        else{
            insert(root,temp);
        }
        printf("Do you want to continue? if Yes the enter Y/y:");
        scanf(" %c",&ch);
    }while(ch=='Y' || ch=='y');

    printf("Preorder traversal:");
    preorder(root);
    printf("\n");
    printf("Inorder traversal:");
    inorder(root);
    printf("\n");
    printf("Postorder traversal:");
    postorder(root);
    printf("\n");
    return 0;
}
