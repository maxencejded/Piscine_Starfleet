#include "header.h"

int			addition(int x, int y)
{
	if (y)
		return (addition( x ^ y, (x & y) << 1));
	return (x);
}

int			leftmostCar(unsigned int parkingRow)
{
	int		nbr;

	nbr = -1;
	while (parkingRow)
	{
		parkingRow >>= 1;
		nbr = addition(nbr, 1);
	}
	return (nbr);
}
