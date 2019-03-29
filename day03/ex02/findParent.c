#include "header.h"
#include <string.h>

static struct s_node	*findLCA(struct s_node *root, char *one, char *two)
{
	int				i;
	int				height;
	struct s_node	*tmp;
	struct s_node	*parent;

	tmp = NULL;
	parent = NULL;
	height = 0;
	if (!root)
		return (NULL);
	if (strcmp(root->name, one) == 0 || strcmp(root->name, two) == 0)
		return (root);
	for (i = 0; root->children[i]; i+= 1)
	{
		tmp = findLCA(root->children[i], one, two);
		if (tmp)
		{
			height += 1;
			parent = tmp;
		}
	}
	if (height >= 2)
		return (root);
	return (parent);
}

static void				findSpecies(struct s_node *root, char *one, char *two, int *ret)
{
	int		i;

	i = 0;
	if (strcmp(root->name, one) == 0)
		*ret |= 1;
	if (strcmp(root->name, two) == 0)
		*ret |= 2;
	for (i = 0; root->children[i]; i+= 1)
		findSpecies(root->children[i], one, two, ret);
}

struct s_node			*findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	int		exist;

	exist = 0;
	findSpecies(root, firstSpecies, secondSpecies, &exist);
	if (!(exist & 1) || !(exist & 2))
		return (NULL);
	return (findLCA(root, firstSpecies, secondSpecies));
}
