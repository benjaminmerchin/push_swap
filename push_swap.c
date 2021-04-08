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

void	find_farthest_pos_b(t_data *data)
{
	int i;

	i = data->spliter;
	data->above_val = -2147483648;
	data->a_val = -2147483648;
	data->bellow_val = 2147483647;
	data->b_val = 2147483647;
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
	if (data->size - data->spliter < 5)
	{
		data->too_small = 1;
		return ;
	}
	i = data->spliter;
	while (i < data->size)
	{
		if (data->list[i] == data->above_val || data->list[i] == data->bellow_val)
			;
		else
		{
			if (data->list[i] >= data->a_val)
			{
				data->a_val = data->list[i];
				data->a_pos = i;
			}
			if (data->list[i] <= data->b_val)
			{
				data->b_val = data->list[i];
				data->b_pos = i;
			}
		}
		i++;
	}
}

void	calculate_best_move(t_data *data)
{
	int min;

	min = data->above_pos - data->spliter;
	if (data->bellow_pos - data->spliter < min)
		min = data->bellow_pos - data->spliter;
	if (data->size - data->above_pos < min)
		min = data->size - data->above_pos;
	if (data->size - data->bellow_pos < min)
		min = data->size - data->bellow_pos;
	if (data->a_pos - data->spliter + 1 < min && !data->lock_a && !data->too_small)
		min = data->a_pos - data->spliter + 1;
	if (data->b_pos - data->spliter + 2 < min && !data->lock_b && !data->too_small)
		min = data->b_pos - data->spliter + 2;
	if (data->size - data->a_pos + 1 < min && !data->lock_a && !data->too_small)
		min = data->size - data->a_pos + 1;
	if (data->size - data->b_pos + 2 < min && !data->lock_b && !data->too_small)
		min = data->size - data->b_pos + 2;

	if (min == data->above_pos - data->spliter)
	{
		data->rotation = min;
		data->direction = 1;
		data->relative = 4;
		data->val = data->above_val;
	}
	else if (min == data->size - data->above_pos)
	{
		data->rotation = min;
		data->direction = -1;
		data->relative = 4;
		data->val = data->above_val;
	}
	else if (min == data->a_pos - data->spliter + 1 && !data->lock_a && !data->too_small)
	{
		data->rotation = data->a_pos - data->spliter;
		data->direction = 1;
		data->relative = 3;
		data->val = data->a_val;
	}
	else if (min == data->size - data->a_pos + 1 && !data->lock_a && !data->too_small)
	{
		data->rotation = data->size - data->a_pos;
		data->direction = -1;
		data->relative = 3;
		data->val = data->a_val;
	}
	else if (min == data->bellow_pos - data->spliter)
	{
		data->rotation = min;
		data->direction = 1;
		data->relative = 1;
		data->val = data->bellow_val;
	}
	else if (min == data->size - data->bellow_pos)
	{
		data->rotation = min;
		data->direction = -1;
		data->relative = 1;
		data->val = data->bellow_val;
	}
	else if (min == data->size - data->b_pos + 2 && !data->lock_b && !data->too_small)
	{
		data->rotation = data->size - data->b_pos;
		data->direction = -1;
		data->relative = 2;
		data->val = data->b_val;
	}
	else if (min == data->b_pos - data->spliter + 2 && !data->lock_b && !data->too_small)
	{
		data->rotation = data->b_pos - data->spliter;
		data->direction = 1;
		data->relative = 2;
		data->val = data->b_val;
	}
}

void	execute_best_move_b(t_data *data, int min, int max)
{
	int i;

	i = 0;
	if (!data->bool_first_move)
	{
		if (data->list[data->spliter - 1] < data->val && data->list[data->spliter - 1] >= min && data->list[data->spliter - 1] < max)
			raw_optimize(data, &i);
		if (data->list[data->spliter - 1] < data->val && data->list[data->spliter - 1] >= min && data->list[data->spliter - 1] < max)
			raw_optimize(data, &i);
		if (data->list[data->spliter - 1] < data->val && data->list[data->spliter - 1] >= min && data->list[data->spliter - 1] < max)
			raw_optimize(data, &i);
		if (data->list[0] > data->val && data->list[0] >= min && data->list[0] < max)
			rraw_optimize(data, &i);
		if (data->list[0] > data->val && data->list[0] >= min && data->list[0] < max)
			rraw_optimize(data, &i);
	}
	print_state(data);
	if (data->relative == 1)
		data->lock_b = 0;
	else if (data->relative == 2)
		data->lock_b = 1;
	else if (data->relative == 3)
		data->lock_a = 1;
	else if (data->relative == 4)
		data->lock_a = 0;
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

void	insersion_sort_b(t_data *data, int min, int max)
{
	int i;

	i = data->spliter;
	data->bool_first_move = 1;
	data->lock_a = 0;
	data->lock_b = 0;
	data->too_small = 0;
	while (i < data->size)
	{
		find_farthest_pos_b(data);
		calculate_best_move(data);
		execute_best_move_b(data, min, max);
		i++;
	}
}

void	manage_half_on_b_sub_sublevel(t_data *data, int min, int max)
{
	int pivot;
	int pivot_min;
	int pivot_max;

	(void)min;
	pivot = median(data, data->spliter, data->size);
	pivot_min = data->pivot_min;
	pivot_max = data->pivot_max;
	push_half_a(data, pivot);
	print_state(data);
	insersion_sort_b(data, pivot_min, pivot);
	print_state(data);
	while (data->list[data->spliter - 1] < pivot)
		raw(data);
	print_state(data);
	while (data->list[data->spliter - 1] >= pivot
	&& data->list[data->spliter - 1] <= max)
		pbw(data);
	insersion_sort_b(data, pivot, pivot_max);
}

void	manage_half_on_b_sublevel(t_data *data, int min, int max)
{
	int pivot;
	int pivot_min;
	int pivot_max;

	(void)min;
	pivot = median(data, data->spliter, data->size);
	pivot_min = data->pivot_min;
	pivot_max = data->pivot_max;
	push_half_a(data, pivot);
	print_state(data);
	manage_half_on_b_sub_sublevel(data, pivot_min, pivot);
	print_state(data);
	while (data->list[data->spliter - 1] < pivot)
		raw(data);
	print_state(data);
	while (data->list[data->spliter - 1] >= pivot
	&& data->list[data->spliter - 1] <= max)
		pbw(data);
	manage_half_on_b_sub_sublevel(data, pivot, pivot_max);
}

void	manage_half_on_b(t_data *data, int min, int max)
{
	int pivot;
	int pivot_min;
	int pivot_max;
	(void)min;

	pivot = median(data, data->spliter, data->size);
	pivot_min = data->pivot_min;
	pivot_max = data->pivot_max;
	push_half_a(data, pivot);
	print_state(data);
	manage_half_on_b_sublevel(data, pivot_min, pivot);
	print_state(data);
	while (data->list[data->spliter - 1] < pivot)
		raw(data);
	print_state(data);
	while (data->list[data->spliter - 1] >= pivot
	&& data->list[data->spliter - 1] <= max)
		pbw(data);
	manage_half_on_b_sublevel(data, pivot, pivot_max);
}

void	quick_sort_ultimate(t_data *data)
{
	int pivot;
	int pivot_min;
	int pivot_max;

	pivot = median(data, 0, data->size);
	pivot_min = data->pivot_min;
	pivot_max = data->pivot_max;
	push_half_b(data, pivot);
	print_state(data);
	manage_half_on_b(data, pivot_min, pivot - 1);
	print_state(data);
	while (data->list[data->spliter - 1] < pivot)
		raw(data);
	while (data->list[data->spliter - 1] >= pivot)
		pbw(data);
	print_state(data);
	manage_half_on_b(data, pivot, pivot_max);
	print_state(data);
	rotate_remainer(data, pivot);
}

void	quick_sort(t_data *data)
{
	int pivot;

	pivot = median(data, 0, data->size);
	push_half_b(data, pivot);
	print_state(data);
	insersion_sort_b(data, data->pivot_min, pivot);
	print_state(data);
	push_remainer_a_to_b(data, pivot);
	print_state(data);
	insersion_sort_b(data, pivot, data->pivot_max);
	print_state(data);
	rotate_remainer(data, pivot);
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
	else if (data->size < 300)
		quick_sort(data);
	else
		quick_sort_ultimate(data);
}

int main_extension(int ac, char **av, char ***tab, t_data *data)
{
	(void)ac;
	(void)av;
	print_state(data);
	sort(data);
	print_state(data);
	free(data->list);
	if (ac == 2)
		ft_free(*tab, ft_nbr_str(av[1], ' '));
	return (0);
}

int main(int ac, char **av)
{
	int i;
	t_data data;
	char **tab;
	
	i = 0;
	data.error = 0;
	data.rrr = 0;
	if (ac == 1)
		return (0);
	data.spliter = ac - 1;
	data.size = ac - 1;
	i = ac - 1;
	if (ac > 10000)
		return (ft_error());
	if (ac == 2)
	{
		i = ft_nbr_str(av[1], ' ');
		if (i > 10000)
			return (ft_error());
		tab = ft_split(av[1], ' ');
		data.spliter = i;
		data.size = i;
	}
	if (!(data.list = malloc(sizeof(int) * data.size)))
		return (free_tab_print_error(ac, av, &tab));
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
	return (main_extension(ac, av, &tab, &data));
}
