/*Problem: Create and Traverse Singly Linked List*/
#include <stdio.h>
#include <stdlib.h>

// Define structure for Node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Prompt and read number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list
    for(int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }

        temp = newNode;
    }

    // Traverse and print the linked list
    printf("Linked list elements are: ");
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}