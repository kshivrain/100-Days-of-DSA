/*Problem: Level Order Traversal*/
#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Queue structure
struct Queue {
    struct TreeNode* arr[100];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

// Check if empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue
void enqueue(struct Queue* q, struct TreeNode* node) {
    if (q->rear == 99) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}

// Dequeue
struct TreeNode* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct TreeNode* temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// Create new node
struct TreeNode* createNode(int data) {
    if (data == -1) return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Queue q;
    initQueue(&q);

    struct TreeNode* root = createNode(arr[0]);
    enqueue(&q, root);

    int i = 1;

    while (!isEmpty(&q) && i < n) {
        struct TreeNode* current = dequeue(&q);

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(&q, current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(&q, current->right);
        }
        i++;
    }

    return root;
}

// Level Order Traversal
void levelOrder(struct TreeNode* root) {
    if (root == NULL) return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        struct TreeNode* temp = dequeue(&q);
        printf("%d ", temp->data);

        if (temp->left != NULL)
            enqueue(&q, temp->left);

        if (temp->right != NULL)
            enqueue(&q, temp->right);
    }
}

// Main function
int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level order elements (-1 for NULL):\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    printf("Level Order Traversal:\n");
    levelOrder(root);

    return 0;
}