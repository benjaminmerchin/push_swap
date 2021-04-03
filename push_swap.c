/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:43:17 by bmerchin          #+#    #+#             */
/*   Updated: 2021/03/03 16:43:18 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
int		ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	find_who_to_push_b(t_data *data, int pivot) //optimmiser pour trouver la pesronne la plus proche dans le top 3 et dans les 2 sens
{
	int i;

	i = data->spliter;
	data->above_val = 2147483647;
	data->bellow_val = -2147483648;
	while (i < data->size)
	{
		if (data->list[i] = pivot)
			data->equal_pos = i;
		else if (data->list[i] > pivot) // on est plus proche du pivot et AU DESSUS
		{
			if (data->list[i] <= data->above_val)
			{
				data->above_val = data->list[i];
				data->above_pos = i;
			}
		}
		else if (data->list[i] < pivot) // on est plus proche du pivot et EN DESSOUS
		{
			if (data->list[i] >= data->bellow_val)
			{
				data->bellow_val = data->list[i];
				data->bellow_pos = i;
			}
		}
		i++;
	}
	// i pivort est positif ou egal a 0, ca signifie qu'on est sur un premier passage et on a pivot
}

void	insersion_sort_b(t_data *data)
{
	int i;
	int pivot;

	i = data->spliter;
	pivot = median(data, data->spliter, data->size);
	printf(">>>pivot insersion_sort_b : %d<<<\n", pivot);
	find_who_to_push_b(data, pivot);
}

void	quick_sort(t_data *data)
{
	int i;
	int pivot;

	i = 0;
	pivot = median(data, 0, data->size);
	while (i < data->size)
	{
		if (data->list[data->spliter - 1] < pivot)
		{
			pb(data);
			ft_putstr("pb\n");
		}
		else
		{
			ra(data);
			ft_putstr("ra\n");
		}
		i++;
	}
	print_state(data);
	insersion_sort_b(data);
}

void	sort_two_top_a(t_data *data)
{
	if (data->list[data->spliter - 1] > data->list[data->spliter - 2])
	{
		sa(data);
		ft_putstr("sa\n");
	}
}

void	sort_only_three(t_data *data)
{
	if (data->list[data->spliter - 1] < data->list[data->spliter - 3] &&
	data->list[data->spliter - 3] < data->list[data->spliter - 2])
	{
		ra(data);
		ft_putstr("ra\n");
		sa(data);
		ft_putstr("sa\n");
		rra(data);
		ft_putstr("rra\n");
	}
	else if (data->list[data->spliter - 2] < data->list[data->spliter - 1] &&
	data->list[data->spliter - 1] < data->list[data->spliter - 3])
	{
		sa(data);
		ft_putstr("sa\n");
	}
	else if (data->list[data->spliter - 3] < data->list[data->spliter - 1] &&
	data->list[data->spliter - 1] < data->list[data->spliter - 2])
	{
		rra(data);
		ft_putstr("rra\n");
	}
	else if (data->list[data->spliter - 2] < data->list[data->spliter - 3] &&
	data->list[data->spliter - 3] < data->list[data->spliter - 1])
	{
		ra(data);
		ft_putstr("ra\n");
	}
	else if (data->list[data->spliter - 3] < data->list[data->spliter - 2] &&
	data->list[data->spliter - 2] < data->list[data->spliter - 1])
	{
		sa(data);
		ft_putstr("sa\n");
		rra(data);
		ft_putstr("rra\n");
	}
}

void	sort(t_data *data)
{
	if (data->size == 1)
		return ;
	else if (data->size == 2)
		sort_two_top_a(data);
	else if (data->size == 3)
		sort_only_three(data);
	else
		quick_sort(data);
}

int main(int ac, char **av)
{
	int i;
	t_data data;
	char **tab;
	
	i = 0;
	data.error = 0;
	if (ac == 1)
		return (0);
	data.spliter = ac - 1;
	data.size = ac - 1;
	data.error_instruc = 0;
	if (!(data.list = malloc(sizeof(int) * (ac - 1))))
		return (0); //message d'erreur
	i = ac - 1;
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		i = ft_nbr_str(av[1], ' ');
		//printf(">>>i : %d<<<\n", i);
		//printf(">>>tab 0: %s<<<\n", tab[0]);
		//printf(">>>tab 1: %s<<<\n", tab[1]);
		data.spliter = i;
		data.size = i;
	}
	while (i > 0)
	{
		//security qu'on a bien un int en entree;
		//security no duplicates
		if (ac == 2)
		{
			data.list[data.spliter - i] = atoi(tab[i - 1]);
			//printf(">>>%d<<<\n", atoi(tab[i - 1]));
		}
		else
			data.list[ac - i - 1] = atoi(av[i]);
		i--;
	}
	//printf(">>>lst 0: %d<<<\n", data.list[0]);
	//printf(">>>lst 1: %d<<<\n", data.list[1]);
	print_state(&data);
	sort(&data);
	print_state(&data);
	free(data.list);
	if (ac == 2)
		ft_free(tab, ft_nbr_str(av[1], ' '));
	//ft_putstr(av[1]);
	return (0);
}
