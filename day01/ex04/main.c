#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

# define BUFF_SIZE 255

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/
	int				len;
	int				flag;
	char			*message;
	char			buff[BUFF_SIZE + 1];
	struct s_queue	*queue;

	flag = 0;
	if (!(queue = queueInit()))
		return (1);
	while (42)
	{
		fgets(buff, BUFF_SIZE + 1, stdin);
		if ((len = strlen(buff)) > 1)
		{
			buff[len - 1] = '\0';
			if (strcmp(buff, "EXIT") == 0)
				break ;
			else if (strcmp(buff, "DEQUEUE") == 0)
			{
				message = dequeue(queue);
				printf("%s\n", message);
				free (message);
			}
			else if (strcmp(buff, "PEEK") == 0)
			{
				message = peek(queue);
				printf("%s\n", message);
			}
			else if (strcmp(buff, "ISEMPTY") == 0)
			{
				flag = isEmpty(queue);
				printf("%s\n", ((flag) ? "Yes" : "No"));
			}
			else
			{
				message = strdup(buff);
				enqueue(queue, message);
			}
		}
	}
	queueFree(queue);
	return (0);
}

// Function used for the test
// Don't go further :)
