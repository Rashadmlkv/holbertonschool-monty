#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>


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
 * struct globvar - decleration
 * @buffer: string buffer for getline
 * @token: string buffer for strok
 * @fd: file descriptor
 * @f: function pointer for checkop
 * @top: stack
 */
typedef struct globvar
{
	char *buffer, *token;
	FILE *fd;
	void (*f)(stack_t **stack, unsigned int line_number);
	stack_t *top;
} global;
extern global glob;
global glob;


void checkFile(int ac, char **av);
int checkLine(void);
int isDigit(char *number);
void freeStack(void);
void (*checkOp(char *str, unsigned int line_number))(stack_t **, unsigned int);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

#endif
