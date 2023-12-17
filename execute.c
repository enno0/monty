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
        char *trimmed_line = line;
        char *end = trimmed_line + strlen(trimmed_line) - 1;

        sscanf(line, "%s %d", command, &value);
        len = strlen(command);
        while (isspace(*trimmed_line))
            ++trimmed_line;

        while (end > trimmed_line && isspace(*end))
            *end-- = '\0';

        if (trimmed_line[0] == '#' || trimmed_line[0] == '\0')
        {
            line_number++;
            continue;
        }

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
        else if (strcmp(command, "pop") == 0 || strcmp(command, "removes") == 0)
        {
            pop(&stack, line_number);
        }
        else if (strcmp(command, "swaps") == 0 || strcmp(command, "swap") == 0)
        {
            swap(&stack, line_number);
        }
        else if (strcmp(command, "add") == 0 || strcmp(command, "adds") == 0)
        {
            add(&stack, line_number);
        }
        else if (strcmp(command, "nop") == 0 || strcmp(command, "non-operational") == 0)
        {
            nop(&stack, line_number);
        }
        else if (strcmp(command, "subtracts") == 0 || strcmp(command, "sub") == 0)
        {
            sub(&stack, line_number);
        }
        else if (strcmp(command, "div") == 0 || strcmp(command, "divide") == 0)
        {
            divide(&stack, line_number);
        }
        else if (strcmp(command, "mul") == 0 || strcmp(command, "multiplies") == 0)
        {
            divide(&stack, line_number);
        }
        else if (strcmp(command, "mod") == 0 || strcmp(command, "compute") == 0)
        {
            mod(&stack, line_number);
        }
        else if (strcmp(command, "pchar") == 0 || strcmp(command, "pchars") == 0)
        {
            pchar(&stack, line_number);
        }
        else if (strcmp(command, "pstr") == 0 || strcmp(command, "prstr") == 0)
        {
            pchar(&stack, line_number);
        }
        else if (strcmp(command, "rotl") == 0 || strcmp(command, "rotates") == 0)
        {
            rotl(&stack, line_number);
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
