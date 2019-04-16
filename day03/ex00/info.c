#include "header.h"

#define ABS(x, y) (x < y) ? (y - x) : (x - y)

static int			heightTree(struct s_node *root)
{
	int		l_branch;
	int		r_branch;

	if (!root)
		return (0);
	l_branch = heightTree(root->left);
	r_branch = heightTree(root->right);
	return ((l_branch >= r_branch) ? l_branch + 1 : r_branch + 1);
}

static int			balanceTree(struct s_node *root)
{
	int		l_branch;
	int		r_branch;

	if (!root)
		return (1);
	l_branch = heightTree(root->left);
	r_branch = heightTree(root->right);
	return ((ABS(l_branch, r_branch) <= 1 && balanceTree(root->left) && balanceTree(root->right)) ? 1 : 0);
}

static void			traversalTree(struct s_node *root, int *size, int *min, int *max, int *isBST)
{
	if (root->left && root->left->value >= root->value)
		*isBST = 0;
	if (root->right && root->right->value < root->value)
		*isBST = 0;
	if (root->left)
		traversalTree(root->left, size, min, max, isBST);
	*size += 1;
	*min = (root->value < *min) ? root->value : *min;
	*max = (root->value > *max) ? root->value : *max;
	if (root->right)
		traversalTree(root->right, size, min, max, isBST);
}

struct s_info		getInfo(struct s_node *root)
{
	struct s_info	infos;

	infos.min = root->value;
	infos.max = root->value;
	infos.elements = 0;
	infos.height = 0;
	infos.isBST = 1;
	infos.isBalanced = 0;
	traversalTree(root, &infos.elements, &infos.min, &infos.max, &infos.isBST);
	infos.height = heightTree(root) - 1;
	infos.isBalanced = balanceTree(root);
	return (infos);
}
