/*
Problem: Write a C program to delete the element at a given 1-based position 
pos from an array of n integers. Shift remaining elements to the left.
*/

#include <stdio.h>

int main() {
    int n, pos;
    
    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Read the array elements
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Display original array
    printf("\nOriginal array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Read the position to delete (1-based)
    printf("Enter the position to delete (1 to %d): ", n);
    scanf("%d", &pos);
    
    // Validate position
    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return 1;
    }
    
    printf("\nDeleting element at position %d (value = %d)\n", pos, arr[pos - 1]);
    
    // Shift elements to the left starting from position pos
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Print the updated array with (n-1) elements
    printf("\nUpdated array after deletion: ");
    for (int i = 0; i < n - 1; i++) {
        printf("%d", arr[i]);
        if (i < n - 2) {
            printf(" ");
        }
    }
    printf("\n");
    
    printf("\nArray size reduced from %d to %d\n", n, n - 1);
    
    return 0;
}
