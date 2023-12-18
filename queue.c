#include "monty.h"

/**
 * _stack - sets the format of the data to a stack (LIFO)
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void _stack(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    (void)stack;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void queue(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void)line_number;

    if (current != NULL && current->next != NULL)
    {
        while (current->next != NULL)
            current = current->next;

        if (current != *stack)
        {
            current->next = *stack;
            (*stack)->prev = current;
            *stack = (*stack)->next;
            (*stack)->prev->next = NULL;
            (*stack)->prev = NULL;
        }
    }
}