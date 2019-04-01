#include "header.h"
#include <stdlib.h>
#include <string.h>

char		*getSum(char *a, char *b)
{
	int		i;
	int		r;
	char	*bits;

	if (!(bits = (char *)malloc(sizeof(char) * 7)))
		return (NULL);
	bzero(bits, sizeof(char) * 7);
	i = 5;
	r = 0;
	while (i >= 0)
	{
		bits[i] = (r == 1) ? '1' : '0';
		if (a[i] == '1' && b[i] == '1')
			r = 1;
		else if (a[i] == '1' || b[i] == '1')
		{
			bits[i] = (r == 1) ? '0' : '1';
			r = (r == 1) ? 1 : 0;
		}
		else
			r = 0;
		i -= 1;
	}
	return (bits);
}

int			toInt(char *bits)
{
	int		i;
	int		nbr;
	int		two;

	i = 5;
	two = 1;
	nbr = 0;
	while (i >= 0)
	{
		nbr += (bits[i] == '1') ? two : 0;
		two = two * 2;
		i -= 1;
	}
	return (nbr);
}
