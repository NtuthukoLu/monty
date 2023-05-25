#include "monty.h"
FILE *file= NULL;
/**
 * getFunction - finds funtion 
 * @stack: stack to operate on
 * @code: string to find function
 * @l: number of opcode
 * Return: pointer to desired function
 */
void (*getFunction(stack_t **stack, int l, char *code))(stack_t **, unsigned int)
{
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop}
	};
	int i = 0;

	while (strcmp(code, instruction[i].opcode) != 0)
	{
		i++;
		if (i > 7)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", l, code);
			freeStack(stack);
			error();
		}
	}
	return (instruction[i].f);
}
/**
 * pushOp - helper for push operator
 * @stack: linked list stack
 * @line_number: number of bytecode file
 * @pushNum: num to add to the new node
 */
void pushOp(stack_t **stack, unsigned int line_number, char *pushNum)
{
	if (strcmp(pushNum, "0") == 0)
		(*stack)->n = 0;
	if (strcmp(pushNum, "0") != 0)
	{
		(*stack)->n = atoi(pushNum);
		if ((*stack)->n == 0 || (pushNum[0] != '-' && (*stack)->n == -1))
		{
			fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
			freeStack(stack);
			error();
		}
	}
}
/**
 * freeStack - frees a list
 * @stack: stack
 */
void freeStack(stack_t **stack)
{
	if (!(stack) || !(*stack))
	{
		return;
	}
	freeStack(&((*stack)->next));
	free(*stack);
	*stack = NULL;
}

/**
 * error - error handler
 */
void error(void)
{
	fclose(file);
	exit(EXIT_FAILURE);
}
