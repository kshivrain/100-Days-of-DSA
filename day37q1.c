/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.*/
#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = 0;

// Insert element in priority queue
void insert(int x)
{
    int i;

    if(size == MAX)
    {
        printf("Priority Queue Overflow\n");
        return;
    }

    // Shift elements to maintain sorted order
    for(i = size - 1; i >= 0 && pq[i] > x; i--)
    {
        pq[i + 1] = pq[i];
    }

    pq[i + 1] = x;
    size++;
}

// Delete highest priority element (smallest value)
void delete()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);

    for(int i = 1; i < size; i++)
    {
        pq[i - 1] = pq[i];
    }

    size--;
}

// Peek highest priority element
void peek()
{
    if(size == 0)
        printf("-1\n");
    else
        printf("%d\n", pq[0]);
}

int main()
{
    int n, x;
    char operation[10];

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter operation (insert x / delete / peek): ");
        scanf("%s", operation);

        if(operation[0] == 'i')  // insert
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(operation[0] == 'd') // delete
        {
            delete();
        }
        else if(operation[0] == 'p') // peek
        {
            peek();
        }
    }

    return 0;
}