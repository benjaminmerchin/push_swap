/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_on_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:36:57 by bmerchin          #+#    #+#             */
/*   Updated: 2021/03/04 12:36:58 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
