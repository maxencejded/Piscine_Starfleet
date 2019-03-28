#include "header.h"

#define NULL (void *)0

static void				splitMiddle(struct s_stone *head, struct s_stone **a, struct s_stone **b)
{
	struct s_stone	*middle;
	struct s_stone	*end;

	middle = head;
	end = middle->next;
	while (end)
	{
		end = end->next;
		if (end)
		{
			end = end->next;
			middle = middle->next;
		}
	}
	*a = head;
	*b = middle->next;
	middle->next = NULL;
}

static struct s_stone	*mergeSplit(struct s_stone *a, struct s_stone *b)
{
	struct s_stone	*merge;

	merge = NULL;
	if (!a)
		return (b);
	else if (!b)
		return (a);
	else if (a->size <= b->size)
	{
		merge = a;
		merge->next = mergeSplit(a->next, b);
	}
	else
	{
		merge = b;
		merge->next = mergeSplit(a, b->next);
	}
	return (merge);
}

void					sortStones(struct s_stone **stone)
{
	struct s_stone	*head;
	struct s_stone	*a;
	struct s_stone	*b;

	head = *stone;
	if (!head || !head->next)
		return ;
	splitMiddle(head, &a, &b);
	sortStones(&a);
	sortStones(&b);
	*stone = mergeSplit(a, b);
}
