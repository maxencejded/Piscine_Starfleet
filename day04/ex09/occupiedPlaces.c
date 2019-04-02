#include "header.h"

int		addition(int x, int y)
{
	if (y == 0)
		return x;
	return (addition( x ^ y, (x & y) << 1));
}

int			occupiedPlaces(unsigned int parkingRow)
{
	int		nbr;

	nbr = 0;
	while (parkingRow != 0)
	{
		if (parkingRow & 1)
			nbr = addition(nbr, 1);
		parkingRow >>= 1;
	}
	return (nbr);
}
