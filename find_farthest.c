/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_farthest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:36:57 by bmerchin          #+#    #+#             */
/*   Updated: 2021/03/04 12:36:58 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	find_farthest_pos_b_2(t_data *data, int i)
{
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

void	initialize_val(t_data *data)
{
	data->above_val = -2147483648;
	data->a_val = -2147483648;
	data->bellow_val = 2147483647;
	data->b_val = 2147483647;
}

void	find_farthest_pos_b(t_data *data)
{
	int i;

	i = data->spliter;
	initialize_val(data);
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
	find_farthest_pos_b_2(data, i);
}
