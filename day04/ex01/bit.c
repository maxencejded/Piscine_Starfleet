#include <stdlib.h>
#include <string.h>

static void		handleNot(char *bits)
{
	int		i;

	i = 4;
	while (i > 0)
	{
		bits[i] = (bits[i] == '1') ? '0' : '1';
		i -= 1;
	}
}

char		*getAnd(char *a, char *b)
{
	int		i;
	int		j;
	int		k;
	char	*bits;

	if (!(bits = (char *)malloc(sizeof(char) * 5)))
		return (NULL);
	bzero(bits, sizeof(char) * 5);
	i = (a[0] == '~') ? 4 : 3;
	j = (b[0] == '~') ? 4 : 3;
	if (a[0] == '~')
		handleNot(a);
	if (b[0] == '~')
		handleNot(b);
	k = 3;
	while (k >= 0)
	{
		bits[k] = '0';
		if (a[i] == '1' && b[j] == '1')
			bits[k] = '1';
		i -= 1;
		j -= 1;
		k -= 1;
	}
	return (bits);
}

char		*getOr(char *a, char *b)
{
	int		i;
	int		j;
	int		k;
	char	*bits;

	if (!(bits = (char *)malloc(sizeof(char) * 5)))
		return (NULL);
	bzero(bits, sizeof(char) * 5);
	i = (a[0] == '~') ? 4 : 3;
	j = (b[0] == '~') ? 4 : 3;
	if (a[0] == '~')
		handleNot(a);
	if (b[0] == '~')
		handleNot(b);
	k = 3;
	while (k >= 0)
	{
		bits[k] = '0';
		if (a[i] == '1' || b[j] == '1')
			bits[k] = '1';
		i -= 1;
		j -= 1;
		k -= 1;
	}
	return (bits);
}

int			toInt(char *bits)
{
	int		i;
	int		nbr;
	int		two;

	i = 3;
	two = 1;
	nbr = 0;
	while (i >= 0)
	{
		nbr += (bits[i] == '1') ? two : 0;
		two = two * 2;
		i -= 1;
	}
	return (nbr);
}
