#include "monty.h"
/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%d: can't %s, stack empty\n", line_number, "pchar");
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n < 0 || (*stack)->n > 127)
    {
        fprintf(stderr, "L%d: can't %s, value out of range\n", line_number, "pchar");
        exit(EXIT_FAILURE);
    }

    printf("%c\n", (*stack)->n);
    pop(stack, line_number);
}
