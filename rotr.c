#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (*stack != NULL && (*stack)->next != NULL)
    {
        stack_t *last = *stack;

        while (last->next != NULL)
            last = last->next;

        last->prev->next = NULL;
        last->prev = NULL;
        last->next = *stack;
        (*stack)->prev = last;
        *stack = last;
    }
}
