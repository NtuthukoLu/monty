#include "monty.h"
/**
 * push - pushes element to the stack
 * @stack: linked list
 * @line-number: number of bytecode file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newN = malloc(sizeof(stack));
	if (newN == NULL)
	{
		fprintf(stderr, "Error: failed\n");
		free_stack(stack);
		err();
	}

	(void)line_number;
	if (*stack)
		(*stack)->prev = newN;

	newN->prev = NULL;
	newN->next = *stack;
	newN->n = 0;
	*stack = newN;

}
/**
 * pall - Prints all the values on the stack
 * @stack: Pointer to the top of the stack
 * @line_number: number of bytecode file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	temp = *stack;
	
	do 
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	while (temp);

	(void)line_number;
}
