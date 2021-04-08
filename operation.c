/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:36:57 by bmerchin          #+#    #+#             */
/*   Updated: 2021/03/04 12:36:58 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(t_data *data)
{
	int temp;

	if (data->spliter < 2)
		return ;
	temp = data->list[data->spliter - 1];
	data->list[data->spliter - 1] = data->list[data->spliter - 2];
	data->list[data->spliter - 2] = temp;
}

void	sb(t_data *data)
{
	int temp;

	if (data->spliter - data->size < 2)
		return ;
	temp = data->list[data->spliter];
	data->list[data->spliter] = data->list[data->spliter + 1];
	data->list[data->spliter + 1] = temp;
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}

void	pa(t_data *data)
{
	if (data->spliter < data->size)
		data->spliter++;
}

void	pb(t_data *data)
{
	if (data->spliter > 0)
		data->spliter--;
}
