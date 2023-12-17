#include "monty.h"

/**
 * mul - multiplies the second top element with the top element
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void mul(stack_t **stack, unsigned int line_number)
{
    int result;
    if (stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, "mul");
        exit(EXIT_FAILURE);
    }

    result = (*stack)->next->n * (*stack)->n;
    pop(stack, line_number);
    (*stack)->n = result;
}
