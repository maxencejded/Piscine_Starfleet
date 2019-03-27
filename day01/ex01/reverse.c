#include "header.h"
#include <stdio.h>

void			printRecursive(struct s_node *lst)
{
	if (lst->next)
		printRecursive(lst->next);
	printf("%s ", lst->word);
}

void			printReverse(struct s_node *lst)
{
	if (lst->next)
		printRecursive(lst->next);
	printf("%s\n", lst->word);
}
