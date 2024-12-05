#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    // Allocate memory for new node
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    // Insert the data
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct Node* insert(struct Node* node, int data) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(data);

    // Otherwise, recur down the tree
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    // return the (unchanged) node pointer
    return node;
}

void display(struct Node* root) {
    if (root != NULL) {
        // Traverse the left subtree
        display(root->left);

        // Visit the root
        printf("%d ", root->data);

        // Traverse the right subtree
        display(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 10);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the given tree: ");
    display(root);

    return 0;
}
