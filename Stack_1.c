// push.c
#include "monty.h"

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
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

// pall.c


void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

// pint.c


void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack)
        printf("%d\n", (*stack)->n);
    else
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
}

// pop.c


void pop(stack_t **stack, unsigned int line_number)
{
    if (*stack)
    {
        stack_t *temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
    else
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
}

// swap.c


void swap(stack_t **stack, unsigned int line_number)
{
    if (*stack && (*stack)->next)
    {
        int temp = (*stack)->n;
        (*stack)->n = (*stack)->next->n;
        (*stack)->next->n = temp;
    }
    else
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
}

// add.c


void add(stack_t **stack, unsigned int line_number)
{
    if (*stack && (*stack)->next)
    {
        (*stack)->next->n += (*stack)->n;
        pop(stack, line_number);
    }
    else
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
}

// nop.c


void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack; // Avoid unused variable warning
    (void)line_number; // Avoid unused variable warning
    // Do nothing
}
