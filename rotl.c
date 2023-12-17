#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (*stack != NULL && (*stack)->next != NULL)
    {
        stack_t *first = *stack;
        stack_t *second = (*stack)->next;
        stack_t *last = *stack;

        while (last->next != NULL)
            last = last->next;

        *stack = second;
        second->prev = NULL;
        last->next = first;
        first->prev = last;
        first->next = NULL;
    }
}
