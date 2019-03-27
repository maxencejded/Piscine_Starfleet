#include "header.h"
#include <string.h>
#include <stdlib.h>

size_t			hash(char *input)
{
	unsigned int	i;
	size_t			hash;

	hash = 2166136261;
	i = 0;
	while (input[i])
	{
		hash ^= input[i];
		hash *= 16777619;
		i += 1;
	}
	return ((size_t)hash);
}

struct s_dict	*dictInit(int capacity)
{
	struct s_dict	*dict;

	if (!(dict = (struct s_dict *)malloc(sizeof(struct s_dict))))
		return (NULL);
	if (!(dict->items = (struct s_item **)malloc(sizeof(struct s_item *) * capacity)))
	{
		free (dict);
		return (NULL);
	}
	bzero(dict->items, sizeof(struct s_item *) * capacity);
	dict->capacity = capacity;
	return (dict);
}

struct s_item	*create_elem(char *key, int value)
{
	struct s_item	*new;

	if (!(new = (struct s_item	*)malloc(sizeof(struct s_item))))
		return (NULL);
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}

int				dictInsert(struct s_dict *dict, char *key, int value)
{
	size_t			index;
	struct s_item	*new;

	if (!dict || !key || !(new = create_elem(key, value)))
		return (0);
	index = hash(key) % dict->capacity;
	if (dict->items[index] == NULL)
		dict->items[index] = new;
	else
	{
		new->next = dict->items[index];
		dict->items[index] = new;
	}
	return (1);
}

int				dictSearch(struct s_dict *dict, char *key)
{
	size_t			index;
	struct s_item	*tmp;

	if (!dict || !key)
		return (-1);
	index = hash(key) % dict->capacity;
	if (dict->items[index] == NULL)
		return (-1);
	else
	{
		tmp = dict->items[index];
		while (tmp)
		{
			if (strcmp(key, tmp->key) == 0)
				return (tmp->value);
			tmp = tmp->next;
		}
	}
	return (-1);
}

static int		ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

static char		*ft_strmcpy(const char *src, size_t len)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(sizeof(char) * (len + 1));
	i = -1;
	while (src[++i] && i < len)
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

char			*compress(char *book, struct s_dict *dict)
{
	int				i, j;
	int				len;
	int				ret, flag;
	char			*words;
	char			*new_book;

	len = strlen(book);

	// Header
	len += 2;
	for (i = 0; i < dict->capacity; i += 1)
	{
		struct s_item	*tmp;

		tmp = dict->items[i];
		while (tmp)
		{
			len += strlen(tmp->key) + 1;
			tmp = tmp->next;
		}
	}
	if (!(new_book = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	bzero(new_book, len + 1);

	j = 0;
	new_book[j++] = '<';
	for (i = 0; i < dict->capacity; i += 1)
	{
		struct s_item	*tmp;

		tmp = dict->items[i];
		while (tmp)
		{
			new_book = strcat(new_book, tmp->key);
			new_book[strlen(new_book)] = ',';
			tmp = tmp->next;
		}
	}
	j = strlen(new_book);
	new_book[j - 1] = '>';

	i = 0;
	// j = 0;
	while (book[i])
	{
		flag = 1;
		len = 1;
		if (ft_isalpha(book[i]))
		{
			len = 0;
			while (ft_isalpha(book[i + len]))
				len++;
			words = ft_strmcpy(&book[i], len);
			if ((ret = dictSearch(dict, words)) != -1)
			{
				new_book[j++] = '@';
				new_book[j++] = ret;
				flag = 0;
				i += len;
				len = 0;
			}
			free(words);
		}
		if (flag == 1)
		{
			while (len-- > 0)
				new_book[j++] = book[i++];
		}
	}
	return (new_book);
}
