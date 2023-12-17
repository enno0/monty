#include "monty.h"
/**
 * push - pushes an element onto the stack
 * @stack: pointer to the stack
 * @value: value to push onto the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, int value, unsigned int line_number)
{

    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    else
    {
        new_node->next = NULL;
    }

    if (line_number != 0)
    {
        /* code */
    }

    *stack = new_node;
}