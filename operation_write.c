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

void	saw(t_data *data)
{
	int temp;

	if (data->spliter < 2)
		return ;
	temp = data->list[data->spliter - 1];
	data->list[data->spliter - 1] = data->list[data->spliter - 2];
	data->list[data->spliter - 2] = temp;
	if (data->rrr == 0)
		ft_putstr("sa\n");
}

void	sbw(t_data *data)
{
	int temp;

	if (data->spliter - data->size < 2)
		return ;
	temp = data->list[data->spliter];
	data->list[data->spliter] = data->list[data->spliter + 1];
	data->list[data->spliter + 1] = temp;
	if (data->rrr == 0)	
		ft_putstr("sb\n");
}

void	ssw(t_data *data)
{
	data->rrr = 1;
	saw(data);
	sbw(data);
	data->rrr = 0;
	ft_putstr("ss\n");
}

void	paw(t_data *data)
{
	if (data->spliter < data->size)
		data->spliter++;
	ft_putstr("pa\n");
}

void	pbw(t_data *data)
{
	if (data->spliter > 0)
		data->spliter--;
	ft_putstr("pb\n");
}

void	raw(t_data *data)
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
	if (data->rrr == 0)
		ft_putstr("ra\n");
}

void	rbw(t_data *data)
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
	if (data->rrr == 0)
		ft_putstr("rb\n");
}

void	rrw(t_data *data)
{
	data->rrr = 1;
	raw(data);
	rbw(data);
	data->rrr = 0;
	ft_putstr("rr\n");
}

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
