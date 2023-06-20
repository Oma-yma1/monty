#include "monty.h"
/**
 * add - add func
 * @stack: stack t zd
 * @line_number: lone nulmberr
 * credit: Omayma & Taha
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
