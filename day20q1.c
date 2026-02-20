/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.*/
#include <stdio.h>

int main() {
    int n;

    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;

    // Check all subarrays
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == 0) {
                count++;
            }
        }
    }

    // Output result
    printf("Number of subarrays with sum zero: %d\n", count);

    return 0;
}