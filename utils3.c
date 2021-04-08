/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:13:57 by bmerchin          #+#    #+#             */
/*   Updated: 2021/03/04 11:13:58 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_half_b(t_data *data, int pivot)
{
	int i;

	i = 0;
	while (i < data->size)
	{
		if (data->list[data->spliter - 1] < pivot)
			pbw(data);
		else
			raw(data);
		i++;
	}
}

void	push_half_a(t_data *data, int pivot)
{
	int i;

	i = data->spliter;
	while (i < data->size)
	{
		if (data->list[data->spliter] >= pivot)
			paw(data);
		else
			rbw(data);
		i++;
	}
}

void	initialize_main(t_data *data, int ac)
{
	data->rrr = 0;
	data->spliter = ac - 1;
	data->size = ac - 1;
	data->error = 0;
	data->print = 0;
	data->show_number = 0;
	data->fancy = 0;
	data->color = 0;
	data->ac = ac;
}
