#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	unsigned int	parkingRow;

	if (ac == 2) {
		parkingRow = atoi(av[1]);
	}else{
		printf("usage: ./occupiedPlaces parkingRow\n");
		return (0);
	}
	/*-------------------
	launch your test here
	--------------------*/

	printf("Parking row %d has %d occupied places\n", parkingRow, occupiedPlaces(parkingRow));

	return (0);
}



// Function used for the test
// Don't go further :)
