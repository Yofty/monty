#include "monty.h"
/**
 * get_op_func - select the correct operation
 * @s : operator argument
 * Return: function pointer
 */
void(*get_op_func(char *s))(stack_t**, unsigned int)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{NULL, NULL},
	};
	int i = 0;

	while (ops[i].opcode != NULL && strcmp((ops[i].opcode), s))
		i++;
	return (ops[i].f);
}
