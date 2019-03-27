#include "header.h"
#include <string.h>

/*
** Implementation of Insertion Sort
** Complexity:
**		time: O(n^2)
**		space: O(1)
*/
void	sortArts(struct s_art **arts)
{
	int				i;
	int				j;
	struct s_art	*swap;

	i = 1;
	while (arts[i])
	{
		swap = arts[i];
		j = i - 1;
		while (j >= 0 && strcmp(arts[j]->name, swap->name) > 0)
		{
			arts[j + 1] = arts[j];
			j -= 1;
		}
		arts[j + 1] = swap;
		i += 1;
	}
}
