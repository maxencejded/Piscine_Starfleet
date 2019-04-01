#include "header.h"
#include <math.h>

int			getPlace(unsigned int parkingRow, int pos)
{
	int		two;

	two = pow(2, pos);
	return ((parkingRow & two) ? 1 : 0);
}
