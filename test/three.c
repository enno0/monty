#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack)
{
    stack->top = -1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack overflow!\n");
        return;
    }

    stack->items[++stack->top] = value;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }

    return stack->items[stack->top--];
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        exit(EXIT_FAILURE);
    }

    return stack->items[stack->top];
}

int main()
{
    Stack myStack;
    initialize(&myStack);

    push(&myStack, 100);
    push(&myStack, 200);
    push(&myStack, 300);

    printf("Top element: %d\n", peek(&myStack));
    printf("Popped element: %d\n", pop(&myStack));
    printf("Top element after pop: %d\n", peek(&myStack));

    return 0;
}
