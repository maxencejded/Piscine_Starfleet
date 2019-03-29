#include "header.h"

static void		swapNodeLeft(struct s_node **head)
{
	struct s_node	*n_head;
	struct s_node	*right;
	struct s_node	*n_left;

	n_left = *head;
	right = n_left->right;
	n_head = n_left->left;
	n_left->left = n_head->left;
	n_left->right = n_head->right;
	n_head->right = right;
	n_head->left = n_left;
	*head = n_head;
}

static void		swapNodeRight(struct s_node **head)
{
	struct s_node	*n_head;
	struct s_node	*left;
	struct s_node	*n_right;

	n_right = *head;
	left = n_right->left;
	n_head = n_right->right;
	n_right->left = n_head->left;
	n_right->right = n_head->right;
	n_head->left = left;
	n_head->right = n_right;
	*head = n_head;
}

void			saveTheSequoia(struct s_node **root)
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
