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
		data->coloration = 33;
		printf_color("sa\n", data);
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
		data->coloration = 33;
		printf_color("sb\n", data);
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
		data->coloration = 33;
		printf_color("ss\n", data);
		print_state_fancy(data);
	}
}

void	pa(t_data *data)
{
	if (data->spliter < data->size)
		data->spliter++;
	if (data->fancy)
	{
		data->coloration = 31;
		printf_color("pa\n", data);
		print_state_fancy(data);
	}
}

void	pb(t_data *data)
{
	if (data->spliter > 0)
		data->spliter--;
	if (data->fancy)
	{
		data->coloration = 32;
		printf_color("pb\n", data);
		print_state_fancy(data);
	}
}
