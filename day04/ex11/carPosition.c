#include "header.h"

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
		if (parkingRow & 1)
			flags = addition(flags, 1);
		parkingRow >>= 1;
		nbr = addition(nbr, 1);
	}
	return ((flags == 1) ? nbr : -1);
}
