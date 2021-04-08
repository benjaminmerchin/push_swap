/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_best_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:36:57 by bmerchin          #+#    #+#             */
/*   Updated: 2021/03/04 12:36:58 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	calculate_best_move3(t_data *data, int min)
{
	if (min == data->size - data->b_pos + 2 && !data->lock_b && !data->too_small)
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

void	calculate_best_move2(t_data *data, int min)
{
	if (min == data->size - data->a_pos + 1 && !data->lock_a && !data->too_small)
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
	else
		calculate_best_move3(data, min);
}

void	calculate_best_move1(t_data *data, int min)
{
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
	else
		calculate_best_move2(data, min);
}

void		calculate_best_move(t_data *data)
{
	int min;

	min = data->above_pos - data->spliter;
	if (data->bellow_pos - data->spliter < min)
		min = data->bellow_pos - data->spliter;
	if (data->size - data->above_pos < min)
		min = data->size - data->above_pos;
	if (data->size - data->bellow_pos < min)
		min = data->size - data->bellow_pos;
	if (data->a_pos - data->spliter + 1 < min
	&& !data->lock_a && !data->too_small)
		min = data->a_pos - data->spliter + 1;
	if (data->b_pos - data->spliter + 2 < min
	&& !data->lock_b && !data->too_small)
		min = data->b_pos - data->spliter + 2;
	if (data->size - data->a_pos + 1 < min && !data->lock_a && !data->too_small)
		min = data->size - data->a_pos + 1;
	if (data->size - data->b_pos + 2 < min && !data->lock_b && !data->too_small)
		min = data->size - data->b_pos + 2;
	calculate_best_move1(data, min);
}
