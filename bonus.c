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

void	printf_color(char *s, t_data *data)
{
	(void)data;
	if (!s)
		return ;
	if (data->color && data->coloration == 31)
		printf("\033[0;31m");
	else if (data->color && data->coloration == 32)
		printf("\033[0;32m");
	else if (data->color && data->coloration == 34)
		printf("\033[0;34m");
	else if (data->color && data->coloration == 35)
		printf("\033[0;35m");
	else if (data->color && data->coloration == 36)
		printf("\033[0;36m");
	printf("%s", s);
	if (data->color)
		printf("\033[0m");
}

void	print_state_fancy(t_data *data)
{
	int		i;
	int		milli_seconds;
	clock_t start_time;

	i = 0;
	if (!data->fancy || data->size == 0)
		return ;
	printf("A: ");
	while (i < data->size)
	{
		printf("%d", data->list[i]);
		if (i == data->spliter - 1)
			printf("|");
		else
			printf(" ");
		i++;
	}
	printf(":B\n");
	while (i < 100000000)
		i++;
	start_time = clock();
	milli_seconds = 1000 * 1;
	while (clock() < start_time + milli_seconds)
		;
	system("clear");
}

void	manage_bonus2(t_data *data, int *ac, char ***av)
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

void	manage_bonus(t_data *data, int *ac, char ***av)
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
