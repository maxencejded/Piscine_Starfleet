#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_tank				*initTank(void)
{
	struct s_tank	*tank;

	if (!(tank = (struct s_tank *)malloc(sizeof(struct s_tank))))
		return (NULL);
	tank->stacks = NULL;
	tank->n = 0;
	return (tank);
}

static struct s_elem		*initElem(int energy)
{
	struct s_elem	*i;

	if (!(i = (struct s_elem *)malloc(sizeof(struct s_elem))))
		return (NULL);
	i->energy = energy;
	i->next = NULL;
	return (i);
}

static struct s_stack		*initStack(int energy)
{
	struct s_stack		*i;

	if (!(i = (struct s_stack *)malloc(sizeof(struct s_stack))))
		return (NULL);
	i->elem = initElem(energy);
	i->sum = energy;
	return (i);
}

void						tankPush(struct s_tank *tank, int energy)
{
	struct s_elem	*e_tmp;

	if (!tank || (energy > 100 || energy < 10))
		return ;
	if (tank->n == 0)
	{
		if (!(tank->stacks = (struct s_stack **)malloc(sizeof(struct s_stack *))))
			return ;
		if (!(tank->stacks[0] = initStack(energy)))
			return ;
		tank->n += 1;
	}
	else
	{
		if ((tank->stacks[tank->n - 1]->sum + energy) <= 1000)
		{
			if (!(e_tmp = initElem(energy)))
				return ;
			e_tmp->next = tank->stacks[tank->n - 1]->elem;
			tank->stacks[tank->n - 1]->elem = e_tmp;
			tank->stacks[tank->n - 1]->sum += e_tmp->energy;
		}
		else
		{
			tank->n += 1;
			if (!(tank->stacks = (struct s_stack **)realloc(tank->stacks, sizeof(struct s_stack *) * tank->n)))
				return ;
			if (!(tank->stacks[tank->n - 1] = initStack(energy)))
				return ;
		}
	}
}

int							tankPop(struct s_tank *tank)
{
	int				i;
	int				energy;
	struct s_elem	*e_tmp;
	struct s_stack	**s_tmp;

	if (!tank || (tank->n == 0) || (tank->stacks[0]->sum == 0))
		return (0);
	e_tmp = tank->stacks[tank->n - 1]->elem;
	tank->stacks[tank->n - 1]->elem = e_tmp->next;
	tank->stacks[tank->n - 1]->sum -= e_tmp->energy;
	energy = e_tmp->energy;
	free(e_tmp);
	if (!tank->stacks[tank->n - 1]->elem)
	{
		free(tank->stacks[tank->n - 1]);
		tank->n -= 1;
		if (!(s_tmp = (struct s_stack **)malloc(sizeof(struct s_stack *))))
			return (energy);
		i = -1;
		while (++i < tank->n)
			s_tmp[i] = tank->stacks[i];
		free(tank->stacks);
		tank->stacks = s_tmp;
	}
	return (energy);
}

void						tankPrint(struct s_tank *tank)
{
	int			i;

	if (tank->n == 0)
		printf("No tank\n");
	i = -1;
	while (++i < tank->n)
	{
		if (i == 0)
			printf("normal%c", ((i == (tank->n - 1)) ? '\n' : '\t'));
		else
			printf("nitro%d%c", i, ((i == (tank->n - 1)) ? '\n' : '\t'));
	}
	i = -1;
	while (++i < tank->n)
		printf("------%c", ((i == (tank->n - 1)) ? '\n' : '\t'));
	i = -1;
	while (++i < tank->n)
		printf("|%4d|%c", tank->stacks[i]->sum, ((i == (tank->n - 1)) ? '\n' : '\t'));
	i = -1;
	while (++i < tank->n)
		printf("|    |%c", ((i == (tank->n - 1)) ? '\n' : '\t'));
		i += 1;
	printf("\n");
}

void						tankFree(struct s_tank *tank)
{
	int				i;
	struct s_elem	*e_tmp;

	i = -1;
	while (++i < tank->n)
	{
		while(tank->stacks[i]->elem)
		{
			e_tmp = tank->stacks[i]->elem;
			tank->stacks[i]->elem = tank->stacks[i]->elem->next;
			free(e_tmp);
		}
		free(tank->stacks[i]);
	}
	free(tank->stacks);
	free(tank);
}
