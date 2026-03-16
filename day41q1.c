/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue operation
void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

// Dequeue operation
int dequeue() {
    if (front == NULL) {
        return -1;
    }

    struct Node* temp = front;
    int value = temp->data;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return value;
}

int main() {
    int N;
    printf("Enter number of operations: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int op, value;

        printf("Enter operation (1 for enqueue, 2 for dequeue): ");
        scanf("%d", &op);

        if (op == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
        }
        else if (op == 2) {
            int result = dequeue();
            printf("%d\n", result);
        }
    }

    return 0;
}