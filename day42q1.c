/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.*/
#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

int stack[MAX];
int top = -1;

// Enqueue
void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// Push
void push(int x) {
    if (top == MAX - 1)
        return;
    stack[++top] = x;
}

// Pop
int pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

int main() {
    int n, i, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter queue elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Move queue elements to stack
    while(front <= rear) {
        push(dequeue());
    }

    // Step 2: Move stack elements back to queue
    while(top != -1) {
        enqueue(pop());
    }

    // Print reversed queue
    printf("Reversed Queue: ");
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}