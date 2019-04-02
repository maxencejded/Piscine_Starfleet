#include "header.h"
#include <stdlib.h>

int			**pianoDecompress(struct s_bit *bit, int l)
{
	int		i;
	int		j;
	int		**song;

	if (!(song = (int **)malloc(sizeof(int *) * (bit->n + 1))))
		return (NULL);
	i = 0;
	while (i < bit->n)
	{
		song[i] = (int *)malloc(sizeof(int) * l);
		j = 0;
		while (j < l)
		{
			song[i][j] = (bit->arr[i] & 1) ? 1 : 0;
			bit->arr[i] >>= 1;
			j += 1;
		}
		i += 1;
	}
	song[i] = NULL;
	return (song);
}
