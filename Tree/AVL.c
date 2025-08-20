#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int max(int a, int b){
    return a>b ? a: b;
}

int getHeight(struct Node* node){
    if(node == NULL){
        return 0;
    }
    return node->height;
}

struct Node* createNode(int key){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = key;
    new->left = NULL;
    new->right = NULL;
    new->height = 1;
    return new;
}

int getBalanceFactor(struct Node* node){
    if(node == NULL){
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

struct Node* right_rotate(struct Node* node){
    struct Node* x = node->left;
    struct Node* T2 = node->right;

    x->right = node;
    node->left = T2;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    x->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    return x;
}

struct Node* left_rotate(struct Node* node){
    struct Node* x = node->right;
    struct Node* T2 = x->left;

    x->left = node;
    node->right = T2;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    x->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    return x;
}

struct Node* insert(struct Node* node, int key){
    if(node == NULL){
        return createNode(key);
    }

    if(key < node->data){
        node->left = insert(node->left, key);
    }
    else if(key > node->data){
        node->right = insert(node->right, key);
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    // Left Left case
    if(bf>1 && key < node->left->data){
        return right_rotate(node);
    }

    // Right Right case
    if(bf<-1 && key > node->right->data){
        return left_rotate(node);
    }

    // Left Right case
    if(bf>1 && key > node->left->data){
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    // Right left case
    if(bf<-1 && key < node->right->data){
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    return node;
}

void traverse(struct Node* root){
    if(root != NULL){
        printf("%d \t", root->data);
        traverse(root->left);
        traverse(root->right);
    }
}

int main(){
    struct Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);

    traverse(root);
    return 0;
}