#include "header.h"
#include <stdlib.h>

static struct s_node	*nodeInit(int value)
{
	struct s_node	*i;

	if (!(i = (struct s_node *)malloc(sizeof(struct s_node))))
		return (NULL);
	i->value = value;
	i->right = NULL;
	i->left = NULL;
	return (i);
}

static void				nodePush(struct s_node *root, int value)
{
	if (value < root->value)
	{
		if (!root->left)
			root->left = nodeInit(value);
		else
			nodePush(root->left, value);
	}
	else
	{
		if (!root->right)
			root->right = nodeInit(value);
		else
			nodePush(root->right, value);
	}
}

struct s_node			*createBST(int *arr, int n)
{
	int				i;
	struct s_node	*root;

	root = NULL;
	i = 0;
	while (i < n)
	{
		if (!root)
			root = nodeInit(arr[i]);
		else
			nodePush(root, arr[i]);
		i += 1;
	}
	return (root);
}
