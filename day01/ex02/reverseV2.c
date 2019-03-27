#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_stack			*stackInit(void)
{
	struct s_stack	*stack;

	if (!(stack = (struct s_stack *)malloc(sizeof(struct s_stack))))
		return (NULL);
	stack->item = NULL;
	return (stack);
}

static struct s_item	*itemInit(char *word)
{
	struct s_item	*items;

	if (!(items = (struct s_item *)malloc(sizeof(struct s_item))))
		return (NULL);
	items->word = word;
	items->next = NULL;
	return (items);
}

void					push(struct s_stack *stack, char *word)
{
	struct s_item	*new;

	if (!stack || !(new = itemInit(word)))
		return ;
	new->next = stack->item;
	stack->item = new;
}

void					*pop(struct s_stack *stack)
{
	void	*top;

	top = NULL;
	if (!stack || !stack->item)
		return (NULL);
	top = stack->item;
	stack->item = stack->item->next;
	return (top);
}

void					printReverseV2(struct s_node *lst)
{
	struct s_item	*top;
	struct s_stack	*stack;
	struct s_node	*lst_tmp;

	if (!lst || !(stack = stackInit()))
		return ;
	lst_tmp = lst;
	while (lst_tmp)
	{
		push(stack, lst_tmp->word);
		lst_tmp = lst_tmp->next;
	}
	while ((top = pop(stack)) != NULL)
	{
		printf("%s%c", top->word, (top->next) ? ' ' : '\n');
		free(top);
	}
	free(stack);
}
