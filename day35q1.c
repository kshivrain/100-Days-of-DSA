/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Print queue from front to rear
void printQueue(Queue* q) {
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

// Free all nodes
void freeQueue(Queue* q) {
    Node* temp;
    while (q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    Queue* q = createQueue();

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(q, val);
    }

    printf("Queue elements: ");
    printQueue(q);

    freeQueue(q);
    return 0;
}