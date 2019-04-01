#include "header.h"

int		isFilled(unsigned int parkingRow)
{
	if (parkingRow == 0)
		return (1);
	if (~parkingRow & 1)
		return (0);
	return (isFilled(parkingRow >> 1));
}
