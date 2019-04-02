#include "header.h"
#include <math.h>

int			addition(int x, int y)
{
	if (y)
		return (addition( x ^ y, (x & y) << 1));
	return (x);
}

int			rightmostCar(unsigned int parkingRow)
{
	int		nbr;

	nbr = 0;
	while (parkingRow)
	{
		if (parkingRow & 1)
			return (nbr);
		parkingRow >>= 1;
		nbr = addition(nbr, 1);
	}
	return (-1);
}
