/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create new polynomial term
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
struct Node* insertTerm(struct Node* head, int c, int e) {
    struct Node* newNode = createNode(c, e);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print polynomial in standard format
void printPolynomial(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->exp == 0)
            printf("%d", temp->coeff);
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main() {
    int n, coeff, exp;
    struct Node* head = NULL;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent for each term:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        head = insertTerm(head, coeff, exp);
    }

    printf("Polynomial: ");
    printPolynomial(head);

    return 0;
}