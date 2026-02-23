/*Problem: Count Nodes in Linked List*/
#include <stdio.h>
#include <stdlib.h>

// Define structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int count = 0;

    // Read number of nodes
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // If n is 0
    if(n <= 0) {
        printf("Count of nodes: 0\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);

    // Create linked list
    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Count nodes
    temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Print count
    printf("Count of nodes: %d\n", count);

    return 0;
}