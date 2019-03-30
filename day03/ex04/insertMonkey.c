#include "header.h"
#include <stdlib.h>
#include <stdio.h>

static void		swapNodeLeft(struct s_node **head)
{
	struct s_node	*n_head;
	struct s_node	*right_old;

	n_head = (*head)->left;
	right_old = (*head)->right;
	(*head)->left = n_head->left;
	(*head)->right = n_head->right;
	n_head->right = right_old;
	n_head->left = (*head);
	*head = n_head;
}

static void		swapNodeRight(struct s_node **head)
{
	struct s_node	*n_head;
	struct s_node	*left_old;

	n_head = (*head)->right;
	left_old = (*head)->left;
	(*head)->left = n_head->left;
	(*head)->right = n_head->right;
	n_head->left = left_old;
	n_head->right = (*head);
	*head = n_head;
}

static void		saveTheSequoia(struct s_node **root)
{
	if ((*root)->left)
		saveTheSequoia(&(*root)->left);
	if ((*root)->right)
		saveTheSequoia(&(*root)->right);
	if ((*root)->left && (*root)->value < (*root)->left->value)
	{
		swapNodeLeft(root);
		saveTheSequoia(&(*root)->left);
	}
	if ((*root)->right && (*root)->value < (*root)->right->value)
	{
		swapNodeRight(root);
		saveTheSequoia(&(*root)->right);
	}
}

struct s_queue			*queueInit(int size)
{
	struct s_queue	*queue;

	if (!(queue = (struct s_queue *)malloc(sizeof(struct s_queue))))
		return (NULL);
	queue->front = -1;
	queue->rear = -1;
	queue->size = size;
	queue->height = (int *)malloc(sizeof(int) * size);
	queue->array = (struct s_node **)malloc(sizeof(struct s_node *) * size);
	return (queue);
}

void					queueShift(struct s_queue *queue)
{
	int			i;

	if (queue->front == 0)
		queue->front = 1;
	i = queue->front;
	while (i < queue->rear)
	{
		queue->array[i - 1] = queue->array[i];
		queue->height[i - 1] = queue->height[i];
		i += 1;
	}
	queue->front--;
	queue->rear--;
	queue->size--;
}

void					enqueue(struct s_queue *queue, struct s_node *i, int height)
{
	if (queue->rear == queue->size - 1)
		queueShift(queue);
	queue->array[++queue->rear] = i;
	queue->height[queue->rear] = height;
	if (queue->front == -1)
		++queue->front;
}

struct s_node			*dequeue(struct s_queue *queue)
{
	struct s_node	*tmp;

	tmp = NULL;
	if (!queue || queue->front == -1)
		return (NULL);
	tmp = queue->array[queue->front];
	if (queue->front == queue->rear)
	{
		queue->front = -1;
		queue->rear = -1;
	}
	else
		queue->front += 1;
	return (tmp);
}

struct s_node 			*peek(struct s_queue *queue, int *height)
{
	if (!queue || queue->front == -1)
		return (NULL);
	*height = queue->height[queue->front];
	return (queue->array[queue->front]);
}

void					insertNode(struct s_node **root, struct s_node *monkey, struct s_queue *queue)
{
	int				height;
	struct s_node	*front;

	height = 0;
	front = NULL;
	if (!*root)
		*root = monkey;
	else
	{
		front = peek(queue, &height);
		if (!front->left)
			front->left = monkey;
		else if (!front->right)
			front->right = monkey;
		if (front && front->left && front->right)
			dequeue(queue);
	}
	enqueue(queue, monkey, height);
}

void					queueFill(struct s_node *root, struct s_queue *queue, int height)
{
	if (root->left)
		queueFill(root->left, queue, height + 1);
	enqueue(queue, root, height);
	if (root->right)
		queueFill(root->right, queue, height + 1);
}

void					queueSort(struct s_queue *queue)
{
	int				i;
	int				j;
	int				h_tmp;
	struct s_node	*n_tmp;

	i = queue->front;
	while (i <= queue->rear)
	{
		h_tmp = queue->height[i];
		n_tmp = queue->array[i];
		j = i - 1;
		while (j >= 0 && h_tmp < queue->height[j])
		{
			queue->height[j + 1] = queue->height[j];
			queue->array[j + 1] = queue->array[j];
			j -= 1;
		}
		queue->height[j + 1] = h_tmp;
		queue->array[j + 1] = n_tmp;
		i += 1;
	}
}

void					queuePrint(struct s_queue *queue)
{
	int		i;

	i = queue->front;
	while (i <= queue->rear)
	{
		printf("[%d] (%d)\n", queue->array[i]->value, queue->height[i]);
		i += 1;
	}
}

int						asTwoChild(struct s_node *i)
{
	if (i && i->left && i->right)
		return (1);
	return (0);
}

void					queueCheck(struct s_queue *queue)
{
	while (asTwoChild(queue->array[queue->front]))
		queue->front += 1;
}

void					insertMonkey(struct s_node **root, struct s_node *monkey)
{
	int				height;
	struct s_queue	*queue;

	height = 0;
	queue = queueInit(20);
	queueFill(*root, queue, height);
	queueSort(queue);
	queueCheck(queue);
	queuePrint(queue);
	insertNode(root, monkey, queue);
	// saveTheSequoia(root);
}
