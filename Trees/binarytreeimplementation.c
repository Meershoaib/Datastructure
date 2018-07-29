#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TEST_NUMBER 100

typedef struct node{
    struct node * l, * r;
    int value;
} node;

void in(node * n){
    if(n->l) in(n->l);
    printf("%d ", n->value);
    if(n->r) in(n->r);
}

void pre(node * n){
    printf("%d ", n->value);
    if(n->l) pre(n->l);
    if(n->r) pre(n->r);
}

void post(node * n){
    if(n->l) post(n->l);
    if(n->r) post(n->r);
    printf("%d ", n->value);
}

node * new(int value){
    node * n = malloc(sizeof(node));
    n->value = value;
    n->l = n->r = NULL;
    return n;
}

void insert(node ** root, node * child){
    
    if(!*root) *root = child;
    
    else insert( child->value <= (*root)->value ? &(*root)->l : &(*root)->r , child );
    
}


node * search(node * root, int value){
    return !root ? NULL : root->value == value ? root : search( value > root->value ? root->r : root->l , value );
   
}


void searchByPointer(node * root, int value, node ** save){
    *save = search(root,value);
}

int main(){
    
    int test, c, success;
    test = c = success = 0;
    
    srand(time(NULL));
    
    node * root = NULL;

    
    while(c++ < TEST_NUMBER)
        insert(&root, new(rand() % 150));

    
    printf("\n > IN ORDER -> ");
    in(root);
    
    printf("\n\n > PRE ORDER -> ");
    pre(root);
    
    printf("\n\n > POST ORDER -> ");
    post(root);
    
    puts("\n\n > TEST SEARCH:");
    
    while(test++ < TEST_NUMBER)
        if(search(root, test) > 0){
            printf("  - %d\n", test);
            success++;
        }
    
    printf("\n <SUCCESS> = %d <FAILED> = %d\n", success, TEST_NUMBER - success);
    
}
