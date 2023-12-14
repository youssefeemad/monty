#ifndef MONTY_H
#define MONTY_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @next: points to the next element of the stack (or queue)
 * @prev: points to the previous element of the stack (or queue)
 */
typedef struct stack_s
{
	int n;
	struct stack_s *next;
	struct stack_s *prev;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);

} instruction_t;

/* Global variables */
extern stack_t *head;

/* Prototypes */
void open_file(char *file_name);
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln);
void print_stack(stack_t **stack, unsigned int line_number);
void pop_top(stack_t **stack, unsigned int line_number);
void swap_top(stack_t **stack, unsigned int line_number);
void add_top(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif