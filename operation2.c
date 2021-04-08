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
	if (data->aaa == 0 && data->fancy)
	{
		ft_putstr("ra\n");
		print_state_fancy(data);
	}
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
	if (data->aaa == 0 && data->fancy)
	{
		ft_putstr("rb\n");
		print_state_fancy(data);
	}
}

void	rr(t_data *data)
{
	data->aaa = 1;
	ra(data);
	rb(data);
	data->aaa = 0;
	if (data->fancy)
	{
		ft_putstr("rr\n");
		print_state_fancy(data);
	}
}
