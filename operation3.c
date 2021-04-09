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

void	rra(t_data *data)
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
	if (data->aaa == 0 && data->fancy)
	{
		data->coloration = 35;
		printf_color("rra\n", data);
		print_state_fancy(data);
	}
}

void	rrb(t_data *data)
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
	if (data->aaa == 0 && data->fancy)
	{
		data->coloration = 35;
		printf_color("rrb\n", data);
		print_state_fancy(data);
	}
}

void	rrr(t_data *data)
{
	data->aaa = 1;
	rra(data);
	rrb(data);
	data->aaa = 0;
	if (data->fancy)
	{
		data->coloration = 35;
		printf_color("rrr\n", data);
		print_state_fancy(data);
	}
}
