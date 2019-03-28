#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

#define BUFF_SIZE 255

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/
	int				len;
	int				nbr;
	char			buff[BUFF_SIZE + 1];
	struct s_tank	*tank;

	nbr = 0;
	if (!(tank = initTank()))
		return (1);
	while (42)
	{
		fgets(buff, BUFF_SIZE + 1, stdin);
		if ((len = strlen(buff)) > 1)
		{
			buff[len - 1] = '\0';
			if (strcmp(buff, "EXIT") == 0)
				break ;
			else if (strcmp(buff, "PRINT") == 0)
				tankPrint(tank);
			else if (strcmp(buff, "POP") == 0)
				printf("%d\n", tankPop(tank));
			else
			{
				nbr = atoi(buff);
				tankPush(tank, nbr);
			}
		}
	}
	tankFree(tank);
	system("leaks tank");
	return (0);
}

// Function used for the test
// Don't go further :)
