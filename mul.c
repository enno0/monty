#include "monty.h"

/**
 * mul - multiplies the second top element by the top element
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void mul(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n *= (*stack)->n;
    pop(stack, line_number);
}
