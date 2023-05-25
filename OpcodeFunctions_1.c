#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line of the bytecode file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp->next || !temp)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		freeStack(stack);
		error();
	}

	temp->next->n += temp->n;
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}
/**
 * nop - doesn't do anything
 * @stack: pointer to the top of the stack
 * @line_number: line of the bytecode file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

