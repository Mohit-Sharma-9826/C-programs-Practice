#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* left;
    int data;
    struct node* right;
};

void display(struct node* root) {
    if (root == NULL){
        return;
    }
    display(root->left);        
    printf("%d ", root->data);  
    display(root->right);       
}

struct node* insert(struct node* root, struct node* new){
    if(new->data < root->data){
        if(root->left == NULL){
            root->left = new;
        }
        else{
            insert(root->left, new);
        }
    }
    else{
        if(root->right == NULL){
            root->right = new;
        }
        else{
            insert(root->right, new);
        }
    }
    return root;
}

struct node* create(struct node* root, int info){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = info;
    new->left = NULL;
    new->right = NULL;
    if(root == NULL){
        root = new;
    }
    else{
        root = insert(root, new);
    }
    return root;
}
 
void main(){
    struct node* root = NULL;
    root = create(root, 50);
    create(root, 40);
    create(root, 60);
    create(root, 45);
    create(root, 49);

    display(root);
}
