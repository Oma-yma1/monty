#define _GNU_SOURCE
#include "monty.h"
static instruction_t opcod[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{"add", add},
{"nop", nop},
{NULL, NULL}
};
void prs_fl(char *flnm);
instruction_t *gt_instru(char *opcode);
void exe_instru(instruction_t *instr, stack_t **stack,
unsigned int line_number);
/**
* main - main function
* @argc: number of argument
* @argv: argument
* Credit: Omayma & Taha
* Return: 0 always
*/
int main(int argc, char **argv)
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
prs_fl(argv[1]);
return (0);
}
/**
* prs_fl - parse monty bytecodes
* @flnm: file name
* Credit: OMAYMA & TAHA
* Return: void
*/
void prs_fl(char *flnm)
{
FILE *to;
char *bvff = NULL, *opcode = NULL;
size_t bvfsz = 0;
size_t ln_sz = 0;
unsigned int line_number = 1;
stack_t *stack = NULL;
to = fopen(flnm, "r");
if (!to)
{
fprintf(stderr, "Error: Can't open file %s\n", flnm);
exit(EXIT_FAILURE);
}
while ((ln_sz = getline(&bvff, &bvfsz, to)) != (size_t)-1)
{
opcode = strtok(bvff, " \t\n");
if (!opcode || opcode[0] == '#')
{
line_number++;
continue;
}
if (!stack && strcmp(opcode, "push") != 0)
{
fprintf(stderr, "L%u: can't %s, stack empty\n", line_number, opcode);
fclose(to);
free(bvff);
exit(EXIT_FAILURE);
}
exe_instru(gt_instru(opcode), &stack, line_number);
line_number++;
}
free(bvff);
fclose(to);
}
/**
* gt_instru - search instruction
* @opcode: opcode
* Credit: omayma & taha
* Return: instruction_t
*/
instruction_t *gt_instru(char *opcode)
{
size_t n;
for (n = 0; opcod[n].opcode; n++)
{
if (strcmp(opcode, opcod[n].opcode) == 0)
{
return (&opcod[n]);
}
}
return (NULL);
}
/**
* exe_instru - execution of instruction
* @instr: instruction_t
* @stack: stack
* @line_number: line number
* Credit: omayma & taha
* Return: void
*/
void exe_instru(instruction_t *instr, stack_t **stack,
unsigned int line_number)
{
if (!instr)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, instr->opcode);
exit(EXIT_FAILURE);
}
instr->f(stack, line_number);
}
