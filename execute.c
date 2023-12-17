#include "monty.h"

/**
 * execute - reads Monty ByteCode from a file and executes it
 * @filename: name of the Monty ByteCode file
 */
void execute(const char *filename)
{
    stack_t *stack = NULL;
    char line[256];
    int line_number = 1;

    FILE *file = fopen(filename, "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        int value;
        char command[10];
        int len;

        sscanf(line, "%s %d", command, &value);
        len = strlen(command);

        if (len > 0 && command[len - 1] == '$')
        {
            command[len - 1] = '\0';
        }

        if (strcmp(command, "push") == 0)
        {
            push(&stack, value, line_number);
        }
        else if (strcmp(command, "pall") == 0)
        {
            pall(&stack, line_number);
        }
        else if (strcmp(command, "pop") == 0)
        {
            pop(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
            fclose(file);
            free_stack(&stack);
            exit(EXIT_FAILURE);
        }

        line_number++;
    }

    fclose(file);
    free_stack(&stack);
}
