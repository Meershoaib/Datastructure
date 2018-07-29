/* C program to check if a tree is height-balanced or not */
#include<stdio.h>
#include<stdlib.h>
#define bool int

struct node
{
    int data;
    struct node* left;
    struct node* right;
};


int height(struct node* node);


bool isBalanced(struct node *root)
{
    int lh;
    int rh;
    
    if(root == NULL)
        return 1;
    
    
    lh = height(root->left);
    rh = height(root->right);
    
    if( abs(lh-rh) <= 1 &&
       isBalanced(root->left) &&
       isBalanced(root->right))
        return 1;
    return 0;
}

int max(int a, int b)
{
    return (a >= b)? a: b;
}


int height(struct node* node)
{
    
    if(node == NULL)
        return 0;
        return 1 + max(height(node->left), height(node->right));
}

struct node* newNode(int data)
{
    struct node* node = (struct node*)
    malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return(node);
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
    
    if(isBalanced(root))
        printf("Tree is balanced");
    else
        printf("Tree is not balanced");
    
    getchar();
    return 0;
}
