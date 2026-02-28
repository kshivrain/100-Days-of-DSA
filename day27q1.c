/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>

// Structure for Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Get length of list
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection point
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            head1 = head1->next;
    } else {
        for (int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    // Traverse together
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int n, m, i, value;

    // Input first list
    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);

    printf("Enter elements of first list: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insertEnd(head1, value);
    }

    // Input second list
    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);

    printf("Enter elements of second list: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = insertEnd(head2, value);
    }

    // OPTIONAL: Manually create intersection for testing
    // Example: Connect last node of list2 to second node of list1
    // Uncomment below lines if you want forced intersection

    /*
    struct Node* temp1 = head1;
    for(i = 1; i < 2; i++)
        temp1 = temp1->next;

    struct Node* temp2 = head2;
    while(temp2->next != NULL)
        temp2 = temp2->next;

    temp2->next = temp1;
    */

    // Find intersection
    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("Intersection Point Value: %d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}