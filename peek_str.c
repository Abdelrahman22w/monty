#include "monty.h"

/**
 * peek_str - see top str
 * @head: pt
 * @counter: cnt
*/
void peek_str(stack_t **head, unsigned int counter)
{
	(void) counter;
	stack_t *top = *head;

	if (head == NULL || *head == NULL)
	{
		putchar('\n');
		return;
	}

    for (; top != NULL; top = top->next)
    {
        if (top->n != 0 && isascii(top->n))
        {
            putchar((char)top->n);
        }
    }
    putchar('\n');
}
