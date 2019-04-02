#include "header.h"

int		isFilled(unsigned int parkingRow)
{
	if (parkingRow)
	{
		if (~parkingRow & 1)
			return (0);
		return (isFilled(parkingRow >> 1));
	}
	return (1);
}
