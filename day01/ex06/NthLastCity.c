#include "header.h"

#define NULL (void *)0

static void		nth_elem(struct s_city *city, char **elem, int *n)
{
	if (city->next)
		nth_elem(city->next, elem, n);
	if (*n == 0)
		*elem = city->name;
	*n -= 1;
}

char			*NthLastCity(struct s_city *city, int n)
{
	char			*elem;

	elem = NULL;
	nth_elem(city, &elem, &n);
	return (elem);
}
