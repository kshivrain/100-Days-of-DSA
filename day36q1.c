/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;

    if (front == NULL) {
        front = rear = temp;
        rear->next = front;
    } 
    else {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    if (front == rear) {
        struct Node* temp = front;
        front = rear = NULL;
        free(temp);
    } 
    else {
        struct Node* temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

// Display queue
void display() {
    if (front == NULL) {
        printf("Queue is empty");
        return;
    }

    struct Node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
}

int main() {
    int n, m, x;

    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    printf("Enter number of dequeue operations: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    printf("Queue elements from front to rear: ");
    display();

    return 0;
}