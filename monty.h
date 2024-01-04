#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct global_info_s - structure to store global information for
 * Monty interpreter
 * @monty_file: pointer to the currently open Monty file
 * @current_line: pointer to the currently processed line in the Monty file
 * @stack_head: pointer to the head of the stack
 * @line_number: current line number being processed
 *
 * Description: This structure is used to store global information needed for
 * the Monty interpreter, including the Monty file, current line, stack, and
 * the line number being processed.
 */
typedef struct global_info_s
{
	FILE *monty_file;
	char *current_line;
	stack_t *stack_head;
	unsigned int line_number;
} global_info_t;

extern global_info_t global_info;

int execute_monty_instruction(char *instruction, stack_t **stack_head,
unsigned int line_number);
void push(stack_t **stack, int n);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
int is_numeric(const char *str);
void cleanup(global_info_t *info);

#endif /* MONTY_H */