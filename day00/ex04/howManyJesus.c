#include "header.h"
#include <string.h>

static size_t	hash(char *input, unsigned int len)
{
	unsigned int	i;
	size_t			hash;

	hash = 2166136261;
	i = 0;
	while (i < len)
	{
		hash ^= input[i];
		hash *= 16777619;
		i += 1;
	}
	return ((size_t)hash);
}

int		howManyJesus(char *bible, char *jesus)
{
	int j_len, b_len;
	size_t j_hash, b_hash;
	int ret;;

	ret = 0;
	j_len = strlen(jesus);
	b_len = strlen(bible);
	j_hash = hash(jesus, j_len);
	for (int i = 0; i <= b_len - j_len; i++)
	{
		b_hash = hash(&bible[i], j_len);
		if (j_hash == b_hash)
			ret += (strncmp(jesus, &bible[i], j_len) == 0) ? 1 : 0;
	}
	return (ret);
}
