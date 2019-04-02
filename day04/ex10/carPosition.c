#include "header.h"

int			addition(int x, int y)
{
	if (y == 0)
		return x;
	return (addition( x ^ y, (x & y) << 1));
}

int			carPosition(unsigned int parkingRow)
{
	int		nbr;
	int		flags;

	nbr = 0;
	flags = 0;
	while (parkingRow != 0)
	{
		if (parkingRow & 1)
			flags = addition(flags, 1);
		parkingRow >>= 1;
		nbr = addition(nbr, 1);
	}
	return ((flags == 1) ? nbr : -1);
}
