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

int		min_up(t_data *data, int a, int b)
{
	if (a <= b) //doner la priorite a la val above si on va de b vers a
	{
		data->relative_up = 1;
		return (a);
	}
	data->relative_up = -1;
	return (b);
}

int		min_down(t_data *data, int a, int b)
{
	if (a <= b) //doner la priorite a la val above si on va de b vers a
	{
		data->relative_down = 1;
		return (a);
	}
	data->relative_down = -1;
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

void	find_farthest_pos_b(t_data *data)
{
	int i;

	i = data->spliter;
	data->above_val = -2147483648;
	data->bellow_val = 2147483647;
	while (i < data->size)
	{
		if (data->list[i] >= data->above_val)
		{
			data->above_val = data->list[i];
			data->above_pos = i;
		}
		if (data->list[i] <= data->bellow_val)
		{
			data->bellow_val = data->list[i];
			data->bellow_pos = i;
		}
		i++;
	}
}

void	calculate_best_move(t_data *data)
{
	int up;
	int down;

	up = min_up(data, data->above_pos - data->spliter, data->bellow_pos - data->spliter);
	down = min_down(data, data->size - data->above_pos, data->size - data->bellow_pos);
	if (up <= down)
	{
		data->rotation = up;
		data->direction = 1;
		data->relative = data->relative_up;
	}
	else
	{
		data->rotation = down;
		data->direction = -1;
		data->relative = data->relative_down;
	}
}

void	execute_best_move_b(t_data *data) //combine up & down with the first operation
{
	int i;

	i = 0;
	if (!data->bool_first_move && data->last_relative < 0)
		raw(data);
	data->bool_first_move = 0;
	while(i < data->rotation)
	{
		if (data->direction > 0)
			rbw(data);
		else
			rrbw(data);
		i++;
	}
	data->last_relative = data->relative;
	paw(data);
}

void	insersion_sort_b(t_data *data)
{
	int i;
	int pivot;

	i = data->spliter;
	pivot = median(data, data->spliter, data->size);
	//printf(">>>pivot insersion_sort_b : %d<<<\n", pivot);
	data->bool_first_move = 1;
	while (i < data->size)
	{
		find_farthest_pos_b(data);
		calculate_best_move(data);
		execute_best_move_b(data);
		i++;
	}
}

void	push_remainer_a_to_b(t_data *data, int pivot)
{
	while (data->list[data->spliter - 1] < pivot)
		raw(data);
	while (data->list[data->spliter - 1] >= pivot)
		pbw(data);
}

void	rotate_remainer(t_data *data, int pivot)
{
	while (data->list[data->spliter - 1] >= pivot)
		raw(data);
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
	print_state(data);
	push_remainer_a_to_b(data, pivot);
	print_state(data);
	insersion_sort_b(data);
	print_state(data);
	//write(1, "@\n", 2);
	rotate_remainer(data, pivot);
	//printf(">>>pivot insersion_sort_b : %d<<<\n", pivot);
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

void	push_min_three_b_to_a(t_data *data)
{
	if (data->list[data->spliter] > data->list[data->spliter + 1] &&
	data->list[data->spliter] > data->list[data->spliter + 2])
		paw(data);
	else if (data->list[data->spliter + 1] > data->list[data->spliter] &&
	data->list[data->spliter + 1] > data->list[data->spliter + 2])
	{
		rbw(data);
		paw(data);
	}
	else if (data->list[data->spliter + 2] > data->list[data->spliter] &&
	data->list[data->spliter + 2] > data->list[data->spliter + 1])
	{
		rrbw(data);
		paw(data);
	}
}

void	push_min_thwo_b_to_a(t_data *data)
{
	if (data->list[data->spliter] > data->list[data->spliter + 1])
		paw(data);
	else
	{
		rbw(data);
		paw(data);
	}
}

void	sort_four_five(t_data *data)
{
	int i;
	int pivot;

	i = 0;
	pivot = median(data, 0, data->size);
	while (i < data->size)
	{
		if (data->list[data->spliter - 1] <= pivot)
			pbw(data);
		else
			raw(data);
		i++;
	}
	if (data->size == 5)
	{
		if (data->list[0] < data->list[1])
			raw(data);
	}
	push_min_three_b_to_a(data);
	push_min_thwo_b_to_a(data);
	paw(data);
}

void	sort(t_data *data)
{
	if (already_sorted(data))
		return ;
	if (data->size == 1)
		return ;
	else if (data->size == 2)
		sort_two_top_a(data);
	else if (data->size == 3)
		sort_only_three(data);
	else if (data->size < 6)
		sort_four_five(data);
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
	i = ac - 1;
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		i = ft_nbr_str(av[1], ' ');
		data.spliter = i;
		data.size = i;
	}
	if (!(data.list = malloc(sizeof(int) * data.size)))
		return (0); //message d'erreur
	while (i > 0)
	{
		if (ac == 2)
		{
			data.list[data.spliter - i] = ft_atoi(tab[i - 1], &data);
			security_duplicates(&data, data.spliter - i);
		}
		else
		{
			data.list[ac - i - 1] = ft_atoi(av[i], &data);
			security_duplicates(&data, ac - i - 1);
		}
		if (data.error == 1)
			return(ft_free_print_error(&data, ac, av, &tab));
		i--;
	}
	print_state(&data);
	sort(&data);
	print_state(&data);
	free(data.list);
	if (ac == 2)
		ft_free(tab, ft_nbr_str(av[1], ' '));
	return (0);
}
