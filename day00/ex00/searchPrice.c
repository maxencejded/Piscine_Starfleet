#include "header.h"
#include <string.h>

int		searchPrice(struct s_art **arts, char *name)
{
	int		i;

	i = -1;
	while (arts[++i] != NULL)
		if (strcmp(arts[i]->name, name) == 0)
			return (i);
	return (-1);
}
