#include "header.h"
#include <stdlib.h>

struct s_queue			*queueInit(void)
{
	struct s_queue	*queue;

	if (!(queue = (struct s_queue *)malloc(sizeof(struct s_queue))))
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

void					queueFree(struct s_queue *queue)
{
	struct s_node	*tmp;

	tmp = NULL;
	while (queue->first)
	{
		tmp = queue->first;
		queue->first = queue->first->next;
		free(tmp->message);
		free(tmp);
	}
	free(queue);
}

static struct s_node	*nodeInit(char *message)
{
	struct s_node	*i;

	if (!(i = (struct s_node *)malloc(sizeof(struct s_node))))
		return (NULL);
	i->message = message;
	i->next = NULL;
	return (i);
}

void					enqueue(struct s_queue *queue, char *message)
{
	struct s_node	*i;

	if (!queue || !(i = nodeInit(message)))
		return ;
	if (!queue->last)
		queue->first = i;
	else
		queue->last->next = i;
	queue->last = i;
}

char					*dequeue(struct s_queue *queue)
{
	char			*message;
	struct s_node	*i;

	if (!queue || !queue->first)
		return (NULL);
	i = queue->first;
	queue->first = i->next;
	message = i->message;
	free(i);
	return (message);
}

char					*peek(struct s_queue *queue)
{
	char			*message;

	if (!queue || !queue->first)
		return (NULL);
	message = queue->first->message;
	return (message);
}

int						isEmpty(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (1);
	return (0);
}
