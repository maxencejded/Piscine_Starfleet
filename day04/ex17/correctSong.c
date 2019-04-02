#include "header.h"
#include <math.h>

void	correctSong(struct s_bit *bit, int l, int row, int col, int dist)
{
	int		i;

	i = 0;
	while (i < dist && i < l)
	{
		bit->arr[row + i] = pow(2, col);
		i += 1;
	}
}
