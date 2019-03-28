#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	/*-------------------
	launch your test here
	--------------------*/
	char		*mess;

	mess = console();
	printf("this message is sended: \"%s\"\n", mess);
	free(mess);

	return (0);
}

// Function used for the test
// Don't go further :)
