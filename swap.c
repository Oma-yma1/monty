#include "monty.h"
/**
 * swap - Swaps the top two
 * @stack: Pointer to the
 * credit: Omayma & Taha
 * @line_number: Line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tep;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tep = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tep;
}
