/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.*/
#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

void push_front(int value)
{
    if(front == 0)
        printf("Overflow at front\n");

    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[front] = value;
    }
    else
    {
        front--;
        deque[front] = value;
    }
}

void push_back(int value)
{
    if(rear == MAX-1)
        printf("Overflow at rear\n");

    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[rear] = value;
    }
    else
    {
        rear++;
        deque[rear] = value;
    }
}

void pop_front()
{
    if(front == -1)
        printf("Deque Underflow\n");

    else if(front == rear)
    {
        printf("Deleted element: %d\n", deque[front]);
        front = rear = -1;
    }
    else
    {
        printf("Deleted element: %d\n", deque[front]);
        front++;
    }
}

void pop_back()
{
    if(rear == -1)
        printf("Deque Underflow\n");

    else if(front == rear)
    {
        printf("Deleted element: %d\n", deque[rear]);
        front = rear = -1;
    }
    else
    {
        printf("Deleted element: %d\n", deque[rear]);
        rear--;
    }
}

void display()
{
    if(front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    for(int i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}

void get_front()
{
    if(front == -1)
        printf("Deque empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

void get_back()
{
    if(rear == -1)
        printf("Deque empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

int main()
{
    int choice, value;

    while(1)
    {
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Push Front\n");
        printf("2. Push Back\n");
        printf("3. Pop Front\n");
        printf("4. Pop Back\n");
        printf("5. Front Element\n");
        printf("6. Rear Element\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push_front(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                push_back(value);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                get_front();
                break;

            case 6:
                get_back();
                break;

            case 7:
                display();
                break;

            case 8:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}