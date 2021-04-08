/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:36:57 by bmerchin          #+#    #+#             */
/*   Updated: 2021/03/04 12:36:58 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <time.h>

void	print_state_fancy(t_data *data)
{
	int i;
	int milli_seconds;

	i = 0;
	if (!data->fancy || data->size == 0)
		return ;
	ft_putstr("A: ");
	while (i < data->size)
	{
		ft_putnbr(data->list[i]);
		if (i == data->spliter - 1)
			ft_putchar('|');
		else
			ft_putchar(' ');
		i++;
	}
	ft_putstr(":B");
	while (i < 100000000)
		i++;
	clock_t start_time = clock();
	milli_seconds = 1000 * 1;
	while (clock() < start_time + milli_seconds)
		;
	system("clear");
	ft_putchar('\n');
}

void		manage_bonus2(t_data *data, int *ac, char ***av)
{
	if (*ac < 2)
		return ;
	if ((*av)[1][0] == '-' && (*av)[1][1] == 'f' && (*av)[1][2] == '\0')
	{
		(*ac)--;
		(*av)++;
		data->spliter--;
		data->size--;
		data->ac--;
		data->fancy = 1;
		system("clear");
		manage_bonus(data, ac, av);
	}
	if (*ac < 2)
		return ;
	if ((*av)[1][0] == '-' && (*av)[1][1] == 'c' && (*av)[1][2] == '\0')
	{
		(*ac)--;
		(*av)++;
		data->spliter--;
		data->size--;
		data->ac--;
		data->color = 1;
		manage_bonus(data, ac, av);
	}
}

void		manage_bonus(t_data *data, int *ac, char ***av)
{
	if (*ac < 2)
		return ;
	if ((*av)[1][0] == '-' && (*av)[1][1] == 'n' && (*av)[1][2] == '\0')
	{
		(*ac)--;
		(*av)++;
		data->spliter--;
		data->size--;
		data->ac--;
		data->show_number = 1;
		manage_bonus(data, ac, av);
	}
	if (*ac < 2)
		return ;
	if ((*av)[1][0] == '-' && (*av)[1][1] == 'p' && (*av)[1][2] == '\0')
	{
		(*ac)--;
		(*av)++;
		data->spliter--;
		data->size--;
		data->ac--;
		data->print = 1;
		manage_bonus(data, ac, av);
	}
	manage_bonus2(data, ac, av);
}
