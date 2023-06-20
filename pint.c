#include "monty.h"
/**
 * pint - pint function
 * @stack: stack arg
 * @line_number: line number
 * credited: Taha & Omayma
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprint(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
