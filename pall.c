#include "monty.h"
/**
* pall - print values
* @stack: stack
* @line_number: line number
* Credit: omayma & taha
* Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *tep = NULL;
(void)line_number;
if (!stack || !*stack)
{
printf("stack is empty\n");
return;
}
tep = *stack;
while (tep)
{
printf("%d\n", tep->n);
tep = tep->next;
}
}

