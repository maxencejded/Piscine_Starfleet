#include "header.h"
#include <stdlib.h>
#include <stdio.h>

static struct s_node	*nodeInit(int value)
{
	struct s_node	*i;

	if (!(i = malloc(sizeof(struct s_node))))
		return (NULL);
	i->value = value;
	i->random = NULL;
	i->next = NULL;
	return (i);
}

static struct s_node	*setSubBoard(struct s_node *node, int *size)
{
	struct s_node	*i;
	struct s_node	*tmp;

	tmp = node;
	while (tmp)
	{
		if (!(i = nodeInit(tmp->value)))
			return (NULL);
		i->next = tmp->next;
		tmp->next = i;
		tmp = i->next;
		*size += 1;
	}
	return (node);
}

static struct s_node	*setLink(struct s_node *node, int size)
{
	int				i;
	struct s_node	*tmp;

	i = 0;
	tmp = node;
	while (i < size)
	{
		if (tmp->random)
			tmp->next->random = tmp->random->next;
		tmp = tmp->next;
		if (tmp->next)
			tmp = tmp->next;
		i += 1;
	}
	return (node);
}

static struct s_node	*splitBoard(struct s_node *node)
{
	struct s_node	*clone;
	struct s_node	*c_tmp;
	struct s_node	*tmp;

	clone = node->next;
	tmp = node;
	while (tmp)
	{
		c_tmp = tmp->next;
		if (tmp->next)
		 	tmp->next = tmp->next->next;
		if (c_tmp->next)
			c_tmp->next = c_tmp->next->next;
		tmp = tmp->next;
	}
	return (clone);
}

struct s_node			*cloneGameBoard(struct s_node *node)
{
	int		size;

	size = 0;
	node = setSubBoard(node, &size);
	node = setLink(node, size);
	return (splitBoard(node));
}

void					boardFree(struct s_node *node)
{
	struct s_node	*tmp;

	tmp = node;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}
