#include "monty.h"

/**
 * initialize_stack - initializes an empty stack
 * @stack: pointer to the stack
 */
void initialize_stack(stack_t **stack)
{
    *stack = NULL;
}

/**
 * main - entry point for the Monty interpreter
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    const char *filename;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    filename = argv[1];
    execute(filename);

    return 0;
}
