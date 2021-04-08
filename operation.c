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
	if (data->aaa == 0 && data->fancy)
	{
		ft_putstr("sa\n");
		print_state_fancy(data);
	}
}

void	sb(t_data *data)
{
	int temp;

	if (data->spliter - data->size < 2)
		return ;
	temp = data->list[data->spliter];
	data->list[data->spliter] = data->list[data->spliter + 1];
	data->list[data->spliter + 1] = temp;
	if (data->aaa == 0 && data->fancy)
	{
		ft_putstr("sb\n");
		print_state_fancy(data);
	}
}

void	ss(t_data *data)
{
	data->aaa = 1;
	sa(data);
	sb(data);
	data->aaa = 0;
	if (data->fancy)
	{
		ft_putstr("ss\n");
		print_state_fancy(data);
	}
}

void	pa(t_data *data)
{
	if (data->spliter < data->size)
		data->spliter++;
	if (data->fancy)
	{
		ft_putstr("pa\n");
		print_state_fancy(data);
	}
}

void	pb(t_data *data)
{
	if (data->spliter > 0)
		data->spliter--;
	if (data->fancy)
	{
		ft_putstr("pb\n");
		print_state_fancy(data);
	}
}
