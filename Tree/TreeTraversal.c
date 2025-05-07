#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* left;
    int data;
    struct node* right;
};

// Function to create a new node
struct node* newnode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void preorder(struct node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);  // Visit root
    preorder(root->left);       // Traverse left subtree
    preorder(root->right);      // Traverse right subtree
}

void inorder(struct node* root) {
    if (root == NULL)
        return;
    inorder(root->left);        // Traverse left subtree
    printf("%d ", root->data);  // Visit root
    inorder(root->right);       // Traverse right subtree
}

void postorder(struct node* root) {
    if (root == NULL)
        return;
    postorder(root->left);      // Traverse left subtree
    postorder(root->right);     // Traverse right subtree
    printf("%d ", root->data);  // Visit root
}

int main() {
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
 