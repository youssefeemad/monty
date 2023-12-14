/* opcode_pint.c */
#include "monty.h"

void pint(stack_t **stack)
{
    if (!*stack)
    {
        dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
