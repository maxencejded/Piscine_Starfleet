#include "header.h"
#include <math.h>

static unsigned int	setPlace(unsigned int parkingRow, int pos)
{
	int				two;
	unsigned int	place;

	two = pow(2, pos);
	place = parkingRow;
	if (!(parkingRow & two))
		place = parkingRow ^ two;
	return (place);
}

static unsigned int	clearPlace(unsigned int parkingRow, int pos)
{
	int				two;
	unsigned int	place;

	two = pow(2, pos);
	place = parkingRow;
	if (parkingRow & two)
		place = parkingRow ^ two;
	return (place);
}

unsigned int		updatePlace(unsigned int parkingRow, int pos, int value)
{
	return ((value == 1) ? setPlace(parkingRow, pos) : clearPlace(parkingRow, pos));
}
