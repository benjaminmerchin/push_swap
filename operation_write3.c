/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:36:57 by bmerchin          #+#    #+#             */
/*   Updated: 2021/03/04 12:36:58 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rraw(t_data *data)
{
	int i;
	int temp;
	
	i = 0;
	if (data->spliter < 2)
		return ;
	temp = data->list[0];
	while (i < data->spliter - 1)
	{
		data->list[i] = data->list[i + 1];
		i++;
	}
	data->list[i] = temp;
	if (data->rrr == 0)
		ft_putstr("rra\n");
}

void	rrbw(t_data *data)
{
	int i;
	int temp;
	
	i = data->size - 1;
	if (data->size - data->spliter < 2)
		return ;
	temp = data->list[i];
	while (i > data->spliter)
	{
		data->list[i] = data->list[i - 1];
		i--;
	}
	data->list[i] = temp;
	if (data->rrr == 0)
		ft_putstr("rrb\n");
}

void	rrrw(t_data *data)
{
	data->rrr = 1;
	rraw(data);
	rrbw(data);
	data->rrr = 0;
	ft_putstr("rrr\n");
}
