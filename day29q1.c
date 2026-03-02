/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>

// Define structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to rotate the linked list right by k places
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node *current = head;
    int length = 1;

    // Find length of list
    while (current->next != NULL) {
        current = current->next;
        length++;
    }

    // Make it circular
    current->next = head;

    // Reduce k if greater than length
    k = k % length;

    // Find new tail position
    int stepsToNewHead = length - k;
    struct Node* newTail = head;

    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;

    // Break the circle
    newTail->next = NULL;

    return newHead;
}

int main() {
    int n, k, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL;

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter k: ");
    scanf("%d", &k);

    head = rotateRight(head, k);

    // Print rotated list
    printf("Rotated List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}