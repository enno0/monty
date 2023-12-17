#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element by the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void mod(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, "mod");
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n %= (*stack)->n;
    pop(stack, line_number);
}
