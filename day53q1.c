/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.*/
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue Node (for level order + HD)
struct QNode {
    struct Node* node;
    int hd;
};

// Create new tree node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue implementation
struct QNode queue[1000];
int front = 0, rear = 0;

void enqueue(struct Node* node, int hd) {
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

struct QNode dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* q[1000];
    int f = 0, r = 0;
    q[r++] = root;

    int i = 1;

    while (i < n) {
        struct Node* curr = q[f++];

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[r++] = curr->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[r++] = curr->right;
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    int map[200][200];  // store values
    int count[200] = {0};

    int offset = 100; // to handle negative HD

    enqueue(root, 0);

    while (!isEmpty()) {
        struct QNode temp = dequeue();
        struct Node* curr = temp.node;
        int hd = temp.hd + offset;

        map[hd][count[hd]++] = curr->data;

        if (curr->left)
            enqueue(curr->left, temp.hd - 1);
        if (curr->right)
            enqueue(curr->right, temp.hd + 1);
    }

    // Print result
    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

// Main function
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[1000];
    printf("Enter level order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    printf("Vertical Order Traversal:\n");
    verticalOrder(root);

    return 0;
}