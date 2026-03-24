/*Problem: BST Search*/
#include <stdio.h>
#include <stdlib.h>

// Definition of Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Function to search in BST
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

// Main function
int main() {
    struct TreeNode* root = NULL;
    int n, val, key;

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input elements
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Input value to search
    printf("Enter value to search: ");
    scanf("%d", &key);

    // Search operation
    struct TreeNode* result = searchBST(root, key);

    // Output result
    if (result != NULL)
        printf("Value %d found in BST\n", key);
    else
        printf("Value %d not found in BST\n", key);

    return 0;
}