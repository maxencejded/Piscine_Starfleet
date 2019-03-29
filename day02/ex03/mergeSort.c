#include "header.h"
#include <stdlib.h>
#include <strings.h>

static void			mergeSplit(struct s_player **players, int low, int high, int middle)
{
	int				i, j, k;
	int				s_zero;
	int				s_one;
	struct s_player	**tmp_l;
	struct s_player	**tmp_h;

	s_zero = middle - low + 1;
	s_one = high - middle;
	tmp_l = (struct s_player **)malloc(sizeof(struct s_player *) * s_zero);
	bzero(tmp_l, sizeof(struct s_player *) * s_zero);
	tmp_h = (struct s_player **)malloc(sizeof(struct s_player *) * s_one);
	bzero(tmp_h, sizeof(struct s_player *) * s_one);
	i = -1;
	while (++i < s_zero)
		tmp_l[i] = players[low + i];
	i = -1;
	while (++i < s_one)
		tmp_h[i] = players[middle + 1 + i];
	i = 0;
	j = 0;
	k = 0;
	while (i < s_zero && j < s_one)
	{
		if (tmp_l[i] <= tmp_h[j])
			players[k] = tmp_l[i++];
		else
			players[k] = tmp_h[j++];
		k += 1;
	}
	while (i < s_zero)
		players[k++] = tmp_l[i++];
	while (j < s_one)
		players[k++] = tmp_l[j++];
	free(tmp_h);
	free(tmp_l);
}

static void			mergeSortAlgo(struct s_player **players, int low, int high)
{
	int		middle;

	middle = (low + high - 1) / 2;
	if (low < high)
	{
		mergeSortAlgo(players, low, middle);
		mergeSortAlgo(players, middle + 1, high);
		mergeSplit(players, low, high, middle);
	}
}

struct s_player		**mergeSort(struct s_player **players)
{
	int		size;

	size = 0;
	while (players[size])
		size += 1;
	mergeSortAlgo(players, 0, size  -1);
	return (players);
}
