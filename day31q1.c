/*Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top--]);
}

// Display operation (Top to Bottom)
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, operation, value;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    printf("Enter operations:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &operation);

        switch (operation) {
            case 1:
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            default:
                printf("Invalid Operation\n");
        }
    }

    return 0;
}