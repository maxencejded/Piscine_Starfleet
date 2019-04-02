#include "header.h"

int			addition(int x, int y)
{
	if (y)
		return (addition( x ^ y, (x & y) << 1));
	return (x);
}

int			longestSequence(unsigned int parkingRow)
{
	int		nbr;
	int		max;

	max = 0;
	while (parkingRow)
	{
		if (parkingRow & 1)
		{
			nbr = 0;
			while (parkingRow & 1)
			{
				nbr = addition(nbr, 1);
				parkingRow >>= 1;
			}
			if (nbr > max)
				max = nbr;
		}
		parkingRow >>= 1;
	}
	return (max);
}
