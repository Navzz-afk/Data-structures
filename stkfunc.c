#include <stdio.h>

#include <stdlib.h>

#define SIZE 4

void push();
void pop();
void show();

int main()
{
    int choice,stack[SIZE],top=-1;

    while (1)
    {
        printf("\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(stack,&top);
            break;
        case 2:
            pop(stack,&top);
            break;
        case 3:
            show(stack,&top);
            break;
        case 4:
            exit(0);

        default:
            printf("\nInvalid choice!!");
        }
    }
}

void push(int stack[],int *top)
{
    int x;

    if (*top == SIZE - 1)
    {
        printf("\nOverflow!!");
        return;
    }
    else
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        stack[++(*top)] = x;
    }
}

void pop(int stack[],int * top)
{
    if (*top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nPopped element: %d", stack[(*top)--]);

    }
}

void show(int stack[],int*top)
{
    if (*top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for (int i = *top; i >= 0; --i)
            if(i==(*top))
            printf("%d <--TOP\n",stack[i]);
            else
            printf("%d\n", stack[i]);
    }
}

