#include "header.h"
#include <stdlib.h>
#include <string.h>

char		*rightShift(char *bin, int k)
{
	int		i;
	char	*bits;

	if (!(bits = (char *)malloc(sizeof(char) * 7)))
		return (NULL);
	bzero(bits, sizeof(char) * 7);
	i = 5;
	while (i - k >= 0)
	{
		bits[i] = bin[i - k];
		i -= 1;
	}
	while (i >= 0)
	{
		bits[i] = bin[0];
		i -= 1;
	}
	return (bits);
}

char		*leftShift(char *bin, int k)
{
	int		i;
	char	*bits;

	if (!(bits = (char *)malloc(sizeof(char) * 7)))
		return (NULL);
	bzero(bits, sizeof(char) * 7);
	i = 0;
	while (i + k <= 5)
	{
		bits[i] = bin[i + k];
		i += 1;
	}
	while (i <= 5)
	{
		bits[i] = '0';
		i += 1;
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
	while (i >= 1)
	{
		nbr += (bits[i] == '1') ? two : 0;
		two = two * 2;
		i -= 1;
	}
	if (bits[i] == '1')
		nbr = nbr - 32;
	return (nbr);
}
