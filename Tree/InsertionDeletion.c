#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct node* insert(struct node* node, int data) {
    if (node == NULL){
        return newNode(data);
    }

    if (data < node->data){
        node->left = insert(node->left, data);
    }
    else if (data > node->data){
        node->right = insert(node->right, data);
    }
    return node;
}

struct node* findMin(struct node* root) {
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

struct node* deletenode(struct node* root, int key) {
    if (root == NULL){
        return root;
    }

    if (key < root->data){
        root->left = deletenode(root->left, key);
    }
    else if (key > root->data){
        root->right = deletenode(root->right, key);
    }
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}


void display(struct node* root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 10);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    root = deletenode(root, 20);

    display(root);

    return 0;
}

//               50
//         30          70
//     20    40     60     80
// 10            
