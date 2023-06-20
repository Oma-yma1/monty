#include "monty.h"
/**
 * pop - pop function
 * @stack: stack arg
 * @line_number: line number
 * credit: Taha & Omayma
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tep;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tep = *stack;
	*stack = (*stack)->next;
	free(tep);
}
