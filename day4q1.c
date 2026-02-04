/*Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.*/
#include <stdio.h>

int main() {
    int n, i, temp;
    int a[100];
    int start, end;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Two-pointer approach
    start = 0;
    end = n - 1;

    while(start < end) {
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;

        start++;
        end--;
    }

    printf("Reversed array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
