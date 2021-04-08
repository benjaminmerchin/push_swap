/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_best_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:36:57 by bmerchin          #+#    #+#             */
/*   Updated: 2021/03/04 12:36:58 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	execute_best_move_b_2(t_data *data, int i)
{
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

void	execute_best_move_b(t_data *data, int min, int max)
{
	int i;

	i = 0;
	if (!data->bool_first_move)
	{
		if (data->list[data->spliter - 1] < data->val
		&& data->list[data->spliter - 1] >= min
		&& data->list[data->spliter - 1] < max)
			raw_optimize(data, &i);
		if (data->list[data->spliter - 1] < data->val
		&& data->list[data->spliter - 1] >= min
		&& data->list[data->spliter - 1] < max)
			raw_optimize(data, &i);
		if (data->list[data->spliter - 1] < data->val
		&& data->list[data->spliter - 1] >= min
		&& data->list[data->spliter - 1] < max)
			raw_optimize(data, &i);
		if (data->list[0] > data->val
		&& data->list[0] >= min && data->list[0] < max)
			rraw_optimize(data, &i);
		if (data->list[0] > data->val
		&& data->list[0] >= min && data->list[0] < max)
			rraw_optimize(data, &i);
	}
	execute_best_move_b_2(data, i);
}
