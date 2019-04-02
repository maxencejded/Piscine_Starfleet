#include "header.h"
#include <math.h>

unsigned int		clearBits(unsigned int parkingRow, int n)
{
	int		i;
	int		two;

	i = 0;
	while (i < n)
	{
		two = pow(2, i);
		if (parkingRow & two)
			parkingRow = parkingRow ^ two;
		i += 1;
	}
	return (parkingRow);
}
