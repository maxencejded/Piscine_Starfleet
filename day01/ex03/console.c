#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct s_stack		*initStack()
{
	struct s_stack	*stack;

	if (!(stack = (struct s_stack *)malloc(sizeof(struct s_stack))))
		return (NULL);
	stack->item = NULL;
	return (stack);
}

static struct s_item	*initItem(int idx)
{
	struct s_item	*i;

	if (!(i = (struct s_item *)malloc(sizeof(struct s_item))))
		return (NULL);
	i->idx = idx;
	i->next = NULL;
	return (i);
}

void				push(struct s_stack *stack, int idx)
{
	struct s_item	*i;

	if (!stack || !(i = initItem(idx)))
		return ;
	i->next = stack->item;
	stack->item = i;
}

int					pop(struct s_stack *stack)
{
	int				ret;
	struct s_item	*i;

	if (!stack || !stack->item)
		return (-1);
	i = stack->item;
	ret = i->idx;
	free(i);
	stack->item = stack->item->next;
	return (ret);

}

# define BUFF_SIZE 255

char				*console(void)
{
	int				len;
	int				index;
	char			buff[BUFF_SIZE + 1];
	char			*message;
	struct s_stack	*stack;

	if (!(stack = initStack()))
		return (NULL);
	if (!(message = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (NULL);
	bzero(message, sizeof(char) * (BUFF_SIZE + 1));
	index = 0;
	while (42)
	{
		printf("🥖  > ");
		fgets(buff, BUFF_SIZE + 1, stdin);
		if ((len = strlen(buff)) > 1)
		{
			buff[len - 1] = '\0';
			if (strcmp(buff, "SEND") == 0)
				break ;
			else if (strcmp(buff, "UNDO") == 0)
			{
				index = pop(stack);
				if (index == -1)
					index = 0;
				bzero(message + index - 1, BUFF_SIZE - index - 1);
			}
			else
			{
				push(stack, index);
				message[index - 1] = (index != 0) ? ' ' : '\0';
				message = strcat(message, buff);
				index += len;
			}
		}
		printf("%s\n\n", message);
	}
	return (message);
}
