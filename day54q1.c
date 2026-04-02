/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue for level order
struct Node* queue[MAX];
int front = 0, rear = 0;

// Create new node
struct Node* createNode(int val) {
    if (val == -1)
        return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Enqueue
void enqueue(struct Node* node) {
    queue[rear++] = node;
}

// Dequeue
struct Node* dequeue() {
    return queue[front++];
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct Node* current = dequeue();

        // left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        // right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (!root)
        return;

    struct Node* q[MAX];
    int f = 0, r = 0;

    q[r++] = root;

    int leftToRight = 1;

    while (f < r) {
        int size = r - f;
        int level[MAX];

        // store level nodes
        for (int i = 0; i < size; i++) {
            struct Node* temp = q[f++];
            level[i] = temp->data;

            if (temp->left)
                q[r++] = temp->left;
            if (temp->right)
                q[r++] = temp->right;
        }

        // print level in zigzag
        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", level[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
    }
}

// Main function
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level order (-1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    printf("Zigzag Traversal: ");
    zigzagTraversal(root);

    return 0;
}