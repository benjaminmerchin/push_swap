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

void	ra(t_data *data)
{
	int i;
	int temp;

	i = data->spliter - 1;
	if (data->spliter < 2)
		return ;
	temp = data->list[i];
	while (i > 0)
	{
		data->list[i] = data->list[i - 1];
		i--;
	}
	data->list[i] = temp;
}

void	rb(t_data *data)
{
	int i;
	int temp;

	i = data->spliter;
	if (data->size - data->spliter < 2)
		return ;
	temp = data->list[i];
	while (i < data->size - 1)
	{
		data->list[i] = data->list[i + 1];
		i++;
	}
	data->list[i] = temp;
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
