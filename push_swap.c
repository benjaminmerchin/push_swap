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

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	find_three_closest_pos_b(t_data *data, int pivot)
{
	int i;

	i = data->spliter;
	data->above_val = 2147483647;
	data->bellow_val = -2147483648;
	data->equal_pos = -1;
	while (i < data->size)
	{
		if (data->list[i] == pivot)
			data->equal_pos = i;
		else if (data->list[i] >= pivot)
		{
			if (data->list[i] <= data->above_val)
			{
				data->above_val = data->list[i];
				data->above_pos = i;
			}
		}
		else if (data->list[i] <= pivot)
		{
			if (data->list[i] >= data->bellow_val)
			{
				data->bellow_val = data->list[i];
				data->bellow_pos = i;
			}
		}
		i++;
	} // i pivort est positif ou egal a 0, ca signifie qu'on est sur un premier passage et on a pivot
}

void	find_farthest_pos_b(t_data *data, int pivot)
{
	int i;

	i = data->spliter;
	data->above_val = pivot;
	data->bellow_val = pivot;
	while (i < data->size)
	{
		if (data->list[i] > data->above_val)
		{
			data->above_val = data->list[i];
			data->above_pos = i;
		}
		if (data->list[i] < data->bellow_val)
		{
			data->bellow_val = data->list[i];
			data->bellow_pos = i;
		}
		i++;
	}
}

void	calculate_best_move(t_data *data, int pivot)
{
	int up;
	int down;

	up = ft_min(data->above_pos - data->spliter, data->bellow_pos - data->spliter);
	down = ft_min(data->size - data->above_pos, data->size - data->bellow_pos);
	if (up <= down)
	{
		data->rotation = up;
		data->direction = 1;
	}
	else
	{
		data->rotation = down;
		data->direction = -1;
	}
}

void	execute_best_move_b(t_data *data, int pivot) //combine up & down with the first operation
{
	int i;

	i = 0;
	while(i < data->rotation)
	{
		if (data->direction > 0)
			rbw(data);
		else
			rrbw(data);
		i++;
	}
	paw(data);
}

void	insersion_sort_b(t_data *data)
{
	int i;
	int pivot;

	i = data->spliter;
	pivot = median(data, data->spliter, data->size);
	//printf(">>>pivot insersion_sort_b : %d<<<\n", pivot);
	while (i < data->size)
	{
		find_farthest_pos_b(data, pivot);
		calculate_best_move(data, pivot);
		execute_best_move_b(data, pivot);
		i++;
	}
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
			pbw(data);
		else
			raw(data);
		i++;
	}
	print_state(data);
	insersion_sort_b(data);
}

void	sort_two_top_a(t_data *data)
{
	if (data->list[data->spliter - 1] > data->list[data->spliter - 2])
		saw(data);
}

void	sort_only_three(t_data *data)
{
	if (data->list[data->spliter - 1] < data->list[data->spliter - 3] &&
	data->list[data->spliter - 3] < data->list[data->spliter - 2])
	{
		raw(data);
		saw(data);
		rraw(data);
	}
	else if (data->list[data->spliter - 2] < data->list[data->spliter - 1] &&
	data->list[data->spliter - 1] < data->list[data->spliter - 3])
		saw(data);
	else if (data->list[data->spliter - 3] < data->list[data->spliter - 1] &&
	data->list[data->spliter - 1] < data->list[data->spliter - 2])
		rraw(data);
	else if (data->list[data->spliter - 2] < data->list[data->spliter - 3] &&
	data->list[data->spliter - 3] < data->list[data->spliter - 1])
		raw(data);
	else if (data->list[data->spliter - 3] < data->list[data->spliter - 2] &&
	data->list[data->spliter - 2] < data->list[data->spliter - 1])
	{
		saw(data);
		rraw(data);
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
