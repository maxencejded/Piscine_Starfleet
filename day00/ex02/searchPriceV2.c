#include "header.h"
#include <string.h>

int		searchPrice(struct s_art **arts, int n, char *name)
{
	int		low;
	int		middle;
	int		high;
	int		ret;

	low = 0;
	high = n;
	while (42)
	{
		middle = (low + high) / 2;
		if ((ret = strcmp(arts[middle]->name, name)) == 0)
			return (arts[middle]->price);
		else if (ret > 0)
			high = middle - 1;
		else
			low = middle + 1;
		if (low > high)
			break ;
	}
	return (-1);
}
