#include "header.h"

void		insertionSort(struct s_player **players)
{
	int				i;
	int				j;
	struct s_player	*tmp;

	i = 0;
	while (players[i])
	{
		tmp = players[i];
		j = i - 1;
		while (j >= 0 && tmp->score > players[j]->score)
		{
			players[j + 1] = players[j];
			j -= 1;
		}
		players[j + 1] = tmp;
		i += 1;
	}
}
