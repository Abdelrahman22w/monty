#include "monty.h"

/**
 * peek_str - see top str
 * @head: pt
 * @counter: cnt
*/
void peek_str(stack_t **head, unsigned int counter)
{
	stack_t *top = *head;

	(void) counter;
	if (head == NULL || *head == NULL)
	{
		putchar('\n');
		return;
	}

	for (; top != NULL; top = top->next)
	{
		if (top->n > 127 || top->n <= 0)
		{
			putchar((char)top->n);
		}
	}
	putchar('\n');
}
