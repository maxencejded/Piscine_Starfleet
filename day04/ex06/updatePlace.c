#include "header.h"
#include <math.h>

unsigned int	setPlace(unsigned int parkingRow, int pos)
{
	int				two;
	unsigned int	place;

	two = pow(2, pos);
	place = parkingRow;
	if (!(parkingRow & two))
		place = parkingRow ^ two;
	return (place);
}
