#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(int ac, char **av)
{
	int				pos;
	unsigned int	parkingRow;

	if (ac == 3 && (pos = atoi(av[2])) >= 0 && pos < 20) {
		parkingRow = atoi(av[1]);
	}else{
		printf("Usage: ./setPlace parkingRow pos\n");
		return (1);
	}
	/*-------------------
	launch your test here
	--------------------*/
	printf("New parking row: %d\n", setPlace(parkingRow, pos));

	return (0);
}

// Function used for the test
// Don't go further :)
