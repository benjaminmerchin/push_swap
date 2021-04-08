/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:13:57 by bmerchin          #+#    #+#             */
/*   Updated: 2021/03/04 11:13:58 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 0);
	return (0);
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

void	raw_optimize(t_data *data, int *i)
{
	if (*i < data->rotation && data->direction > 0)
	{
		rrw(data);
		(*i)++;
	}
	else
		raw(data);
}

void	rraw_optimize(t_data *data, int *i)
{
	if (*i < data->rotation && data->direction < 0)
	{
		rrrw(data);
		(*i)++;
	}
	else
		rraw(data);
}
