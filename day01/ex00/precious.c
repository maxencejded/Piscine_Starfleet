#include "header.h"
#include <stdlib.h>
#include <string.h>

static struct s_node	*init_node(char c)
{
	struct s_node	*new;

	if (!(new = (struct s_node *)malloc(sizeof(struct s_node))))
		return (NULL);
	new->c = c;
	new->prev = new;
	new->next = new;
	return (new);
}

static int				node_push(struct s_node **head, char c)
{
	struct s_node	*new;

	if (!head || !(new = init_node(c)))
		return (0);
	else if (!*head)
		*head = new;
	else
	{
		new->next = *head;
		new->prev = (*head)->prev;
		(*head)->prev = new;
		new->prev->next = new;
		*head = new;
	}
	return (1);
}

static struct s_node	*create_machine()
{
	int				i;
	struct s_node	*head;

	head = NULL;
	i = strlen(CS);
	while (--i >= 0)
	{
		if (!node_push(&head, CS[i]))
			return (NULL);
	}
	return (head);
}

char					*precious(int *text, int size)
{
	int				i;
	int				nbr;
	char			*mess;
	struct s_node	*head;

	if (!(head = create_machine()))
		return (NULL);
	if (!(mess = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	for (i = 0; i < size; i += 1)
	{
		if ((nbr = text[i]) >= 0)
			while (nbr-- > 0)
				head = head->next;
		else
			while (nbr++ < 0)
				head = head->prev;
		mess[i] = head->c;
	}
	mess[i] = '\0';
	return (mess);
}
