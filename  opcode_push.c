/* opcode_push.c */
#include "monty.h"

void push(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        dprintf(STDERR_FILENO, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack)
        (*stack)->prev = new_node;

    new_node->next = *stack;
    *stack = new_node;
}

/* opcode_pall.c */
#include "monty.h"

void pall(stack_t **stack)
{
    stack_t *current = *stack;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
