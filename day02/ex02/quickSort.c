#include "header.h"

static void		swapPlayer(struct s_player **players, int i, int j)
{
	struct s_player	*tmp;

	tmp = players[i];
	players[i] = players[j];
	players[j] = tmp;
}

static int		quickSortPartition(struct s_player **players, int low, int high)
{
	int		i;
	int		j;
	int		pivot;

	pivot = players[high]->score;
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (players[j]->score >= pivot)
		{
			i += 1;
			swapPlayer(players, i, j);
		}
		j += 1;
	}
	i += 1;
	swapPlayer(players, i, high);
	return (i);
}

static void		quickSortAlgo(struct s_player **players, int low, int high)
{
	int		pivot;

	pivot = 0;
	if (low < high)
	{
		pivot = quickSortPartition(players, low, high);
		quickSortAlgo(players, low, pivot - 1);
		quickSortAlgo(players, pivot + 1, high);
	}
}


void			quickSort(struct s_player **players)
{
	int		size;

	size = 0;
	while (players[size])
		size += 1;
	quickSortAlgo(players, 0, size - 1);
}
