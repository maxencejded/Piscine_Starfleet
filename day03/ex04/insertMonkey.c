#include "header.h"

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

static void		pushLeft(struct s_node **root, struct s_node *monkey)
{
	if ((*root)->left)
		pushLeft(&(*root)->left, monkey);
	else
		(*root)->left = monkey;
}

void			insertMonkey(struct s_node **root, struct s_node *monkey)
{
	pushLeft(root, monkey);
	saveTheSequoia(root);
}
