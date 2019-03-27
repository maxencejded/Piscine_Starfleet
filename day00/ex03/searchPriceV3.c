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

struct s_item	*create_elem(char *key, struct s_art *value)
{
	struct s_item	*new;

	if (!(new = (struct s_item	*)malloc(sizeof(struct s_item))))
		return (NULL);
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}

int				dictInsert(struct s_dict *dict, char *key, struct s_art *value)
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

struct s_art	*dictSearch(struct s_dict *dict, char *key)
{
	size_t			index;
	struct s_item	*tmp;

	if (!dict || !key)
		return (NULL);
	index = hash(key) % dict->capacity;
	if (dict->items[index] == NULL)
		return (NULL);
	else if (dict->items[index]->next == NULL)
		return (dict->items[index]->value);
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
	return (NULL);
}

int 			searchPrice(struct s_dict *dict, char *name)
{
	struct s_art	*elem;

	elem = NULL;
	if (dict)
		if ((elem = dictSearch(dict, name)))
			return (elem->price);
	return (-1);
}
