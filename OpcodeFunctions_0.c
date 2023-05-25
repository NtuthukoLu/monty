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
		freeStack(stack);
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
/*
 * pint - prints the value at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: number of bytecode file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n",line_number);
		fclose(file);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/*
 * pop - removes the top element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: number of bytecode file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop a empty stack\n", line_number);
		fclose(file);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	*stack = temp->next;

	if (*stack)
	{
		(*stack)->prev = NULL;
		free(temp);
	}
}
/*
 * swap - swaps top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: number of bytecode file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack)->n;

	if ((*stack) == NULL || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
