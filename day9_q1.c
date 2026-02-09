/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Enter the code name: ");
    scanf("%s", str);   // reads a single word (no spaces)

    int len = strlen(str);

    printf("Mirror format: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    printf("\n");
    return 0;
}
