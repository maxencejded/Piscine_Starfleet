#include "header.h"

int			addition(int x, int y)
{
	if (y)
		return (addition( x ^ y, (x & y) << 1));
	return (x);
}

int			occupiedPlaces(unsigned int parkingRow)
{
	int		nbr;

	nbr = 0;
	while (parkingRow)
	{
		if (parkingRow & 1)
			nbr = addition(nbr, 1);
		parkingRow >>= 1;
	}
	return (nbr);
}
