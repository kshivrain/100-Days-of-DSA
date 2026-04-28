/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.*/
#include <stdio.h>
#include <stdlib.h>

// Function to find longest subarray with sum = 0
int maxLen(int arr[], int n) {
    int sum = 0, max_length = 0;

    // Hash map using array (for simplicity, using large size)
    // You can also use unordered_map in C++ for better handling
    int hash[1000];
    
    // Initialize hash array with -1
    for (int i = 0; i < 1000; i++)
        hash[i] = -1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // If sum is 0, update max_length
        if (sum == 0)
            max_length = i + 1;

        // Handle negative sums by shifting index
        int index = sum + 500; // shift to avoid negative index

        // If sum seen before
        if (hash[index] != -1) {
            int length = i - hash[index];
            if (length > max_length)
                max_length = length;
        } else {
            // Store first occurrence
            hash[index] = i;
        }
    }

    return max_length;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxLen(arr, n);

    printf("Length of longest subarray with sum 0: %d\n", result);

    return 0;
}