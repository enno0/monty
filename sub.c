#include "monty.h"

/**
 * sub - subtracts the top element from the second top element
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void sub(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n -= (*stack)->n;
    pop(stack, line_number);
}
