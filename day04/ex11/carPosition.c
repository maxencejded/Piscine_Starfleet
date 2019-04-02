#include "header.h"
#include <math.h>

int			addition(int x, int y)
{
	if (y)
		return (addition( x ^ y, (x & y) << 1));
	return (x);
}

int			carPosition(unsigned int parkingRow)
{
	int		nbr;
	int		flags;

	nbr = -1;
	flags = 0;
	while (parkingRow)
	{
		nbr = addition(nbr, 1);
		if (parkingRow & 1)
			flags |= (int)pow(2, nbr);
		parkingRow >>= 1;
	}
	return ((flags & 2) ? -1 : nbr);
}
