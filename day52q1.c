/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.*/
#include <stdio.h>
#include <stdlib.h>

// Tree Node structure
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for level order construction
struct Queue {
    struct TreeNode* data[1000];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    if (q->rear == 999) return;
    if (q->front == -1) q->front = 0;
    q->data[++q->rear] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == -1) return NULL;
    struct TreeNode* temp = q->data[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return temp;
}

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Queue q;
    initQueue(&q);

    struct TreeNode* root = newNode(arr[0]);
    enqueue(&q, root);

    int i = 1;

    while (i < n) {
        struct TreeNode* curr = dequeue(&q);

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

// LCA function
struct TreeNode* LCA(struct TreeNode* root, int p, int q) {
    if (root == NULL) return NULL;

    if (root->val == p || root->val == q)
        return root;

    struct TreeNode* left = LCA(root->left, p, q);
    struct TreeNode* right = LCA(root->right, p, q);

    if (left && right)
        return root;

    return (left != NULL) ? left : right;
}

// Main function
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level-order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int p, q;
    printf("Enter two node values: ");
    scanf("%d %d", &p, &q);

    struct TreeNode* root = buildTree(arr, n);

    struct TreeNode* result = LCA(root, p, q);

    if (result != NULL)
        printf("LCA: %d\n", result->val);
    else
        printf("LCA not found\n");

    return 0;
}