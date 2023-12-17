#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    char buffer[1024];
    int index = 0;

    (void)line_number;

    if (current->n >= 0 && current->n <= 127)
    {
        while (current != NULL && current->n != 0)
        {

            if (index < (int)(sizeof(buffer) - 1))

            {
                buffer[index++] = current->n;
            }
            else
            {
                fprintf(stderr, "L%d: can't pstr, string too long\n", line_number);
                exit(EXIT_FAILURE);
            }

            current = current->next;
        }

        buffer[index] = '\0';

        printf("%s\n", buffer);
    }
    else
    {
        fprintf(stderr, "L%d: can't pstr, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }
}
