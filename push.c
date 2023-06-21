#include "monty.h"
/**
* push - push function
* @stack: stack
* @line_number: line number
* Credit: omayma & taha
* Return: void
*/
void push(stack_t **stack, unsigned int line_number)
{
char *arg = NULL;
int n = 0;
if (!stack)
{
fprintf(stderr, "Error: stack is NULL\n");
exit(EXIT_FAILURE);
}
arg = strtok(NULL, " \t\n");
if (!iv_argu(arg))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
n = atoi(arg);
new_nd(stack, n);
}
/**
* new_nd - add new node
* @stack: stack
* @n: integer
* credit: omayma & taha
* Return: void
*/
void new_nd(stack_t **stack, int n)
{
stack_t *nw_nde = malloc(sizeof(stack_t));
if (!nw_nde)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
nw_nde->n = n;
nw_nde->prev = NULL;
nw_nde->next = *stack;
if (*stack)
(*stack)->prev = nw_nde;
*stack = nw_nde;
}
/**
* iv_argu - checking an argument
* @arg: argument
* credit: omayma & taha
* Return: 1 if argument or 0 if failed
*/
int iv_argu(char *arg)
{
if (!arg || (!isdigit(arg[0]) && arg[0] != '-'))
return (0);
return (1);
}
