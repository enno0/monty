#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void)line_number;

    while (current != NULL && current->n > 0 && current->n < 128)
    {
        printf("%c", (char)current->n);
        current = current->next;
    }

    printf("\n");
}
