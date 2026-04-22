/*Problem Statement
Implement a hash table using quadratic probing with formula:*/
#include <stdio.h>

#define EMPTY -1

int main() {
    int m, q;
    
    // Input size of hash table
    printf("Enter size of hash table: ");
    scanf("%d", &m);

    int hash[m];

    // Initialize hash table
    for (int i = 0; i < m; i++) {
        hash[i] = EMPTY;
    }

    // Number of operations
    printf("Enter number of operations: ");
    scanf("%d", &q);

    while (q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        // INSERT operation
        if (op[0] == 'I') {
            int i = 0;
            int index;

            while (i < m) {
                index = (key % m + i * i) % m;

                if (hash[index] == EMPTY) {
                    hash[index] = key;
                    break;
                }
                i++;
            }

            if (i == m) {
                printf("Hash Table Full\n");
            }
        }

        // SEARCH operation
        else if (op[0] == 'S') {
            int i = 0;
            int index;
            int found = 0;

            while (i < m) {
                index = (key % m + i * i) % m;

                if (hash[index] == key) {
                    found = 1;
                    break;
                }

                if (hash[index] == EMPTY) {
                    break;
                }

                i++;
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}