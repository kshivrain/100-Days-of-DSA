/*Problem: Given an array of integers, rotate the array to the right by k positions.*/
#include <stdio.h>

int main() {
    int n, k;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d integers: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input k
    printf("Enter number of rotations: ");
    scanf("%d", &k);

    // Handle k greater than n
    k = k % n;

    int temp[n];

    // Rotate array to the right
    for(int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }

    // Output rotated array
    printf("Rotated array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}
