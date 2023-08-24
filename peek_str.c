#include "monty.h"

/**
 * pstr - see top str
 * @head: pt
 * @counter: cnt
*/
void peek_str(stack_t **head, unsigned int counter)
{
    stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
